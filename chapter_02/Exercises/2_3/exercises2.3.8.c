/*
设 A和 B是两个单链表(带头结点)，其中元素递增有序, 设计一个算法从A和B中的
公共元素产生单链表 C，要求不破坏A、B的结点
 */
#include "LinkList.h"

void generateCFromAB(LinkList A, LinkList B, LinkList C) {
    LNode *headA = A->next;
    LNode *headB = B->next;
    LNode *tailC = C;
    while (headA != NULL && headB != NULL) {
        if (headA->data == headB->data) {
            LNode *node = malloc(sizeof (LNode));
            node->data = headA->data;
            node->next = NULL;

            tailC->next = node;
            tailC = tailC->next;

            headA = headA->next;
            headB = headB->next;
        } else if (headA->data > headB->data) {
            headB = headB->next;
        } else if (headA->data < headB->data) {
            headA = headA->next;
        }
    }
}



int main() {
    LinkList A;
    initLinkList(&A);
    int numA[] = {1,2,3,4,5};
    tailCreateListByArray(&A, numA, 5);
    printf("A :");
    printLinkList(A);

    LinkList B;
    initLinkList(&B);
    int numB[] = {2,3,4,5,6};
    tailCreateListByArray(&B, numB, 5);
    printf("B :");
    printLinkList(B);

    LinkList C;
    initLinkList(&C);
    generateCFromAB(A, B, C);
    printf("C :");
    printLinkList(C);

}