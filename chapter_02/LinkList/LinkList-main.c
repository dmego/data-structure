#include "LinkList.h"



int main() {

    LinkList list;
    ElemType elem;

    initLinkList(&list);

    //headCreateList(&list, 5);

    //printLinkList(list);

    LinkList list2;
    initLinkList(&list2);
    tailCreateList(&list2, 5);

    printLinkList(list2);

//    insertElem(list, 1, 1);
//
//    Status res = getElem(list, 2, &elem);
//    if (res) {
//        printf("get elem: %d\n", elem);
//    } else {
//        printf("get elem return error\n");
//    }
//
//    res = deleteElem(list, 1, &elem);
//    if (res) {
//        printf("delete elem: %d\n", elem);
//    } else {
//        printf("delete elem return error\n");
//    }
//    res = getElem(list, 1, &elem);
//    if (res) {
//        printf("get elem: %d\n", elem);
//    } else {
//        printf("get elem return error\n");
//    }
//
//    int locate = locateElem(list, 1);
//    printf("locate 1: %d\n", locate);
//
//    insertElem(list, 1, 3);
//    locate = locateElem(list, 1);
//    printf("locate 1: %d\n", locate);
//    locate = locateElem(list, 3);
//    printf("locate 3: %d\n", locate);
}