/*==================================
 * 线性表的顺序存储结构 (顺序表[动态长度])
 ==================================*/

#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit 原型
#include "Status.h"

/* 宏定义 */
#define LIST_INIT_SIZE 10              // 顺序表的初始化长度
#define LIST_MAX_SIZE  (INT32_MAX - 1) // 顺序表的最大存储长度

/* 顺序表的元素类型定义 (int 类型的别名) */
typedef int ElemType;

/* 顺序表存储的元素结构 */
typedef struct {
    ElemType* elemData;  // 顺序表存储空间的起始地址(动态分配)
    // ElemType elemData[LIST_INIT_SIZE]; 静态分配
    int length;          // 当前顺序表的长度，包含多少元素
    int size;            // 当前顺序表的存储容量，可以存储多少元素
} SqList;

/**
 * 初始化一个顺序表
 * @param list
 * @return 初始化成功返回 Ok 否则返回 false
 */
Status initSqList(SqList *list);

/**
 * 销毁一个顺序表( free 存储空间)
 * @param list
 * @return
 */
Status destroyList(SqList *list);


/**
 * 在顺序表的 index 位置插入元素 elem
 * @param list
 * @param i
 * @param elem
 * @return
 */
Status insertElem(SqList* list, int index, ElemType elem);

/**
 * 在顺序表的 index 位置插入元素 elem, 插入到 index 下标
 * @param list
 * @param i
 * @param elem
 * @return
 */
Status insertElem2(SqList* list, int index, ElemType elem);


/**
 * 返回顺序表 index 位置的元素
 * @param list
 * @param index
 * @param elem ElemType 指针，指向 index 位置元素地址
 * @return
 */
Status getElem(SqList* list, int index, ElemType* elem);


/**
 * 删除 index 位置的元素，将删除的元素赋值给 elem
 * @param list
 * @param index
 * @param elem
 * @return
 */
Status deleteElem(SqList* list, int index, ElemType* elem);

/**
 * 顺序表扩容
 * @param size
 * @return
 */
int grow(int size);

/**
 * 打印顺序表
 * @param list
 */
void printList(SqList *list);

#endif
