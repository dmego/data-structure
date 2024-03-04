#include <stdio.h>
#include "SeqList.h"

int main() {

    SqList list;

    ElemType elem;

    Status status = initSqList(&list); // 初始化顺序表
    printf("learnClang status: %d\n", status);
    insertElem(&list, 1, 1);
    insertElem(&list, 2, 2);
    insertElem(&list, 3, 3);
    insertElem(&list, 2, 4);


    for (int i = 1; i <= list.length; i++) {
        getElem(&list, i, &elem);
        printf("get elem[%d]: %d\n", i, elem);
    }

    deleteElem(&list, 2, &elem);
    printf("delete elem: %d\n", elem);

    for (int i = 1; i <= list.length; i++) {
        getElem(&list, i, &elem);
        printf("get elem[%d]: %d\n", i, elem);
    }

    destroyList(&list);
}