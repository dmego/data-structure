#include "SqQueue.h"

/**
 * 初始化一个空的循环队列
 * @param Q
 * @return
 */
Status InitQueue(SqQueue* Q) {
    if (Q == NULL) return ERROR;
    // Q.base 指向 新申请的一块内存区域
    Q->base = malloc(sizeof(QElemType) * QUEUE_MAX_SIZE);
    if (Q->base == NULL) {
        exit(OVERFLOW);
    }
    // front 和 rear 都指向 0，队列置空
    Q->front = Q->rear = 0;
    return OK;
}

/**
 * 销毁一个队列（释放内存）
 * @param Q
 * @return
 */
Status DestroyQueue(SqQueue* Q) {
    if (Q == NULL || Q->base == NULL) return ERROR;
    free(Q->base);

    Q->base = NULL;
    Q->front = Q->rear = 0;
    return OK;
}

/**
 * 将循环队列置空
 * @param Q
 * @return
 */
Status ClearQueue(SqQueue* Q) {
    if (Q == NULL || Q->base == NULL) return ERROR;
    Q->front = Q->rear = 0;
    return OK;
}

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
Status QueueEmpty(SqQueue Q) {
    // 如果队列头指针指向队列尾指针，队列为空
    if (Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 返回队列的长度
 * @param Q
 * @return
 */
int QueueLength(SqQueue Q) {
    if (Q.base == NULL) return 0;
    return (Q.rear - Q.front + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
}

/**
 * 取队列的头节点
 * @param Q
 * @param elem
 * @return
 */
Status GetHead(SqQueue Q, QElemType* elem) {
    // 队列不存在或队列为空，返回 ERROR
    if (Q.base == NULL || Q.front == Q.rear) return ERROR;
    *elem = Q.base[Q.front];
    return OK;
}

/**
 * 出队(删除队头元素)
 * @param Q
 * @param elem
 * @return
 */
Status DeQueue(SqQueue* Q, QElemType* elem) {
    if (Q == NULL || Q->base == NULL) return ERROR;
    // 队列为空
    if (Q->front == Q->rear) return ERROR;
    // 保存队头元素
    *elem = Q->base[Q->front];
    // 头指针 + 1
    Q->front = (Q->front + 1) % QUEUE_MAX_SIZE;
    return OK;
}

/**
 * 入队(在队尾入队元素)
 * @param Q
 * @param elem
 * @return
 */
Status EnQueue(SqQueue* Q, QElemType elem) {
    if (Q == NULL || Q->base == NULL) return ERROR;
    // 判断队列是否已满
    if ((Q->rear + 1) % QUEUE_MAX_SIZE == Q->front) return ERROR;
    // 新元素添加到队尾
    Q->base[Q->rear] = elem;
    // 队尾指针 + 1 (计算得到新的队尾指针)
    Q->rear = (Q->rear + 1) % QUEUE_MAX_SIZE;
    return OK;
}

/**
 * 遍历一个队列
 * @param Q
 * @return
 */
Status TraverseQueue(SqQueue Q) {
    // 从头节点开始遍历，遍历到尾节点
    if (Q.base == NULL || Q.rear == Q.front) return ERROR;
    for (int i = Q.front; i != Q.rear; i = (i + 1) % QUEUE_MAX_SIZE) {
        printf("%d ", Q.base[i]);
    }
    printf("\n");
    return OK;
}