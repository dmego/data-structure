/*

 */

#include "LinkList.h"

void delXFromList(LinkList list, ElemType x) {
    // 指向头结点的头指针
    LNode *head = list;
    LNode *curr;
    while (head->next != NULL) {
        // 当前遍历到的结点
        curr = head->next;
        // 如果当前结点值 = x, 则需要删除
        if (curr->data == x) {
            // 将 head 的 next 执行 curr 的 next
            head->next = curr->next;
            // 删除当前结点
            free(curr);
        }
        // head 往后移动
        head = head->next;
    }
}



int main() {

    LinkList list;
    InitList(&list);
    int num[] = {1,2,3,4,5,3,2,4};
    tailCreateListByArray(&list, num, 8);
    printf("before del:\n");
    printLinkList(list);
    delXFromList(list, 3);
    printf("after del:\n");
    printLinkList(list);
}