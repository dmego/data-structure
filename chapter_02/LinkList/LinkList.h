/*=========================
 * 线性表的链式存储结构 (单链表)
 =========================*/

/*
 对 首元节点，头结点，头指针的说明：
    首元节点：链表中存储的第一个数据元素的 节点
    头结点：在首元节点前面(prev)的一个节点，头结点的指针域指向 首元节点
    头指针：是指向链表中第一个节点的指针，存在头结点时，指向的是 头结点 地址
 */

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include <stdbool.h>
#include "Status.h"

/* 单链表的元素类型定义 (int 类型的别名) */
typedef int ElemType;

/* 单链表的数据结构 */
typedef struct LNode {
    ElemType data;      // 链表的数据节点(保存的是实际的值而非指针)
    struct LNode *next; // 链表下一个节点的指针(下一个节点也是 LNode 类型，这里保存的是指向下一个节点地址的指针)
} LNode;

/* LinkList 为指向结构体 LNode 的指针类型 (用来定义单链表的头指针) */
typedef LNode *LinkList;


/**
 * 初始化一个带头结点单链表
 */
bool initLinkList(LinkList *list);

/**
 * 返回带头结点单链表的长度
 */
int length(LinkList list);

/**
 * 在单链表 list 的 index 位置插入元素 elem
 */
bool insertElem(LinkList list, int index, ElemType elem);

/**
 * 取出 单链表 list 的 index 位置的元素， 赋值给 elem 指针指向的地址
 */
void getElem(LinkList list, int index, ElemType *elem);

/**
 * 删除 单链表 index 位置的元素，并将删除的元素赋值给 elem
 */
bool deleteElem(LinkList list, int index, ElemType *elem);

/**
 * 在单链表中定位 elem 元素的位置
 */
int locateElem(LinkList list, ElemType elem);

/**
 * 前插法创建一个单链表
 */
bool headCreateList(LinkList *list, int num);

/**
 * 后插法创建一个单链表
 */
bool tailCreateList(LinkList *list, int num);

/**
 * 后插法创建一个单链表，数据来源一个数组
 */
bool tailCreateListByArray(LinkList *list, const int data[], int num);

/**
 * 遍历输出单链表
 */
void printLinkList(LinkList list);


#endif
