#ifndef GENERAL-HEADER_H_INCLUDED
#define GENERAL-HEADER_H_INCLUDED
#include <iostream>
#define Next(P) P->Next
#define Prev(P) P->Prev
#define Info(P) P->Info
#define First(L) L.First
#define Last(L) L.Last

using namespace std;

void loginMenu();
void adminMenu();
void userMenu();
void greetingUser(string username);
void greetingAdmin(string adminName);

#endif // GENERAL-HEADER_H_INCLUDED
