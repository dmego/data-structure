/*
试编写在带头结点的单链表 L 中删除一个最小值结点的高效算法(假设该结点唯一)
 */

#include "LinkList.h"

void delMinNode(LinkList list) {
    // head 指针指向头结点
    LNode *head = list;
    LNode *minNode = list->next;
    // dummy 结点指向  的前一个结点
    LNode *dummy = list;
    while (head->next != NULL) {
        if (head->next->data < minNode->data) {
            minNode = head->next;
            dummy = head;
        }
        head = head->next;
    }
    // 删除 minNode 结点
    dummy->next = minNode->next;
    free(minNode);
}



int main() {
    LinkList list;
    InitList(&list);
    int num[] = {6,2,3,4,5};
    tailCreateListByArray(&list, num, 5);
    printf("before del:\n");
    printLinkList(list);
    delMinNode(list);
    printf("after del:\n");
    printLinkList(list);
}