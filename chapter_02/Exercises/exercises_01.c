/*
从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位
置由最后一个元素填补，若顺序表为空，则显示出信错息退并出运行
 */

#include "SqList.h"

bool deleteMinElem(SqList *L, ElemType *e) {
    if (L->length == 0) {
        printf("list is empty!");
        return false;
    }
    // 找到顺序表中最小元素
    int min = 0;
    for (int i = 1; i < L->length; i++) {
        if (L->data[i] < L->data[min]) {
            min = i;
        }
    }
    *e = L->data[min];
    // 将顺序表中最后一个元素放置到被删除的最小元素位置
    if (min != L->length) {
        L->data[min] = L->data[L->length];
    }
    L->data[L->length] = 0;
    L->length--;
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

    deleteMinElem(&L, &e);

    printf("minElem: %d", e);
}