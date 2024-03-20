/*
 将两个有序顺表序合并为一个新的有序顺序表, 并由函数返回结果顺序表。
 */

#include "SqList.h"

void mergeList(SqList *L, SqList *S, SqList *A) {
    if (L->length == 0) return;
    if (S->length == 0) return;
    int i = 0, j = 0;
    int k = 0;
    while (i < L->length && j < S->length) {
        if (L->data[i] <= S->data[j]) {
            A->data[k] = L->data[i];
            i++;
        } else {
            A->data[k] = S->data[j];
            j++;
        }
        k++;
    }
    while (i < L->length) {
        A->data[k] = L->data[i];
        k++;
        i++;
    }
    while (j < S->length) {
        A->data[k] = S->data[j];
        k++;
        j++;
    }
    A->length = k;
}



int main() {

    SqList L;
    SqList S;
    SqList A;
    ElemType e;
    InitList(&L);
    InitList(&S);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 3);
    ListInsert(&L, 3, 5);

    ListInsert(&S, 1, 2);
    ListInsert(&S, 2, 4);
    ListInsert(&S, 3, 5);
    ListInsert(&S, 4, 6);

    printf("before: \n");
    printf("L: ");
    printList(L);
    printf("S: ");
    printList(S);

    InitList(&A);
    mergeList(&L, &S, &A);
    printf("after: \n");
    printList(A);
}
