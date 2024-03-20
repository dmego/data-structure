/*
 从有序顺序表中删除有所有值重复的元素，使表中有所元素的值均不同
 */
#include "SqList.h"

/**
 * 定义 k 表示不包含重复元素顺序表的下标边界
 * 从前往后遍历，若遇到 data[i] == data[k], 说明 i 与 k 处元素重复，跳过 i
 * 若 data[i] != data[k], 说明 data[i] 是新的不重复元素，k++, 并将 data[i] 移动 data[k] 处
 */
void remainUnique(SqList *L) {
    if (L->length <= 1) return;
    int k = 0;
    for (int i = 1; i < L->length; i++) {
        if (L->data[i] != L->data[k]) {
            k++;
            L->data[k] = L->data[i];
        }
    }
    // k 表示边界下标，实际长度需要 + 1
    L->length = k + 1;
}



int main() {
    SqList L;
    ElemType e;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 1);
    ListInsert(&L, 3, 2);
    ListInsert(&L, 4, 2);
    ListInsert(&L, 5, 3);
    ListInsert(&L, 6, 4);
    ListInsert(&L, 7, 4);
    ListInsert(&L, 8, 5);
    ListInsert(&L, 9, 5);

    printf("before: \n");
    printList(L);

    remainUnique(&L);
    printf("after: \n");
    printList(L);
}
