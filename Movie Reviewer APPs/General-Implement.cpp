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
void insertPasword(string &password) {
    char pass[32];
    char ch;
    bool Enter = false;
    int i = 0;
    while (!Enter) { // looping for ever
        password = "";
        ch = _getch();
        if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) {
            pass[i]=ch; //store the ch to the pass
            cout << '*';
            i++;
        }
        if (ch=='\b' && i>=1) {
            cout << "\b \b"; //to delete wrong character that user input
            i--;
        }
        if (ch=='\r') { //r is Enter or 13 charecter code (enter)
            Enter = true;
        }
    }
    password = pass;
}
void loginForAdmin(admin theAdmin[adminMember]) {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "                        Admin Login                         *\n";
    cout << "*************************************************************\n";
    string username, password;

    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    insertPasword(password);
    cout << endl;
    if (validasiAdmin(theAdmin, username, password)) {
        greetingAdmin(username);
    } else {
        cout << "The username and/or password you specified are not correct.\n";
    }
    cout << "\nEnter any Key to continue.\n";
    getch();

}
bool validasiAdmin(admin theAdmin[adminMember], string username, string password) {
    bool check = false;
    for (int i = 0; i < 2; i++) {
        if (username == theAdmin[i].username && password == theAdmin[i].password) {
            check = true;
        }
    }
    return check;
}
void loadDataAdmin(admin theAdmin[adminMember]) {
    theAdmin[0].username = "BagasTri07";
    theAdmin[0].password = "sayaAdmin";
    theAdmin[1].username = "MaulanaFC";
    theAdmin[1].password = "sayaJuga";
}

void loginForUser(user theUser[userMember]){
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "                        User Login                         *\n";
    cout << "*************************************************************\n";
    string username, password;

    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    insertPasword(password);
    cout << endl;
    if (validasiUser(theUser, username, password)) {
        greetingUser(username);
    } else {
        cout << "The username and/or password you specified are not correct.\n";
    }
    cout << "\nEnter any Key to continue.\n";
    getch();
}

bool validasiUser(user theUser[userMember], string username, string password){
    bool check = false;
    for (int i = 0; i < 4; i++) {
        if (username == theUser[i].username && password == theUser[i].password) {
            check = true;
        }
    }
    return check;
}
/*
void loadDataUser(user theUser[userMember]){
    theUser[0].username = "Alex";
    theUser[0].password = "sayaAlex";
    theUser[1].username = "Bobi";
    theUser[1].password = "sayaBobi";
    theUser[2].username = "Charles";
    theUser[2].password = "sayaCharles";
    theUser[3].username = "Dion";
    theUser[3].password = "sayaDion";
}*/
