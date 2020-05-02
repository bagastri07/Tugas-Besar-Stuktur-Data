#include "General-Header.h"
#include "List-Parent-Movie.h"

void createListMovie(List_Movie &L) {
    First(L) = NULL;
    Last(L) = NULL;
}
bool isEmptyListMovie(List_Movie &L) {
    return First(L) == NULL && Last(L) == NULL;
}
address_Movie createElmMovie(string judul, string tahun) {
    address_Movie P;
    P = new elmList_Movie;
    Info(P).Judul = judul;
    Info(P).Tahun = tahun;
    Info(P).Status = "Unreviewed";
    Next(P) = NULL;
    return P;
}
void viewListMovie(List_Movie L) {
    address_Movie A;
    A = First(L);
    cout<<"===>Movie List<===="<<endl;
    while (A != NULL) {
        //Sementara tidak menggunakan ID
        //cout<<"ID : "<<Info(A).ID<<endl;
        cout<<"Title    : "<<Info(A).Judul<<endl;
        cout<<"Year     : "<<Info(A).Tahun<<endl;
        cout<<endl;
        A = Next(A);
    }
    cout << "\nEnter any Key to continue.\n";
    getch();
}
void insertLastMovie(List_Movie &L, address_Movie P){
    if (isEmptyListMovie(L)) {
        First(L) = P;
        Last(L) = P;
    } else {
        Next(Last(L)) = P;
        Last(L) = P;
    }
}
void deleteFirstMovie(List_Movie &L, address_Movie &P){
    if (isEmptyListMovie(L)) {
        P = First(L);
        First(L) = NULL;
        Last(L) = NULL;
    } else {
        P = First(L);
        First(L) = Next(P);
        Next(P) = NULL;
    }
}
void deleteLastMovie(List_Movie &L, address_Movie &P) {
    if (Next(First(L)) == NULL) {
        deleteFirstMovie(L,P);
    } else {
        P = Last(L);
        address_Movie A = First(L);
        while (Next(Next(A)) != NULL) {
            A = Next(A);
        }
        Last(L) = A;
        Next(A) = NULL;
    }
}
void deleteAfterMovie(address_Movie Prec, address_Movie &P) {
    P = Next(Prec);
    Next(Prec) = Next(P);
    Next(P) = NULL;
}
address_Movie searchElmMovie(List_Movie L, string judul) {
    address_Movie A = First(L);
    bool Found = false;
    while (A != NULL && !Found) {
        if (Info(A).Judul == judul) {
            Found = true;
        } else {
            A = Next(A);
        }
    }
    if (Found) {
        return A;
    } else {
        return NULL;
    }
}
void deleteElmMovie(List_Movie &L, string judul) {
    if (!isEmptyListMovie(L)) {
        address_Movie P = searchElmMovie(L,judul);
        if (P != NULL) {
            if (P == First(L)) {
                deleteFirstMovie(L,P);
            } else if (P == Last(L)) {
                deleteLastMovie(L,P);
            } else {
                address_Movie A = First(L);
                while (Next(A) != P) {
                A = Next(A);
                }
                deleteAfterMovie(A,P);
            }
            cout << "'" << judul << "' was deleted." << endl;
        } else {
        cout << "Movie Title not found." << endl;
        }
    } else {
        cout << "The movie list is empty." << endl;
    }
    cout << "\nEnter any Key to continue.\n";
    getch();
}
void loadDataMovies(List_Movie &L) {
    createListMovie(L);
    address_Movie A;
    A = createElmMovie("Gundala","2019");
    insertLastMovie(L,A);
    A = createElmMovie("Ayat-Ayat Cinta 2","2018");
    insertLastMovie(L,A);
    A = createElmMovie("Hit & Run","2019");
    insertLastMovie(L,A);
    A = createElmMovie("Spider Man : Far From Home","2019");
    insertLastMovie(L,A);
    A = createElmMovie("Joker","2019");
    insertLastMovie(L,A);
    A = createElmMovie("Ratu Ilmu Hitam","2019");
    insertLastMovie(L,A);
}
int countMovie(List_Movie L) {
    address_Movie A = First(L);
    int i = 0;
    while (A != NULL) {
        i++;
        A = Next(A);
    }
    return i;
}
int countMovieReviewed(List_Movie L) {
    address_Movie A = First(L);
    int i = 0;
    while (A != NULL) {
        if (Info(A).Status == "Reviewed") {
            i++;
        }
        A = Next(A);

    }
    return i;
}



