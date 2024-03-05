/*
 对长度为 n 的顺序表 L ，编写一个时间复杂度为O(n)、 空间复杂度为O(1)的算法，该算
 法删除顺序表中有所有值为 x 的数据元素
 */
#include "SqList.h"

/**
 * 遍历顺序表，将所以不等于 x 的元素移动到顺序表前面区域，定义一个下标 k=0,表示顺序表中不等于 x 元素区域的边界
 * 边界结束后，顺序表的长度就是 k
 */
void delValueXFromList(SqList *L, ElemType x) {
    if (L->length == 0) return;
    int k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            k++; // 不等于 x 的元素个数 + 1
        }
    }
    L->length = k; // 更新顺序表长度
}


// ⚠️：这种方法会改变顺序表中元素的顺序
void delValueXFromList3(SqList *L, ElemType x) {
    if (L->length == 0) return;
    int size = 0;
    int i = 0;
    int j = L->length - 1;
    while (i <= j) {
        if (L->data[i] == x) {
            swap(L, i, j);
            size++;
            j--;
        }
        if (L->data[i] != x) {
            i++;
        }
    }
    L->length = L->length - size;
}


int main() {
    SqList L;
    ElemType e;
    InitList(&L);
    ListInsert(&L, 1, 5);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 2);
    ListInsert(&L, 5, 4);
    ListInsert(&L, 6, 2);

    printf("before delete\n");
    printList(L);

    delValueXFromList(&L, 2);
    //delValueXFromList3(&L, 2);
    printf("after delete\n");
    printList(L);
}