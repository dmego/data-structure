/*
 设C={a1,b1 a2,b2 ,an,bn }为线性表, 采带用头结点的单链表存放，
 设计一个地就算法，将其拆分为两个线性，使得表A={a1,a2,..an}，B={bn ..b2,b1}。
*/

#include "LinkList.h"

/**
 * 遍历线性表 list, 奇数项采用尾插法插入链表 A, 偶数项采用头插法插入链表 B
 *
 */
void splitList(LinkList list, LinkList A, LinkList B) {
    LNode *head = list->next;
    int count = 1;
    // A 链表的 尾指针
    LNode *tailA = A;
    // B 链表的 头指针
    LNode *headB = B;
    while (head != NULL) {
        // 为了防止在插入过程中断链，先用 next 指针保存 head->next
        LNode *next = head->next;
        head->next = NULL;

        // 奇数项
        if (count % 2 == 1) {
            tailA->next = head;
            tailA = tailA->next;
        }
        // 偶数项
        else {
            head->next = headB->next;
            headB->next = head;
        }
        count++;
        head = next;
    }
}



int main() {
    LinkList list;
    initLinkList(&list);
    int num[] = {1,2,3,4,5,6,7,8,9};
    tailCreateListByArray(&list, num, 9);
    printf("linkList :\n");
    printLinkList(list);

    LinkList A;
    initLinkList(&A);
    LinkList B;
    initLinkList(&B);

    splitList(list, A, B);
    printf("A: ");
    printLinkList(A);
    printf("B: ");
    printLinkList(B);

}