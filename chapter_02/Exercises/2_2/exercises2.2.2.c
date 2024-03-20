/*
 设计一个高效算法，将顺序表区的所有元素倒置，要算求法的空间复杂度为O(1)。
 */
#include "SqList.h"

void reverseList(SqList *L) {
    if (L->length <= 1) return;
    int i = 0;
    int j = L->length - 1;
    while (i < j) {
        ElemType temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
        i++;
        j--;
    }
}


int main() {
    SqList L;
    ElemType e;
    InitList(&L);
    ListInsert(&L, 1, 5);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 1);
    ListInsert(&L, 5, 4);

    printf("before reverse\n");
    printList(L);

    reverseList(&L);
    printf("after reverse\n");
    printList(L);
}