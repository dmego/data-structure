/*
 试编写算法将带头结点的单表链就地逆置，所谓“就”地是指辅助空间复杂度为O(1)。
 */
#include "LinkList.h"

void reverseList(LinkList list) {
    // 头指针指向头结点
    LNode *head = list;
    // node 表示要逆置结点的前一个结点 (首元结点不用逆置，node 指向首元结点)
    LNode *node = list->next;
    while (node->next != NULL) {
        // 先将 curr 从链表中断开
        LNode *curr = node->next;
        node->next = curr->next;
        // 再将 curr 插入到最前面
        curr->next = head->next;
        head->next = curr;

        // 注意 node 结点经过逆置后，已经处于正确位置 不用执行 node = node->next

    }
}

int main() {
    LinkList list;
    InitList(&list);
    int num[] = {1,2,3,4,5};
    tailCreateListByArray(&list, num, 5);
    printf("before:\n");
    printLinkList(list);
    reverseList(list);
    printf("after:\n");
    printLinkList(list);
}