#include "BiTree.h"


int main() {
    BiTree T;
    BiTree L;
    BiTree R;

    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = 1;
    L = (BiTree)malloc(sizeof(BiTNode));
    L->data = 2;
    R = (BiTree)malloc(sizeof(BiTNode));
    R->data = 3;
    T->lchild = L;
    T->rchild = R;

    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");
    LevelOrder(T);
    printf("\n");
    InOrder2(T);
    printf("\n");

}