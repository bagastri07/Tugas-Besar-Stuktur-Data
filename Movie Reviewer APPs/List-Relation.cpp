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
        P = First(L);
        First(L) = Next(P);
        Next(P) = NULL;
    }
}

void deleteLastRelation(List_Relation &L, address_Relation &P){
    if(!isEmptyListRelation(L)){
        adress_Relation Q = First(L);
        while(Next(Next(Q)) != NULL){
            Q = Next(Q);
        }
        Next(Q) = P;
        Next(P) = NULL;
    }
}

void deleteAfterRelation(address_Relation Prec, address_Relation &P){
    P = Next(Prec);
    Next(Prec) = Next(P);
    Next(P) = NULL;
}

address_Relation searchElmRelation(List_Relation L, string title) {
    address_Relation A  = First(L);
    bool Found = false;
    do {
        address_Movie movie = Movie(A);
        if (title == Info(movie).Judul) {
            Found = true;
        } else {
            A = Next(A);
        }
    } while (A != First(L) && !Found);
    return A;
}
void deleteElmRelation(List_Relation L, string title);
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
}
