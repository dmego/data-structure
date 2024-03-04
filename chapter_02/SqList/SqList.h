/*==================================
 * 线性表的顺序存储结构 (顺序表[静态长度])
 ==================================*/

#ifndef SQLIST_H
#define SQLIST_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// 静态分配顺序表的长度
#define MaxSize 50
// 顺序表的数据元素类型 int
typedef int ElemType;
// 顺序表的结构定义
typedef struct {
    ElemType data[MaxSize];  // 顺序表存储数组
    int length;              // 顺序表长度
} SqList;

void InitList(SqList *L);

void DestroyList(SqList *L);

bool ListInsert(SqList *L, int index, ElemType e);

bool ListDelete(SqList *L, int index, ElemType *e);

int LocateElem(SqList L, ElemType e);

void printList(SqList *list);

#endif