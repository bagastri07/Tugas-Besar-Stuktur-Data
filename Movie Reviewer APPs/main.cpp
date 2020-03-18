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
    loadDataMovies(A);
    viewListMovie(A);

    List_User B;
    loadDataUsers(B);
    viewListUser(B);

    //user TheUser[userMember];
    //loginForUser(TheUser);
    //userMenu();


    return 0;
}
