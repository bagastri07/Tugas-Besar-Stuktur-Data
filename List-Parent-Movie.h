#ifndef LIST-PARENT-MOVIE_H_INCLUDED
#define LIST-PARENT-MOVIE_H_INCLUDED

#include "General-Header.h"

struct movie {
    int ID;
    string Judul, Tahun, Status;
};

typedef movie infotype;
typedef struct elmList_Movie *address_Movie;

struct elmList_Movie {;
    infotype Info;
    address_Movie Next;
};

struct List_Movie {
    address_Movie First;
    address_Movie Last;
};

void createList(List_Movie &L);
void viewList(List_Movie L);
void insertLast(List_Movie &L, address_Movie P);
void deleteFirst(List_Movie &L, address_Movie &P);
void deleteLast(List_Movie &L, address_Movie &P);
void deleteAfter(address_Movie Prec, address_Movie &P);
address_Movie searchElm(List_Movie L, string judul);
void deleteElm(List_Movie &L, string judul);

#endif // LIST-PARENT-MOVIE_H_INCLUDED
