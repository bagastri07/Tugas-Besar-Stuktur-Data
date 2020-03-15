#ifndef LIST-RELATION_H_INCLUDED
#define LIST-RELATION_H_INCLUDED
#include "General-Header.h"

void createListRelation(List_Relation &L);
bool isEmptyListRelation(List_Relation &L);
void insertLastRelation(List_Relation &L, address_Relation P);
void deleteFirstRelation(List_Relation &L, address_Relation &P);
void deleteLastRelation(List_Relation &L, address_Relation &P);
void deleteAfterRelation(address_Relation Prec, address_Relation &P);
address_Relation searchElmRelation(List_Relation L, string title);
void deleteElmRelation(List_Relation L, string title);



#endif // LIST-RELATION_H_INCLUDED
