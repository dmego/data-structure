#include "BiThrTree.h"


int main() {

    ThreadTree T;
    ThreadTree L;
    ThreadTree R;

    T = (ThreadTree)malloc(sizeof(ThreadNode));
    T->data = 1;
    L = (ThreadTree)malloc(sizeof(ThreadNode));
    L->data = 2;
    R = (ThreadTree)malloc(sizeof(ThreadNode));
    R->data = 3;
    T->lchild = L;
    T->rchild = R;

    CreateInThread(T);
    InOrder(T);

};