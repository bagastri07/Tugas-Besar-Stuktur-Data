#include "General-Header.h"


void loginMenu() {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "*************************************************************\n";
    cout << "* |1|. Login as Admin                                       *\n";
    cout << "* |2|. Login as User                                        *\n";
    cout << "* |3|. Non User                                             *\n";
    cout << "* |4|. Exit                                                 *\n";
    cout << "*************************************************************\n";
    cout << "Enter your choice and press enter: ";
}
void adminMenu() {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "*                         Admin Menu                        *\n";
    cout << "*************************************************************\n";
    cout << "* |1|. Insert New Movie                                     *\n";
    cout << "* |2|. View All Movie                                       *\n";
    cout << "* |3|. Update Data Movie                                    *\n";
    cout << "* |4|. Delete Data Movie                                    *\n";
    cout << "* |5|. View Data Reviewer                                   *\n";
    cout << "* |6|. Delete Reviewer (user)                               *\n";
    cout << "* |7|. Statistic of Movies                                  *\n";
    cout << "* |8|. Detail of Movies                                     *\n";
    cout << "* |9|. Detail of Users                                      *\n";
    cout << "* |0|. Log-out                                              *\n";
    cout << "*************************************************************\n";
    cout << "Enter your choice : ";
}
void userMenu() {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "*                        User Menu                          *\n";
    cout << "*************************************************************\n";
    cout << "* |1|. Insert a Review                                      *\n";
    cout << "* |2|. My Review Movie                                      *\n";
    cout << "* |3|. My Info                                              *\n";
    cout << "* |4|. Log-out                                              *\n";
    cout << "*************************************************************\n";
    cout << "Enter your choice : ";
}

void nonuserMenu() {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "*                      Non User Menu                        *\n";
    cout << "*************************************************************\n";
    cout << "* |1|. Register                                             *\n";
    cout << "* |2|. View All Reviews                                     *\n";
    cout << "* |3|. Return to Menu                                       *\n";
    cout << "*************************************************************\n";
    cout << "Enter your choice : ";
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
    password = "";
    while (!Enter) { // looping for ever
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
            pass[i] = '\0';
            Enter = true;
        }
    }
    //string Temp(pass);
    password = pass;
   //cout << password;
}
void loginForAdmin(admin theAdmin[adminMember], string &access) {
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "*                        Admin Login                        *\n";
    cout << "*************************************************************\n";
    string username, password;

    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    insertPasword(password);
    cout << endl;
    if (validasiAdmin(theAdmin, username, password)) {
        greetingAdmin(username);
        access = "Granted";
    } else {
        cout << "The username and/or password you specified are not correct.\n";
        access = "Denied";
    }
    cout << "\nEnter any Key to continue.\n";
    getch();

}
bool validasiAdmin(admin theAdmin[adminMember], string username, string password) {
    bool check = false;
    for (int i = 0; i < adminMember; i++) {
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
    theAdmin[2].username = "a";
    theAdmin[2].password = "a";
}

string getDateAndTime() {
    // current date/time based on current system
   time_t now = time(0);

   // convert now to string form
    char* dt = ctime(&now);
    return dt;

}
/*
bool validasiChoice(int input,int Min, int Max) {
    return input >= Min && input <= Max;
}
void inputChoice(int &choice, int Min, int Max) {
    int i = 4;
    do {
        if (i < 4) {
            cout << "Miss the choice, try again ... (" << i << ") : ";
        }
        cin >> choice;
        i--;
    } while (!validasiChoice(choice, Min, Max) && i != -1);
}*/

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

bool validasiChoice(char input, char Min, char Max) {
    return input <= Max && input >= Min;
}
void inputChoice(char &choice, char Min, char Max) {
    do {
        choice = _getch();
    } while (!validasiChoice(choice, Min, Max));
    cout << endl;
}
void inputWithSpace(string &Input) {
    string temp;
    string temp2 = "";
    cin >> temp;
    //cin.ignore();
    getline(cin, temp2);
    if (temp2 == "") {
        Input = temp;
    } else {
        Input = temp + temp2;
    }
}
/*
void inputWithSpace(string &Input) {
    char pass[32];
    char ch;
    bool Enter = false;
    int i = 0;
    while (!Enter) { // looping for ever
        Input = "";
        ch = _getch();
        if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') || ch == ' ') {
            pass[i]=ch; //store the ch to the pass
            cout << ch;
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
    char a[i];
    for (int j = 0; j <= i; j++) {
        a[j] = pass[j];
    }
    string Temp(a);
    Input = Temp;
   cout << Input;
}*/
