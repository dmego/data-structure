/*=======================
  队列的链式存储结构(链队列)
 =======================*/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

/* 链队列的元素类型 */
typedef int QElemType;

/* 链队列的链表节点类型 */
typedef struct QNode {
    QElemType data;
    struct QNode* next;
}QNode, *NodePtr;

/* 链队列的数据结构 */
typedef struct {
    NodePtr front;  // 队头指针
    NodePtr rear;   // 队尾指针
} LinkQueue;

/**
 * 初始化一个空的队列
 * @param Q
 * @return
 */
Status InitQueue(LinkQueue* Q);


/**
 * 销毁一个队列（释放内存）
 * @param Q
 * @return
 */
Status DestroyQueue(LinkQueue* Q);

/**
 * 将循环队列置空
 * @param Q
 * @return
 */
Status ClearQueue(LinkQueue* Q);

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
Status QueueEmpty(LinkQueue Q);

/**
 * 返回队列的长度
 * @param Q
 * @return
 */
int QueueLength(LinkQueue Q);

/**
 * 取队列的头节点
 * @param Q
 * @param elem
 * @return
 */
Status GetHead(LinkQueue Q, QElemType* elem);

/**
 * 出队(删除队头元素)
 * @param Q
 * @param elem
 * @return
 */
Status DeQueue(LinkQueue* Q, QElemType* elem);

/**
 * 入队(在队尾入队元素)
 * @param Q
 * @param elem
 * @return
 */
Status EnQueue(LinkQueue* Q, QElemType elem);

/**
 * 遍历一个队列
 * @param Q
 * @return
 */
Status TraverseQueue(LinkQueue Q);




#endif LINKQUEUE_H