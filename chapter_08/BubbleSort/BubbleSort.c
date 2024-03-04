#include <stdio.h>
#include "SqList.h"
/**
 * 冒泡排序
 * @param list
 * @return
 */
void BubbleSort(SqList *list) {
    int i, j, flag, temp;
    for (i = 1; i <= list->length; i++) {
        flag = 0;
        for (j = 2; j <= list->length - i + 1; j++) {
            if (list->data[j - 1] > list->data[j]) {
                flag = 1;
                temp = list->data[j - 1];
                list->data[j - 1] = list->data[j];
                list->data[j] = temp;
            }
        }
        if (flag == 0) return;
    }
}



int main() {

    // 初始化顺序表，数据为 [49,38,65,97,76,13,27]
    SqList list;
    InitList(&list);
    ListInsert(&list, 1, 49);
    ListInsert(&list, 2, 38);
    ListInsert(&list, 3, 65);
    ListInsert(&list, 4, 97);
    ListInsert(&list, 5, 76);
    ListInsert(&list, 6, 13);
    ListInsert(&list, 7, 27);
    printf("排序前：\n");
    printList(&list);
    // 排序
    BubbleSort(&list);
    printf("排序后：\n");
    printList(&list);
}