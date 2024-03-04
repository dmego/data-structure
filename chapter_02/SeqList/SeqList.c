#include "SeqList.h"

/**
 * 初始化一个顺序表
 * @param list
 * @return 初始化成功返回 Ok 否则返回 false
 */
Status initSqList(SqList* list) {
    // 对 elem 进行初始化 内存分配
    list->elemData = malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    // 如果内存分配失败，退出
    if (list->elemData == NULL) {
        exit(OVERFLOW);
    }
    list->length = 0;            // 初始化顺序表当前长度为 0
    list->size = LIST_INIT_SIZE; // 初始化顺序表的容量为 INIT_SIZE

    return OK; // 初始化成功，返回 OK
}

/**
 * 销毁一个顺序表( free 存储空间)
 * @param list
 * @return
 */
Status destroyList(SqList* list) {
    // 确保顺序表存在
    if (list == NULL || list->elemData == NULL) return ERROR;
    // 释放顺序表存储内存
    free(list->elemData);

    // 重置顺序表结构相关属性
    list->elemData = NULL;
    list->length = 0;
    list->size = 0;

    return OK;
}

/**
 * 在顺序表中 index 位置插入元素 elem
 * 平均时间复杂度 O(n)
 * @param list
 * @param index 要插入的位置 从 1 开始
 * @param elem 要插入的元素
 * @return
 */
Status insertElem(SqList* list, int index, ElemType elem) {
    // 确保顺序表存在
    if (list == NULL || list->elemData == NULL) return ERROR;
    // 判断 index 位置是否合法 (1 < index <= list.length + 1)
    if (index < 1 || index > list->length + 1) return ERROR;

    // 当存储空间达到最大空间时，返回 ERROR
    if (list->length == LIST_MAX_SIZE) return ERROR;

    // 当 length >= size 时，顺序表需要扩容
    if (list->length >= list->size) {
        // size 扩容一倍
        list->size = grow(list->size);
        // 在扩大原有的存储空间
        ElemType* newBase = realloc(list->elemData, sizeof(list->size));
        if (newBase == NULL) {
            // 扩容失败
            exit(OVERFLOW);
        }
        // 顺序表开始地址指向新的存储空间起始地址
        list->elemData = newBase;
    }

    // 从后往前遍历，将 index - 1 右边的元素向右移动一位
    for (int i = list->length - 1; i >= index - 1; i--) {
        // 将 elem[i] 元素赋值给 elem[i+1] 位置，相当于将 elem[i] 元素往后移动一位
        list->elemData[i + 1] = list->elemData[i];
    }
    // 将 elem 元素放到 elemData[index - 1] (i 位置)
    list->elemData[index - 1] = elem;
    // 顺序表长度 + 1
    list->length++;

    return OK;
}

/**
 * 在顺序表的 index 位置插入元素 elem, 插入到 index 下标
 * @param list
 * @param i
 * @param elem
 * @return
 */
Status insertElem2(SqList* list, int index, ElemType elem) {
    // 确保顺序表存在
    if (list == NULL || list->elemData == NULL) return ERROR;
    // 判断 index 位置是否合法 (1 < index <= list.length + 1)
    if (index < 1 || index > list->length + 1) return ERROR;

    // 当存储空间达到最大空间时，返回 ERROR
    if (list->length == LIST_MAX_SIZE) return ERROR;

    // 当 length >= size 时，顺序表需要扩容
    if (list->length >= list->size) {
        // size 扩容一倍
        list->size = grow(list->size);
        // 在扩大原有的存储空间
        ElemType* newBase = realloc(list->elemData, sizeof(list->size));
        if (newBase == NULL) {
            // 扩容失败
            exit(OVERFLOW);
        }
        // 顺序表开始地址指向新的存储空间起始地址
        list->elemData = newBase;
    }

    // 从后往前遍历，将 index 右边的元素向右移动一位
    for (int i = list->length - 1; i >= index; i--) {
        // 将 elem[i] 元素赋值给 elem[i+1] 位置，相当于将 elem[i] 元素往后移动一位
        list->elemData[i + 1] = list->elemData[i];
    }
    // 将 elem 元素放到 elemData[index] (i 位置)
    list->elemData[index] = elem;
    // 顺序表长度 + 1
    list->length++;

    return OK;
}

/**
 * 返回顺序表 index 位置的元素
 * 时间复杂度 O(1)
 * @param list
 * @param index
 * @param elem ElemType 指针，指向 index 位置元素地址
 * @return
 */
Status getElem(SqList* list, int index, ElemType* elem) {
    // 确保顺序表存在
    if (list == NULL || list->elemData == NULL) return ERROR;
    // 判断 index 位置是否合法 (1 <= index <= list.length)
    if (index < 1 || index > list->length) return ERROR;

    // 将 list->elem[index - 1] 地址的值 赋值给 elem (这里是直接赋值)
    *elem = list->elemData[index - 1];

    return OK;
}

/**
 * 删除 index 位置的元素，将删除的元素赋值给 elem
 * 平均时间复杂度 O(n)
 * @param list
 * @param index
 * @param elem
 * @return
 */
Status deleteElem(SqList* list, int index, ElemType* elem) {
    // 确保顺序表存在
    if (list == NULL || list->elemData == NULL) return ERROR;
    // 判断 index 位置是否合法 (1 <= index <= list.length)
    if (index < 1 || index > list->length) return ERROR;

    // 将 index 位置的元素赋值给 elem
    *elem = list->elemData[index - 1];
    // 遍历顺序表，将 index - 1 位置右边(从 index 开始)的元素都往左移一位
    for (int i = index; i < list->length; i++) {
        list->elemData[i - 1] = list->elemData[i];
    }
    // 顺序表最后位置的元素往左移动了一位，将最后的位置值重置为 0
    list->elemData[list->length - 1] = 0;
    // 顺序表长度 - 1
    list->length--;

    return OK;
}

int grow(int currentSize) {
    int newSize = currentSize >> 1;
    if (newSize < 0 || newSize > LIST_MAX_SIZE) {
        return LIST_MAX_SIZE;
    } else {
        return newSize;
    }
}

/**
 * 打印顺序表
 * @param list
 */
void printList(SqList *list) {
    for (int i = 1; i <= list->length; i++) {
        printf("%d ", list->elemData[i]);
    }
    printf("\n");
}