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

address_User createElmUser(string username, string password, int umur){
    address_User P;
    P = new elmlist_User;
    Info(P).username = username;
    Info(P).password = password;
    Info(P).umur = umur;
    Next(P) = NULL;
    return P;
}

void viewListUser(List_User L){
    address_User x;
    x = First(L);
    while (x != NULL){
        cout<<"Username : "<<Info(x).username<<endl;
        cout<<"Umur     : "<<Info(x).umur<<endl;
        cout<<endl;
        x = Next(x);
    }
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
    if (isEmptyListUser(L)) {
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
        } else {
        cout << "Username tidak ditemukan" << endl;
        }
    } else {
        cout << "List Reviewer Kosong" << endl;
    }
}

void loadDataUsers(List_User &L){
    createListUser(L);
    address_User x;
    x = createElmUser("Alex","123456",18);
    insertLastUser(L,x);
    x = createElmUser("Bobi","123456",17);
    insertLastUser(L,x);
    x = createElmUser("Charles","123456",19);
    insertLastUser(L,x);
    x = createElmUser("Dion","123456",20);
    insertLastUser(L,x);
    x = createElmUser("Eka","123456",18);
    insertLastUser(L,x);
}
