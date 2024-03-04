#include <stdio.h>
#include "SqList.h"

void swap(SqList *list, int i, int j) {
    int temp = list->data[i];
    list->data[i] = list->data[j];
    list->data[j] = temp;
}

/**
 * 选择排序
 * @param list
 * @return
 */
void SelectSort(SqList *list) {
    int i, j, minIndex;
    for (i = 1; i <= list->length; i++) {
        minIndex = i;
        for (j = i + 1; j <= list->length; j++) {
            if (list->data[j] < list->data[minIndex]) {
                minIndex = j;
            }
        }
        swap(list, i, minIndex);
    }
}

int main() {

    // 初始化顺序表，数据为 [49,38,65,97,49,76,13,27]
    SqList list;
    InitList(&list);
    ListInsert(&list, 1, 49);
    ListInsert(&list, 2, 38);
    ListInsert(&list, 3, 65);
    ListInsert(&list, 4, 97);
    ListInsert(&list, 5, 49);
    ListInsert(&list, 6, 76);
    ListInsert(&list, 7, 13);
    ListInsert(&list, 8, 27);
    printf("排序前：\n");
    printList(&list);
    // 选择排序
    SelectSort(&list);
    printf("排序后：\n");
    printList(&list);
}
