#include "General-Header.h"
#include "List-Parent-Movie.h"
#include "List-Parent-Reviewer.h"
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
    */
    List_User L;
    loadDataUsers(L);
    viewListUser(L);

    return 0;
}
