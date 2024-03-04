#include "SqList.h"

int main() {

    SqList L;
    ElemType e;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 4);

    ListInsert(&L, 2, 5);

    ListDelete(&L, 2, &e);

    int lo = LocateElem(L, 4);

    printf("hh");
    printf("lo: %d", lo);
}