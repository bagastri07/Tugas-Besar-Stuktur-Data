#ifndef LIST-PARENT-MOVIE_H_INCLUDED
#define LIST-PARENT-MOVIE_H_INCLUDED

#include "General-Header.h"

struct movie {
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

void createListMovie(List_Movie &L);
address_Movie createElmMovie(string judul, string tahun);
void viewListMovie(List_Movie L);
void insertLastMovie(List_Movie &L, address_Movie P);
void deleteFirstMovie(List_Movie &L, address_Movie &P);
void deleteLastMovie(List_Movie &L, address_Movie &P);
void deleteAfterMovie(address_Movie Prec, address_Movie &P);
address_Movie searchElmMovie(List_Movie L, string judul);
void deleteElmMovie(List_Movie &L, string judul);
void loadDataMovies(List_Movie &L);

#endif // LIST-PARENT-MOVIE_H_INCLUDED
