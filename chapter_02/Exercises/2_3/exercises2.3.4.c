/*
设 在一个带表头结点的单表链中，所有结点的元素值无序，试编写一个函数，删除表中
所有介于给定的两个值(作为函数参数给出)之间的元素(若存在)。
 */
#include "LinkList.h"

void delFromList(LinkList list, ElemType A, ElemType B) {
    // head 指向头结点
    LNode *head = list;
    while (head->next != NULL) {
        LNode *curr = head->next;
        if (curr->data > A && curr->data < B) {
            head->next = curr->next;
            free(curr);
        }
        head = head->next;
    }
}



int main() {
    LinkList list;
    initLinkList(&list);
    int num[] = {6,2,3,4,5,1};
    tailCreateListByArray(&list, num, 6);
    printf("before del:\n");
    printLinkList(list);
    delFromList(list, 2,6);
    printf("after del:\n");
    printLinkList(list);
}