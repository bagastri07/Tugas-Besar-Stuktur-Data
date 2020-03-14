#ifndef GENERAL-HEADER_H_INCLUDED
#define GENERAL-HEADER_H_INCLUDED
#include <iostream>
#include <conio.h>
//#include <string>
#define Next(P) P->Next
#define Prev(P) P->Prev
#define Info(P) P->Info
#define First(L) L.First
#define Last(L) L.Last

using namespace std;

struct admin {
    string username;
    string password;
};

const int adminMember = 2;

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
