#include "General-Header.h"
#include "List-Relation.h"
#include "List-Parent-Movie.h"
#include "List-Parent-Reviewer.h"

void createListRelation(List_Relation &L) {
    First(L) = NULL;
}
bool isEmptyListRelation(List_Relation &L) {
    return First(L) == NULL;
}
address_Relation createElmRelation(List_Movie ListMovie, List_User ListUser,string titleMovie, string review, string date, string username) {
    address_Movie Mov = searchElmMovie(ListMovie, titleMovie);
    address_User User = searchElmUser(ListUser, username);
    address_Relation P = new elmList_Relation;

    if (Mov != NULL && User != NULL) {
        //Info(P).title = titleMovie;
        Info(P).comment = review;
        Info(P).date = date;
        Movie(P) = Mov;
        Info(Mov).Status = "Reviewed";
        User(P) = User;
        Next(P) = NULL;
        return P;
    } else {
        return NULL;
    }
}
void insertFirstRelation(List_Relation &L, address_Relation P) {
    //cout << "HAI" << endl;
    if (isEmptyListRelation(L)) {
        First(L) = P;
        Next(P) = P;
        Prev(P) = P;

    } else {
        Next(P) = First(L);
        Prev(P) = Prev(First(L));
        Next(Prev(First(L))) = P;
        Prev(First(L)) = P;
        First(L) = P;
    }
}
void insertElmRelation(List_Relation &L, List_Movie ListMovie, List_User ListUser, string titleMovie, string username, string review) {
    string dateTime = getDateAndTime();

    if (!duplicateUsernameAtRelation(L,username, titleMovie)) {
        address_Relation P = createElmRelation(ListMovie,ListUser,titleMovie, review, dateTime, username);
        if (P != NULL) {
            insertFirstRelation(L,P);
        } else {
            cout << "Insert Review Failed\n";
        }
    }
}

void deleteFirstRelation(List_Relation &L, address_Relation &P){
    if(!isEmptyListRelation(L)){
        if (First(L) == Next(First(L))) {
            P = First(L);
            First(L) = NULL;
        } else {
            P = First(L);
            First(L) = Next(P);
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
            Next(P) = NULL;
            Prev(P) = NULL;
        }
    }
}

void deleteLastRelation(List_Relation &L, address_Relation &P){
    if(!isEmptyListRelation(L)){
        P = Prev(First(L));
        Prev(First(L)) = Prev(P);
        Next(Prev(P)) = First(L);
        Next(P) = NULL;
        Prev(P) = NULL;
    }
}

void deleteAfterRelation(address_Relation Prec, address_Relation &P){
    P = Next(Prec);
    Next(Prec) = Next(P);
    Prev(Next(P)) = Prec;
    Next(P) = NULL;
    Prev(P) = NULL;
}

address_Relation searchElmRelation(List_Relation L, string title, string username) {
    address_Relation A  = First(L);
    bool Found = false;
    do {
        //address_Movie movie = Movie(A);
        if (Info(Movie(A)).Judul == title && Info(User(A)).username == username) {
            Found = true;
        } else {
            A = Next(A);
        }
    } while (A != First(L) && !Found);
    if (Found) {
        return A;
    } else {
        return NULL;
    }
}
void deleteElmRelation(List_Relation &L, string title, string username) {
    if(!isEmptyListRelation(L)) {
        address_Relation P = searchElmRelation(L, title, username);
        if (P != NULL) {
            if (P == First(L)) {
                deleteFirstRelation(L,P);
            } else if (P == Prev(First(L))) {
                deleteLastRelation(L,P);
            } else {
                address_Relation Prec = Prev(P);
                deleteAfterRelation(Prec, P);
            }
        } else {
            cout << "The film is not found" << endl;
        }
    }
}
void viewListRelation(List_Relation L) {
    address_Relation A = First(L);
    cout << "==>List Relasi<===" << endl;
    if (A != NULL) {
        do {
            address_Movie B = Movie(A);
            address_User C = User(A);
            cout << "Title    : " << Info(B).Judul << endl;
            cout << "Year     : " << Info(B).Tahun << endl;
            cout << "User     : " << Info(C).username << endl;
            cout << "Age      : " << Info(C).umur << endl;
            cout << "Review   : " << Info(A).comment << endl;
            cout << "Time     : " << Info(A).date << endl;
            cout << endl;
            A = Next(A);
        } while (A != First(L));
    }
}

void viewMyListRelation(List_Relation L, string username, bool &check){
    address_Relation A = First(L);
    check=false;
    int i=0;
    if (A != NULL) {
        do {
            address_Movie B = Movie(A);
            address_User C = User(A);
            if(Info(User(A)).username == username){
                i++;
                cout << i << ")  Title    : " << Info(B).Judul << endl;
                cout << "    Year     : " << Info(B).Tahun << endl;
                cout << "    User     : " << Info(C).username << endl;
                cout << "    Age      : " << Info(C).umur << endl;
                cout << "    Review   : " << Info(A).comment << endl;
                cout << "    Time     : " << Info(A).date << endl;
                cout << endl;
                check = true;
            }
            A = Next(A);
        } while (A != First(L));
        if(!check){
            cout<<"Your review list is Empty.\n\n";
        }
    }
}

bool duplicateUsernameAtRelation (List_Relation L, string username, string title ) {
    if (!isEmptyListRelation(L)) {
        address_Relation A = First(L);
        bool duplicate = false;
        do {
            address_User user = User(A);
            address_Movie movie = Movie(A);
            if (Info(user).username == username && Info(movie).Judul == title) {
                duplicate = true;
            } else {
                A = Next(A);
            }
        } while(A != First(L));
        return duplicate;
    } else {
        return false;
    }

}
void loadDataRelation(List_Relation &L, List_Movie ListMovie, List_User ListUser) {
    createListRelation(L);
    insertElmRelation(L,ListMovie,ListUser, "Hit & Run", "Reynaldo32", "Cukup bagus tapi grafiknya kurang");
    insertElmRelation(L,ListMovie,ListUser, "Hit & Run", "Reynaldo32", "Saya tidak suka"); // coba jika dipaksakan review film yang sama lebih dari 1 kali
    insertElmRelation(L,ListMovie,ListUser, "Ayat-Ayat Cinta 2", "Reynaldo32", "Saya suka alur cerita yang luar biasa"); //user yang sama input review film yang berbeda
    insertElmRelation(L,ListMovie,ListUser, "Ayat-Ayat Cinta 2", "BreadSalad", "Romantis banget pengen nikah deh:("); //user yang berbeda input film yang sama
    insertElmRelation(L,ListMovie,ListUser, "Hit & Run", "Telyu", "Ya lumayan");
    insertElmRelation(L,ListMovie,ListUser, "Ayat-Ayat Cinta 2", "Telyu", "Asik si");
    insertElmRelation(L,ListMovie,ListUser, "Gundala", "BreadSalad", "CGI nya kurang nendang:(");
    insertElmRelation(L,ListMovie,ListUser, "Joker", "BreadSalad", "Orang jahat lahir dari orang baik yang tersakiti");
}

int countReviewedSingleMovie (List_Relation L, string title) {
    address_Relation A = First(L);
    int i = 0;
    do {
        if (title == Info(Movie(A)).Judul) {
            i++;
        }
        A = Next(A);
    } while(A != First(L));
    return i;
}
address_Relation searchTheMostReviewedMovie(List_Relation L) {
    address_Relation A = Next(First(L));
    address_Relation TheMost = First(L);

    do {
        A = Next(A);
        if (countReviewedSingleMovie(L, Info(Movie(TheMost)).Judul) < countReviewedSingleMovie(L, Info(Movie(A)).Judul)) {
            TheMost = A;
        }
    } while (A != First(L));
    return TheMost;
}

int countReviewOfUser(List_Relation L, string username) {
    address_Relation A = First(L);
    int i = 0;
    do {
        if (Info(User(A)).username == username) {
            i++;
        }
        A = Next(A);
    } while (A != First(L));
    return i;
}
address_Relation searchTheMostActiveUser(List_Relation L)  {
    address_Relation A = Next(First(L));
    address_Relation theMost = First(L);
    do {
        if(countReviewOfUser(L, Info(User(A)).username) > countReviewOfUser(L, Info(User(theMost)).username)) {
            theMost = A;
        }
        A = Next(A);
    } while (A != First(L));
    return theMost;
}
void viewDetailUsers(List_Relation L, List_User M) {
    address_User X = First(M);
    int i=0;
    int j=0;
    while (X != NULL) {
        j++;
        cout << j << ")";
        cout << " Username              : " << Info(X).username << endl;
        cout << "   Password              : " << Info(X).password << endl;
        cout << "   Age                   : " << Info(X).umur << endl;
        cout << "   Movies being reviewed : " << endl;
        address_Relation A = First(L);
        if (A != NULL) {
            do {
                address_Movie B = Movie(A);
                address_User C = User(A);
                if (Info(X).username == Info(C).username) {
                    i++;
                    cout << "   " <<i << ")";
                    cout << "  Title    : " << Info(B).Judul << endl;
                    cout << "       Year     : " << Info(B).Tahun << endl;
                    cout << "       Review   : " << Info(A).comment << endl;
                    cout << "       Time     : " << Info(A).date << endl;
                    cout << endl;
                }
                A = Next(A);
            } while (A != First(L));
        }
        i = 0;
        X = Next(X);
    }
}

