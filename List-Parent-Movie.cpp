#include "General-Header.h"
#include "List-Parent-Movie.h"

void createList(List_Movie &L) {
    First(L) = NULL;
}
void viewList(List_Movie L) {
    address_Movie A;
    A = First(L);
    while (A != NULL) {
        cout<<Info(A).ID<<endl;
    }
}
void insertLast(List_Movie &L, address_Movie P);
void deleteFirst(List_Movie &L, address_Movie &P);
void deleteLast(List_Movie &L, address_Movie &P);
void deleteAfter(address_Movie Prec, address_Movie &P);
address_Movie searchElm(List_Movie L, string judul);
void deleteElm(List_Movie &L, string judul);
