#include "SqStack.h"


int main() {

    SqStack stack;
    SElemType elem;
    initStack(&stack);
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);
    stackTraverse(stack);
    getTop(stack, &elem);
    printf("stack top: %d\n", elem);
    pop(&stack, &elem);
    printf("stack pop: %d\n", elem);
    pop(&stack, &elem);
    printf("stack pop: %d\n", elem);
    stackTraverse(stack);

}
