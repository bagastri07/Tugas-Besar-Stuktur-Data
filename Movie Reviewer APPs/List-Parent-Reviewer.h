#ifndef LIST-PARENT-REVIEWER_H_INCLUDED
#define LIST-PARENT-REVIEWER_H_INCLUDED

void createListUser(List_User &L);
bool isEmptyListUser(List_User &L);
address_User createElmUser(string username, string password, int umur);
void viewListUser(List_User L);
void insertLastUser(List_User &L, address_User P);
void insertFirstUser(List_User &L, address_User P);
void insertAfterUser(address_User Prec, address_User &P);
void deleteFirstUser(List_User &L, address_User &P);
void deleteLastUser(List_User &L, address_User &P);
void deleteAfterUser(address_User Prec, address_User &P);
address_User searchElmUser(List_User L, string username);
void deleteElmUser(List_User &L, string username);
void loadDataUsers(List_User &L);

#endif // LIST-PARENT-REVIEWER_H_INCLUDED
