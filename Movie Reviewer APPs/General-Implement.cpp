#include "General-Header.h"

void loginMenu() {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "*************************************************************\n";
    cout << " |1|. Login as Admin                                        *\n";
    cout << " |2|. Login as User                                         *\n";
    cout << " |3|. Register New User                                     *\n";
    cout << " |4|.Exit.                                                 *\n";
    cout << "*************************************************************\n";
    cout << " Enter your choice and press enter: ";
}
void adminMenu() {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "                         Admin Menu                         *\n";
    cout << "*************************************************************\n";
    cout << " |1|. Insert New Movie                                      *\n";
    cout << " |2|. View All Movie                                        *\n";
    cout << " |3|. Update Data Movie                                     *\n";
    cout << " |4|. Delete Data Movie                                     *\n";
    cout << " |5|. View Data Reviewer                                    *\n";
    cout << " |6|. Delete Reviewer (user)                                *\n";
    cout << " |7|. Statitic of Movies                                    *\n";
    cout << " |8|. Statitic of Movies                                    *\n";
    cout << " |9|.Exit.                                                  *\n";
    cout << "*************************************************************\n";
    cout << " Enter your choice and press enter: ";
}
void userMenu() {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "                         User Menu                          *\n";
    cout << "*************************************************************\n";
    cout << " |1|. Insert a Review                                       *\n";
    cout << " |2|. Delete a Review                                       *\n";
    cout << " |3|. My Review Movie                                       *\n";
    cout << " |4|. My Info                                               *\n";
    cout << " |5|.Exit.                                                  *\n";
    cout << "*************************************************************\n";
    cout << " Enter your choice and press enter: ";
}
void greetingUser(string username) {
    cout << "Welcome Back!!!\n";
    cout << "Your're login as '"<<username<<"' (User)\n";
}
void greetingAdmin(string adminName) {
    cout << "Welcome Back!!!\n";
    cout << "Your're login as '"<<adminName<<"' (Admin)\n";
}