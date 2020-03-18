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

    List_Movie A;
    loadDataMovies(A); // Sudah terkandung CreateList & InsertLast
    viewListMovie(A);
    deleteElmMovie(A,"Gundala"); //DeleteFirst
    deleteElmMovie(A,"Ratu Ilmu Hitam"); //DeleteLast
    deleteElmMovie(A,"Joker"); //DeleteAfter
    viewListMovie(A);


    List_User B;
    loadDataUsers(B); // Sudah terkandung CreateList, InsertFirst, InsertLast, dan InsertAfter
    viewListUser(B);
    deleteElmUser(B,"AmandaZahra"); //DeleteFirst;
    deleteElmUser(B,"ZicoArief"); //DeleteLast
    deleteElmUser(B,"DesyAnwar"); //DeleteAfter
    viewListUser(B);

    //user TheUser[userMember];
    //loginForUser(TheUser);
    //userMenu();


    return 0;
}
