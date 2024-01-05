#include "LinkQueue.h"

/**
 * 初始化一个空的队列
 * @param Q
 * @return
 */
Status InitQueue(LinkQueue* Q) {
    // 初始化一个节点作为头结点
    Q->front = Q->rear = malloc(sizeof(QNode));
    if (Q->front == NULL) {
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
    return OK;
}

/**
 * 销毁一个队列（释放内存）
 * @param Q
 * @return
 */
Status DestroyQueue(LinkQueue* Q) {
    if (Q == NULL || Q->front == NULL) return ERROR;
    // 遍历删除链队列中所有的节点
    while (Q->front != NULL) {
        QNode* next = Q->front->next;
        free(Q->front);
        Q->front = next;
    }
    Q->front = Q->rear = NULL;
    return OK;
}

/**
 * 将队列置空(释放非头节点的空间，只保留头结点)
 * @param Q
 * @return
 */
Status ClearQueue(LinkQueue* Q) {
    if (Q == NULL || Q->front == NULL) return ERROR;
    Q->rear = Q->front->next;
    while (Q->rear != NULL) {
         Q->front->next = Q->rear->next;
         free(Q->rear);
         Q->rear = Q->front->next;
    }
    Q->rear = Q->front;
    return OK;
}

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
Status QueueEmpty(LinkQueue Q) {
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
int QueueLength(LinkQueue Q) {
    int size = 0;
    if (Q.front == NULL) return size;
    QNode* node = Q.front->next;
    while (node != NULL) {
        size++;
        node = node->next;
    }
    return size;
}

/**
 * 取队列的第一个节点
 * @param Q
 * @param elem
 * @return
 */
Status GetHead(LinkQueue Q, QElemType* elem) {
    if (Q.front == NULL || Q.front == Q.rear) return ERROR;
    *elem = Q.front->next->data;
    return OK;
}

/**
 * 出队(删除队头元素)
 * @param Q
 * @param elem
 * @return
 */
Status DeQueue(LinkQueue* Q, QElemType* elem) {
    if (Q == NULL || Q->front == NULL) return ERROR;
    // 队列为空
    if (Q->front == Q->rear) return ERROR;
    QNode* temp = Q->front->next;
    *elem = temp->data;
    Q->front->next = temp->next;
    // 如果队列中只有一个元素，删除后，让尾指针也指向头节点
    if (Q->rear == temp) {
        Q->rear = Q->front;
    }
    // 释放头元素的内存
    free(temp);
    return OK;
}

/**
 * 入队(在队尾入队元素)
 * @param Q
 * @param elem
 * @return
 */
Status EnQueue(LinkQueue* Q, QElemType elem) {
    if (Q == NULL || Q->front == NULL) return ERROR;
    QNode* node = malloc(sizeof(QNode));
    if (node == NULL) {
        exit(OVERFLOW);
    }
    node->data = elem;
    node->next = NULL;
    // 将新节点插入到队尾
    Q->rear->next = node;
    // 将尾指针指向新节点
    Q->rear = node;
    return OK;
}

/**
 * 遍历一个队列
 * @param Q
 * @return
 */
Status TraverseQueue(LinkQueue Q) {
    if (Q.front == NULL) return ERROR;
    QNode* node = Q.front->next;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    return OK;
}