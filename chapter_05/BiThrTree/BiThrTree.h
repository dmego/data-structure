/*=================
 * 线索二叉树
 *================*/

#ifndef BITHRTREE_H
#define BITHRTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 线索二叉树的元素类型定义*/
typedef int TElemType;

/* 线索二叉树的数据结构定义*/
typedef struct ThreadNode {
    TElemType data;                      // 数据元素
    struct ThreadNode *lchild, *rchild;  // 左、右孩子指针
    int ltag, rtag;                      // 左、右线索标志
} ThreadNode;

/* 指向线索二叉树的指针*/
typedef ThreadNode *ThreadTree;

void InThread(ThreadTree p, ThreadNode **pre);

void CreateInThread(ThreadTree T);

ThreadNode* InFirstNode(ThreadNode *p);

ThreadNode* InNextNode(ThreadNode *p);

void InOrder(ThreadTree T);

void Visit(ThreadTree T);


#endif BITHRTREE_H