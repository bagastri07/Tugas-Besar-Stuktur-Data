#ifndef LIST-PARENT-MOVIE_H_INCLUDED
#define LIST-PARENT-MOVIE_H_INCLUDED

#include "General-Header.h"

void createListMovie(List_Movie &L);
bool isEmptyListMovie(List_Movie &L);
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
