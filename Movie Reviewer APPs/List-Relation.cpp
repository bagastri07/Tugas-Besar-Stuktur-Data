#include "General-Header.h"
#include "List-Relation.h"

void createListRelation(List_Relation &L) {
    First(L) == NULL;
}
bool isEmptyListRelation(List_Relation &L) {
    return First(L) == NULL;
}
void insertLastRelation(List_Relation &L, address_Relation P) {
    if (isEmptyListRelation(L)) {
        First(L) = P;
        Next(P) = P;
    } else {
        Next(P) = First(L);
        Prev(P) = Prev(First(L));
        Next(Prev(First(L))) = P;
        Prev(First(L)) = P;
    }
}
void deleteFirstRelation(List_Relation &L, address_Relation &P);
void deleteLastRelation(List_Relation &L, address_Relation &P);
void deleteAfterRelation(address_Relation Prec, address_Relation &P);
address_Relation searchElmRelation(List_Relation L, string title) {
    address_Relation A  = First(L);
    bool Found = false;
    do {
        if (title == Info(A).title) {
            Found = true;
        } else {
            A = Next(A);
        }
    } while (A != First(L) && !Found);
    return A;
}
void deleteElmRelation(List_Relation L, string title);
