/*
 从顺序表中删除其值在给定值 s 和 t之间(包含 s 和 t 要求 s < t)的所有元素,
 若 s 或 t 不合理或顺序表为空，则显示出信错息并退出运行
 */
#include "SqList.h"

bool delValueFromSToT(SqList *L, ElemType s, ElemType t) {
    if (L->length == 0 || s >= t) {
        printf("list is empty or s >= t !");
        return false;
    }
    // k 表示值在 < s or > t 之间的元素区域的边界
    int k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] < s || L->data[i] > t) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
    return true;
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
    ListInsert(&L, 6, 6);

    printf("before delete\n");
    printList(L);

    delValueFromSToT(&L, 2, 4);
    printf("after delete\n");
    printList(L);

}
