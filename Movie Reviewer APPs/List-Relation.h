#ifndef LIST-RELATION_H_INCLUDED
#define LIST-RELATION_H_INCLUDED
#include "General-Header.h"

void createListRelation(List_Relation &L);
bool isEmptyListRelation(List_Relation &L);
address_Relation createElmRelation(List_Movie ListMovie, List_User ListUser,string titleMovie, string review, string date, string username);
void insertFirstRelation(List_Relation &L, address_Relation P);
void insertElmRelation(List_Relation &L, List_Movie ListMovie, List_User ListUser, string titleMovie, string username, string review);
void deleteFirstRelation(List_Relation &L, address_Relation &P);
void deleteLastRelation(List_Relation &L, address_Relation &P);
void deleteAfterRelation(address_Relation Prec, address_Relation &P);
address_Relation searchElmRelation(List_Relation L, string title, string username);
void deleteElmRelation(List_Relation &L, string title, string username);
void viewListRelation(List_Relation L);
bool duplicateUsernameAtRelation (List_Relation L, string username, string title );
void loadDataRelation(List_Relation &L, List_Movie ListMovie, List_User ListUser);



#endif // LIST-RELATION_H_INCLUDED
