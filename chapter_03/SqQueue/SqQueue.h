/*=========================
 队列的顺序存储结构(顺序队列)
 ========================*/

#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

/*
队列：
    每当有元素入队时，队尾指针 rear + 1 (往前移动一位) ,始终指向队尾元素的下一个元素
    每当有元素出队时，队头指针 front + 1 (往前移动一位)，始终指向队头元素
    存在溢出问题（头指针移动到了尾指针前面，尾指针移动）
循环队列（解决溢出问题）：
    入队时，新队尾下标：Q.rear = (Q.rear + 1) % size
    如何判断队列为空或满了
    1. 少用一个元素(队列容量 m - 1):
        判断队空：rear = front
        判断队满：(Q.rear + 1) % size = front
    2. 另外设置一个标志位来判断队空和队满
 */

// 宏定义
#define QUEUE_MAX_SIZE 100

/* 循环队列的元素类型定义 */
typedef int QElemType;

/* 循环队列结构体 */
typedef struct {
    QElemType* base; // 队列存储空间的基地址
    int front;       // 队列头指针
    int rear;        // 队列尾指针
} SqQueue;

/**
 * 初始化一个空的循环队列
 * @param Q
 * @return
 */
Status InitQueue(SqQueue* Q);


/**
 * 销毁一个队列（释放内存）
 * @param Q
 * @return
 */
Status DestroyQueue(SqQueue* Q);

/**
 * 将循环队列置空
 * @param Q
 * @return
 */
Status ClearQueue(SqQueue* Q);

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
Status QueueEmpty(SqQueue Q);

/**
 * 返回队列的长度
 * @param Q
 * @return
 */
int QueueLength(SqQueue Q);

/**
 * 取队列的头节点
 * @param Q
 * @param elem
 * @return
 */
Status GetHead(SqQueue Q, QElemType* elem);

/**
 * 出队(删除队头元素)
 * @param Q
 * @param elem
 * @return
 */
Status DeQueue(SqQueue* Q, QElemType* elem);

/**
 * 入队(在队尾入队元素)
 * @param Q
 * @param elem
 * @return
 */
Status EnQueue(SqQueue* Q, QElemType elem);

/**
 * 遍历一个队列
 * @param Q
 * @return
 */
Status TraverseQueue(SqQueue Q);

#endif SQQUEUE_H