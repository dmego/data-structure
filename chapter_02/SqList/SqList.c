#include "SqList.h"

/**
 * 初始化一个顺序表
 */
void InitList(SqList *L) {
    memset(L->data, 0, sizeof(L->data)); // 初始化顺序表所有元素为0
    L->length = 0;
}

// 销毁一个顺序表
void DestroyList(SqList *L) {

}

/**
 * 在顺序表第 index (1 <= index <= length + 1) 个位置插入元素 e
 * (元素下标与数组下标相同)
 */
bool ListInsert(SqList *L, int index, ElemType e) {
    // 如果待插入位置不满足条件 返回 false (注意顺序表元素下标从 1 开始)
    if (index < 1 || index > L->length + 1) return false;
    // 顺序表已满，返回 false
    if (L->length >= MaxSize) return false;
    // 从后往前遍历，将 data[index] 及之后的元素全部后移一位
    for (int i = L->length; i >= index; i--) {
        L->data[i + 1] = L->data[i];
    }
    L->data[index] = e;
    // 顺序表长度加一
    L->length++;
    return true;
}

/**
 *  删除顺序表第 index (1 <= index <= length) 个位置的元素，并赋值给 e
 * (元素下标与数组下标相同)
 */
bool ListDelete(SqList *L, int index, ElemType *e) {
    if (index < 1 || index > L->length) return false;
    if (L->length == 0) return false;
    // 将删除元素赋值给 e
    *e = L->data[index];
    for(int i = index; i <= L->length; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return true;
}

/**
 * 按值查找元素 e, 返回所在下标
 */
int LocateElem(SqList L, ElemType e) {
    if (L.length == 0) return 0;
    for (int i = 1; i <= L.length; i++) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return 0;
}

void printList(SqList *list) {
    for (int i = 1; i <= list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}





