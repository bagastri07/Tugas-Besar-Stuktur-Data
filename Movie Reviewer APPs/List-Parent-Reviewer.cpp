#include "General-Header.h"
#include "List-Parent-Reviewer.h"

void createListUser(List_User &L){
    First(L) = NULL;
    Last(L) = NULL;
}

bool isEmptyListUser(List_User &L){
    if (First(L) == NULL && Last(L) == NULL){
        return true;
    }else
    {
        return false;
    }

}

address_User createElmUser(infotype_User newData){
    address_User P;
    P = new elmlist_User;
    Info(P).username = newData.username;
    Info(P).password = newData.password;
    Info(P).umur = newData.umur;
    Next(P) = NULL;
    return P;
}

void viewListUser(List_User L){
    address_User x;
    x = First(L);
    cout<<"===>List User<===="<<endl;
    while (x != NULL){
        cout<<"Username : "<<Info(x).username<<endl;
        cout<<"Age      : "<<Info(x).umur<<endl;
        cout<<endl;
        x = Next(x);
    }
    cout << "\nEnter any Key to continue.\n";
    getch();
}

void insertLastUser(List_User &L, address_User P){
    if (isEmptyListUser(L)){
        First(L) = P;
        Last(L) = P;
    }else{
        Next(Last(L)) = P;
        Last(L) = P;
    }
}

void insertFirstUser(List_User &L, address_User P){
    if (isEmptyListUser(L)){
        First(L) = P;
        Last(L) = P;
    }else{
        Next(P) = First(L);
        First(L) = P;
    }
}

void insertAfterUser(address_User Prec, address_User &P){
    if (Prec != NULL){
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }else{
        cout<<"Your Insert Failed"<<endl;
        cout<<endl;
    }
}

void deleteFirstUser(List_User &L, address_User &P){
    if (isEmptyListUser(L)){
        P = First(L);
        First(L) = NULL;
        Last(L) = NULL;
    }else{
        P = First(L);
        First(L) = Next(P);
        Next(P) = NULL;
    }
}
void InsertElmUser(List_User &L, infotype_User newData) {
    address_User P = createElmUser(newData);
    if (!isEmptyListUser(L)) {
        if (newData.username <= Info(First(L)).username) {
            insertFirstUser(L,P);
        } else if (newData.username >= Info(Last(L)).username) {
            insertLastUser(L,P);
        } else {
            address_User A = First(L);
            while (newData.username > Info(Next(A)).username) {
                A = Next(A);
            }
            insertAfterUser(A,P);
        }
    } else {
        insertFirstUser(L,P);
    }
}

void deleteLastUser(List_User &L, address_User &P){
    if (Next(First(L)) == NULL) {
        deleteFirstUser(L,P);
    } else {
        P = Last(L);
        address_User x = First(L);
        while (Next(Next(x)) != NULL) {
            x = Next(x);
        }
        Last(L) = x;
        Next(x) = NULL;
    }
}

void deleteAfterUser(address_User Prec, address_User &P){
    P = Next(Prec);
    Next(Prec) = Next(P);
    Next(P) = NULL;
}

address_User searchElmUser(List_User L, string username){
    address_User x = First(L);
    bool Found = false;
    while (x != NULL && !Found) {
        if (Info(x).username == username) {
            Found = true;
        } else {
            x = Next(x);
        }
    }
    if (Found) {
        return x;
    } else {
        return NULL;
    }
}

void deleteElmUser(List_User &L, string username){
    if (!isEmptyListUser(L)) {
        address_User P = searchElmUser(L,username);
        if (P != NULL) {
            if (P == First(L)) {
                deleteFirstUser(L,P);
            } else if (P == Last(L)) {
                deleteLastUser(L,P);
            } else {
                address_User x = First(L);
                while (Next(x) != P) {
                x = Next(x);
                }
                deleteAfterUser(x,P);
            }
            cout << username <<" has been deleted." << endl;
        } else {
        cout << "Username is undefined." << endl;
        }
    } else {
        cout << "User list is empty." << endl;
    }
    cout << "\nEnter any Key to continue.\n";
    getch();
}

bool duplicateUsernameChecker(List_User L, string usernm) {
    address_User A = First(L);
    bool duplicate = false;
    while (A != NULL && !duplicate) {
        if (Info(A).username == usernm) {
            duplicate = true;
        } else {
            A = Next(A);
        }
    }
    return duplicate;
}

void loadDataUsers(List_User &L){
    createListUser(L);
    infotype_User newData;
    newData.username = "Reynaldo32", newData.password  ="thisispassword123", newData.umur = 19;
    InsertElmUser(L,newData);
    newData.username = "AmandaZahra", newData.password  ="thisispassword123", newData.umur = 29;
    InsertElmUser(L,newData);
    newData.username = "ZicoArief", newData.password  ="thisispassword123", newData.umur = 33;
    InsertElmUser(L,newData);
    newData.username = "BreadSalad", newData.password  ="thisispassword123", newData.umur = 13;
    InsertElmUser(L,newData);
    newData.username = "DesyAnwar", newData.password  ="thisispassword123", newData.umur = 33;
    InsertElmUser(L,newData);
    newData.username = "1", newData.password  ="1", newData.umur = 21;
    InsertElmUser(L,newData);
}

void loginForUser(List_User theUser, string &access, string &userN){
    cout << "*************************************************************\n";
    cout << "*                   Movie Reviewer APPs                     *\n";
    cout << "                        User Login                         *\n";
    cout << "*************************************************************\n";
    string username, password;

    cout << "Username : ";
    cin >> username;
    userN = username;
    cout << "Password : ";
    insertPasword(password);
    cout << endl;
    if (validasiUser(theUser, username, password)) {
        greetingUser(username);
        access = "Granted";
    } else {
        cout << "The username and/or password you specified are not correct.\n";
        access = "Denied";
    }
    cout << "\nEnter any Key to continue.\n";
    getch();
}

bool validasiUser(List_User theUser, string username, string password){
    bool check = false;
    address_User P = searchElmUser(theUser, username);
    while (P != NULL) {
        if (Info(P).password == password && Info(P).username == username) {
            check = true;
        }
        P = Next(P);

    }
    return check;
}
