#include "General-Header.h"
#include "List-Parent-Movie.h"
#include "List-Relation.h"
#include "List-Parent-Reviewer.h"

int main()
{
    /*admin TheAdmin[adminMember];
    loadDataAdmin(TheAdmin);
    loginForAdmin(TheAdmin);
    adminMenu(); */

    List_Movie A; // List Parent 1
    loadDataMovies(A); // Sudah terkandung CreateList & InsertLast
    viewListMovie(A);
    deleteElmMovie(A,"Gundala"); //DeleteFirst
    deleteElmMovie(A,"Ratu Ilmu Hitam"); //DeleteLast
    deleteElmMovie(A,"Joker"); //DeleteAfter
    viewListMovie(A);


    List_User B; // List Parent 2
    loadDataUsers(B); // Sudah terkandung CreateList, InsertFirst, InsertLast, dan InsertAfter
    viewListUser(B);
    deleteElmUser(B,"AmandaZahra"); //DeleteFirst;
    deleteElmUser(B,"ZicoArief"); //DeleteLast
    deleteElmUser(B,"DesyAnwar"); //DeleteAfter
    viewListUser(B);

    List_Relation C; // List Relasi
    loadDataRelation(C,A,B); // sudah terkandung createList dan insertFirst sesuai dengan spesifikasi soal
    viewListRelation(C);


    //user TheUser[userMember];
    //loginForUser(TheUser);
    //userMenu();


    return 0;
}
