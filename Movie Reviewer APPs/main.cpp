#include "General-Header.h"
#include "List-Parent-Movie.h"
#include "List-Relation.h"
#include "List-Parent-Reviewer.h"
#include <cstdio>

int main()
{

/*
    admin TheAdmin[adminMember];
    loadDataAdmin(TheAdmin);
    loginForAdmin(TheAdmin);
    adminMenu(); */
/*
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
    deleteElmRelation(C, "Ayat-Ayat Cinta 2", "BreadSalad");
    viewListRelation(C);



    //user TheUser[userMember];
    //loginForUser(TheUser);
    //userMenu();
*/


    //Set UP & Load the default data
    List_Movie listMovie;
    List_Relation listRelation;
    List_User listUser;
    loadDataUsers(listUser);
    loadDataMovies(listMovie);
    loadDataRelation(listRelation, listMovie, listUser);

    //variabel Set Up;
    admin theAdmin[adminMember];
    loadDataAdmin(theAdmin);

    string access;
    char Choice;
    cout << countMovieReviewed(listMovie);
    //Menu
    while(Choice != '4') {
        loginMenu();
        inputChoice(Choice, '1', '4');
        switch(Choice) {
        case '1':
            Choice = '0';
            loginForAdmin(theAdmin, access);
            if (access == "Granted") {
                while(Choice != '8') {
                    adminMenu();
                    inputChoice(Choice, '1', '8');
                    switch(Choice) {
                    case '1':
                        {
                            Choice = '0';
                            string title, year;
                            cout << "Title of The Movie : ";
                            cin.ignore();
                            getline(cin, title);
                            cout << "Year of the Movie  : ";
                            cin >> year;
                            address_Movie A;
                            A = createElmMovie(title, year);
                            insertLastMovie(listMovie, A);
                            cout << title <<" has been added to the list." << endl;
                            break;
                        }
                    case '2':
                        viewListMovie(listMovie);
                        break;
                    case '3':
                        {
                            string title, year;
                            cout << "====>Edit Data Movie<===" << endl;
                            cout << "(Search) Title of the Movie : ";
                            cin.ignore();
                            getline(cin, title);
                            address_Movie P = searchElmMovie(listMovie, title);
                            if (P != NULL) {
                                cout << "(New) Title : ";
                                cin.ignore();
                                getline(cin, title);
                                cout << "(New) Year  : ";
                                cin >> year;
                                Info(P).Judul = title;
                                Info(P).Tahun = year;
                            } else {
                                cout << "The movie not found." << endl;
                            }
                            break;

                        }
                    case '4':
                        {
                            string title;
                            cout << "====>Delete Data Movie<===" << endl;
                            cout << "(Search) Title of the Movie : ";
                            getline(cin, title);
                            getline(cin, title);
                            deleteElmMovie(listMovie, title);
                            cout << "\nEnter any Key to continue.\n";
                            getch();
                            break;
                        }
                    case '5':
                        viewListUser(listUser);
                        break;
                    case '6':
                        {
                            string username;
                            cout << "====>Delete User<===" << endl;
                            cout << "(Search) Username : ";
                            cin >> username;
                            deleteElmUser(listUser, username);
                            break;
                        }
                    case '7' :
                        {
                            cout << "===>The Statitic of the Movies<===" << endl;
                            cout << "Total number of movies   : " << countMovie(listMovie) << endl;
                            cout << "Movies has been reviewed : " << countMovieReviewed(listMovie) << endl;
                            cout << "\nEnter any Key to continue.\n";
                            getch();
                            break;
                        }
                    default:
                        cout << "Missing the choice, you input wrong number." << endl;
                    }
                }
            }
        case '2':
            Choice = '0';
            loginForUser(listUser, access);
            if(access == "Granted"){
                while(Choice != '5'){
                    userMenu();
                    inputChoice(Choice, '1', '5');
                    switch(Choice){
                    case '1':
                        {
                            break;
                        }
                    case '2':
                        {
                            break;
                        }
                    case '3':
                        {
                            break;
                        }
                    case '4':
                        {
                            address_User P = First(listUser);
                            cout << "===>My Info<===" << endl;
                            cout<<"Username : "<< Info(P).username<<endl;
                            cout<<"Password : "<< Info(P).password<<endl;
                            cout<<"Umur : "<< Info(P).umur<<endl;
                            cout<<endl;
                            break;
                        }
                    default:
                        cout << "Missing the choice, you input wrong number." << endl;
                    }
                }
            }

            break;
        case '3':
            break;
        case '4':
            access = "Denied";
            break;
        default:
            cout << "Missing the choice, you input wrong number." << endl;
        }
    }




    return 0;
}
