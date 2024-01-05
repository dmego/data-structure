#include "LinkQueue.h"

int main() {

    LinkQueue queue;
    QElemType elem;

    InitQueue(&queue);

    EnQueue(&queue, 1);
    EnQueue(&queue, 2);
    EnQueue(&queue, 3);
    TraverseQueue(queue);
    printf("queue length: %d \n", QueueLength(queue));
    DeQueue(&queue, &elem);
    printf("de queue: %d \n", elem);
    EnQueue(&queue, 4);
    printf("queue length: %d \n", QueueLength(queue));
    TraverseQueue(queue);



}