#include "General-Header.h"
#include "List-Parent-Reviewer.h"
#include "List-Parent-Movie.h"
#include "List-Relation.h"

int main()
{
    /*admin TheAdmin[adminMember];
    loadDataAdmin(TheAdmin);
    loginForAdmin(TheAdmin);
    adminMenu();

    List_Movie L;
    loadDataMovies(L);
    viewListMovie(L);

    List_User A;
    loadDataUsers(A);
    //viewListUser(A);
    viewListUser(A);
    */

    user TheUser[userMember];
    loadDataUser(TheUser);
    loginForUser(TheUser);
    userMenu();


    return 0;
}
