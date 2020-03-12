#include "General-Header.h"
#include "List-Parent-Movie.h"

int main()
{
    //Testing LIST PARENT MOVIE (STATUS 100% Working)
    List_Movie ListMovie;
    address_Movie A; // A = Address dari elmlist_Movie
    createListMovie(ListMovie);
    A = createElmMovie("Gundala","2019");
    insertLastMovie(ListMovie,A);
    A = createElmMovie("Ayat-Ayat Cinta 2","2018");
    insertLastMovie(ListMovie,A);
    A = createElmMovie("Hit & Run","2019");
    insertLastMovie(ListMovie,A);
    A = createElmMovie("Spider Man : Far From Home","2019");
    insertLastMovie(ListMovie,A);
    A = createElmMovie("Joker","2019");
    insertLastMovie(ListMovie,A);
    viewListMovie(ListMovie);
    deleteElmMovie(ListMovie, "Jokera"); //Uji coba Procedur Delete
    viewListMovie(ListMovie);


    return 0;
}
