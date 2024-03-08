/*
线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储计于算机内。要求设计一个算法，
完成用最少时间在表查中找数值为 x 的元素, 若找到则将其与后继元素位置相交换，
若找不，则将其插入到表中并使表中元素仍递增有序。
 */
#include "SqList.h"

/**
 * 如果 x 在 list 中存在，则返回 x 的下标
 * 如果 x 在 list 中不存在，则返回 x 应插入的位置
 */

void swapXorInsertX(SqList *L, ElemType x) {
    int i = 0, j = L->length - 1;
    int k = 0;
    while (i <= j) {
        k = (i + j) / 2;
        if (L->data[k] == x) {
            if (k + 1 < L->length) {
                swap(L, k, k + 1);
            }
            return;
        } else if (L->data[k] < x) {
            i = k + 1;
        } else if (L->data[k] > k) {
            j = k - 1;
        }
    }
    int pos = L->data[k] > x ? k : k + 1;
    ListInsert(L, pos + 1, x);
}


void swap_case_test() {
    SqList L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 4);
    ListInsert(&L, 5, 5);
    ListInsert(&L, 6, 6);
    ListInsert(&L, 7, 7);

    printf("before swap: \n");
    printList(L);

    swapXorInsertX(&L, 3);
    printf("after swap: \n");
    printList(L);
}

void insert_case_test() {
    SqList L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 4);
    ListInsert(&L, 5, 6);
    ListInsert(&L, 6, 7);
    ListInsert(&L, 7, 8);

    printf("before insert: \n");
    printList(L);

    swapXorInsertX(&L, 5);
    printf("after insert: \n");
    printList(L);
}



int main() {
   swap_case_test();
   insert_case_test();
}
