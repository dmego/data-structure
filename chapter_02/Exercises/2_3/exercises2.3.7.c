/*
在一个递增有序的链单表，中存在重复的元素, 设计算法删除重复的元素,
 例如(7,10,10,21,30,42,42,42,51,70)将变为(7,10,21,30,42,51,70)。
 */
#include "LinkList.h"

void delRepeatEnum(LinkList list) {
    // 以首元结点为头指针
    LNode *head = list->next;
    while (head->next != NULL) {
        if (head->data == head->next->data) {
            LNode *node = head->next;
            head->next = node->next;
            free(node);
        }
        head = head->next;
    }
}



int main() {
    LinkList list;
    initLinkList(&list);
    int num[] = {7,10,10,21,30,42,42,51,70};
    tailCreateListByArray(&list, num, 9);
    printf("before del:\n");
    printLinkList(list);
    delRepeatEnum(list);
    printf("after del:\n");
    printLinkList(list);
}