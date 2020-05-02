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
    string userName;
    string access;
    char Choice;
    //Menu
    while(Choice != '4') {
        loginMenu();
        inputChoice(Choice, '1', '4');
        switch(Choice) {
        case '1':
            Choice = '-';
            loginForAdmin(theAdmin, access);
            if (access == "Granted") {
                while(Choice != '0') {
                    system("cls");
                    adminMenu();
                    inputChoice(Choice, '0', '9');
                    switch(Choice) {
                    case '1':
                        {
                            Choice = '-';
                            string title, year;
                            cout << "Title of The Movie : ";
                            inputWithSpace(title);
                            cout << "Year of the Movie  : ";
                            cin >> year;
                            address_Movie A;
                            A = createElmMovie(title, year);
                            insertLastMovie(listMovie, A);
                            cout << title <<" has been added to the list." << endl;
                            cout << "\nEnter any Key to continue.\n";
                            getch();
                            system("cls");
                            break;
                        }
                    case '2':
                        viewListMovie(listMovie);
                        system("cls");
                        break;
                    case '3':
                        {
                            viewListMovie(listMovie);
                            string title, year;
                            cout << "====>Edit Data Movie<===" << endl;
                            cout << "(Search) Title of the Movie : ";
                            inputWithSpace(title);
                            //cin.ignore();
                            //getline(cin, title);
                            address_Movie P = searchElmMovie(listMovie, title);
                            if (P != NULL) {
                                cout << "(New) Title : ";
                                inputWithSpace(title);
                                cout << "(New) Year  : ";
                                cin >> year;
                                Info(P).Judul = title;
                                Info(P).Tahun = year;
                                cout <<title + "data has been edited." << endl;
                                cout << "\nEnter any Key to continue.\n";
                                getch();
                                system("cls");
                            } else {
                                cout << " The movie not found." << endl;
                                cout << "\nEnter any Key to continue.\n";
                                getch();
                                system("cls");
                            }
                            break;

                        }
                    case '4':
                        {
                            string title;
                            cout << "====>Delete Data Movie<===" << endl;
                            cout << "(Search) Title of the Movie : ";
                            inputWithSpace(title);
                            deleteElmMovie(listMovie, title);
                            system("cls");
                            break;
                        }
                    case '5':
                        viewListUser(listUser);
                        system("cls");
                        break;
                    case '6':
                        {
                            string username;
                            cout << "====>Delete User<===" << endl;
                            cout << "(Search) Username : ";
                            cin >> username;
                            deleteElmUser(listUser, username);
                            system("cls");
                            break;
                        }
                    case '7' :
                        {
                            int totalMovie = countMovie(listMovie);
                            int totalMovieReviewed = countMovieReviewed(listMovie);
                            float percentageR = 100*float(totalMovieReviewed)/float(totalMovie);
                            string theMost = Info(Movie(searchTheMostReviewedMovie(listRelation))).Judul;
                            string ActiveUser = Info(User(searchTheMostActiveUser(listRelation))).username;
                            cout << "===>The Statitic of the Movies<===" << endl;
                            cout << "Total number of movies        : " << totalMovie << endl;
                            cout << "Movies has been reviewed      : " << totalMovieReviewed << endl;
                            cout << "Percentage of movies reviewed : " << percentageR << " %" << endl;
                            cout << "The Most Reviewed Movie       : " << theMost;
                            cout << " (" << countReviewedSingleMovie(listRelation, theMost) << " Review)" << endl;
                            cout << "The Most Active User          : " << ActiveUser;
                            cout << " (" << countReviewOfUser(listRelation, ActiveUser) << " Review)" << endl;

                            cout << "\nEnter any Key to continue.\n";
                            getch();
                            system("cls");
                            break;
                        }
                    case '8':
                        cout << "===> Detail Movies<===" << endl;
                        viewListRelation(listRelation);
                        cout << "\nEnter any Key to continue.\n";
                        getch();
                        break;
                    case '9':
                        cout << "===> Detail Users <<=" << endl;
                        viewDetailUsers(listRelation, listUser);
                        cout << "\nEnter any Key to continue.\n";
                        getch();
                    }
                }
            }
            system("cls");
            break;
        case '2':
            Choice = '0';
            loginForUser(listUser, access, userName);
            if(access == "Granted"){
                while(Choice != '4'){
                    system("cls");
                    userMenu();
                    inputChoice(Choice, '1', '4');
                    switch(Choice){
                    case '1':
                        {
                            string title, review, time;
                            //address_User u=First(listUser);
                            address_Movie mt;
                            int i=0;
                            bool check;
                            cout<<"====>Insert a Review<===\n\n";
                            viewListMovie(listMovie);
                            cout<<"What movie title do you want to review?\n";
                            cout<<"Title : ";
                            inputWithSpace(title);
                            mt = searchElmMovie(listMovie, title);
                            cout<<endl;
                            if (mt != NULL){
                                cout<<"===>Reviewing Movie "<<title<<"<===\n";
                                check = duplicateUsernameAtRelation(listRelation, userName, title);
                                if (!check){
                                cout<<"Write a review :\n";
                                    //istream& ignore (streamsize n = 1, int delim = EOF);
                                    //getline(cin, review);
                                    inputWithSpace(review);

                                    insertElmRelation(listRelation, listMovie, listUser, title, userName, review);
                                    viewListRelation(listRelation);
                                }else{
                                    cout<<"You have reviewed "<<title<<endl;
                                }
                            }else{
                                cout<<"Movie not on the list";
                            }
                            cout << "\nEnter any Key to continue.\n";
                            getch();
                            system("cls");
                            break;
                        }
                    case '2':
                        {
                            //address_User u=First(listUser);
                            string title;
                            bool check;
                            viewMyListRelation(listRelation, userName, check);
                            cout<<endl;
                            if (check){
                                Choice = '0';
                                while(Choice != '2'){
                                    cout<<"1. Delete Movie Review\n";
                                    cout<<"2. Exit\n";
                                    cout<<"Enter your choice: ";
                                    inputChoice(Choice, '1', '2');
                                    switch(Choice){
                                    case '1':
                                        {
                                            cout<<"What movie reviews you want to delete?\n";
                                            inputWithSpace(title);
                                            deleteElmRelation(listRelation, title, userName);
                                            cout<< "Review of " + title + " has been deleted." << endl;
                                            cout << "\nEnter any Key to continue.\n";
                                            getch();

                                            viewMyListRelation(listRelation, userName, check);
                                            break;
                                        }
                                    }
                                }

                            } else {
                                cout << "\nEnter any Key to continue.\n";
                                getch();
                            }
                            system("cls");
                            break;
                        }
                    case '3':
                        {
                            Choice = '0';
                            //address_User P = First(listUser), Q;
                            address_User P = searchElmUser(listUser, userName);
                            string username, password;
                            int age;
                            while(Choice != '4'){
                                cout << "===>My Info (Now)<===" << endl;
                                cout<<"Username : "<< Info(P).username<<endl;
                                cout<<"Password : "<< Info(P).password<<endl;
                                cout<<"Age      : "<< Info(P).umur<<endl;
                                cout<<endl;
                                cout<<"===>Edit My Info<===\n";
                                cout<<"1) Change Username\n";
                                cout<<"2) Change Password\n";
                                cout<<"3) Change Age\n";
                                cout<<"4) Exit\n";
                                cout<<" enter your choice: ";
                                inputChoice(Choice, '1', '4');
                                switch(Choice){
                                case '1':
                                    {
                                        cout<<"Input your new username :";
                                        cin>>username;
                                        Info(P).username = username;
                                        userName = username;
                                        system("cls");
                                        break;
                                    }
                                case '2':
                                    {
                                        cout<<"Input your new password :";
                                        cin>>password;
                                        Info(P).password = password;
                                        system("cls");
                                        break;
                                    }
                                case '3':
                                    {
                                        cout<<"Input your age :";
                                        cin>>age;
                                        Info(P).umur = age;
                                        system("cls");
                                        break;
                                    }
                                }
                            }
                            Choice = 0;
                            system("cls");
                            break;
                        }
                    }
                }
            }
            system("cls");
            Choice = 0;
            break;
        case '3':
            Choice = '0';
            while(Choice != '3'){
                nonuserMenu();
                inputChoice(Choice, '1', '3');
                switch(Choice){
                case '1':
                    {
                        infotype_User regData;

                        cout<<"===> Register a New Member <==="<<endl;
                        cout<<"Username : ";
                        cin>>regData.username;
                        //inputWithSpace(regData.username);
                        cout<<"Password : ";
                        cin>>regData.password;
                        //insertPasword(regData.password);
                        cout<<"Age      : ";
                        cin>>regData.umur;
                        InsertElmUser(listUser, regData);
                        cout<<"The account has been resgisted. Please try to Log-in."<<endl;
                        cout << "\nEnter any Key to continue.\n";
                        getch();

                        //viewListUser(listUser);
                        //cout<<"Enter 3 to menu"<<endl;
                        system("cls");
                        break;
                    }
                case '2':
                    {
                        viewListRelation(listRelation);
                        //cout<<"Enter 3 to menu"<<endl;
                        system("cls");
                        break;

                    }
                }

            }
            break;
        case '4':
            access = "Denied";
            break;
        }
    }




    return 0;
}
