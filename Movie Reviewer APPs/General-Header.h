#ifndef GENERAL-HEADER_H_INCLUDED
#define GENERAL-HEADER_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <ctime>
//#include <string>
#define Next(P) P->Next
#define Prev(P) P->Prev
#define Info(P) P->Info
#define Movie(P) P->Movie
#define User(P) P->User
#define First(L) L.First
#define Last(L) L.Last

using namespace std;

struct admin {
    string username;
    string password;
};

const int adminMember = 2;

// Struct for ALL of the lists.
struct movie {
    string Judul, Tahun, Status;
};
struct review {
    string title, comment, date;
};
struct user {
    string username, password;
    int umur;
};

// typedef for ALL of the lists
typedef movie infotype_Movie;
typedef user infotype_User;
typedef review infotype_Relation;
typedef struct elmList_Movie *address_Movie;
typedef struct elmlist_User *address_User;
typedef struct elmList_Relation *address_Relation;

// struct element for ALL of the list
struct elmList_Movie {
    infotype_Movie Info;
    address_Movie Next;
};
struct elmlist_User {
    infotype_User Info;
    address_User Next;
};
struct elmList_Relation {
    infotype_Relation Info;
    address_Relation Next;
    address_Relation Prev;
    address_Movie Movie;
    address_User User;
};

// struct LIST for ALL of the lists
struct List_Movie {
    address_Movie First;
    address_Movie Last;
};
struct List_User {
    address_User First;
    address_User Last;
};
struct List_Relation {
    address_Relation First;
};

void loginMenu();
void adminMenu();
void userMenu();
void greetingUser(string username);
void greetingAdmin(string adminName);
void insertPasword(string &password);
void loginForAdmin(admin theAdmin[adminMember]);
bool validasiAdmin(admin theAdmin[adminMember], string username, string password);
void loadDataAdmin(admin theAdmin[adminMember]);

#endif // GENERAL-HEADER_H_INCLUDED
