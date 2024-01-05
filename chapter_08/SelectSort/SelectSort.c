#include <stdio.h>
#include "SqList.h"

void swap(SqList *list, int i, int j) {
    int temp = list->elemData[i];
    list->elemData[i] = list->elemData[j];
    list->elemData[j] = temp;
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
            if (list->elemData[j] < list->elemData[minIndex]) {
                minIndex = j;
            }
        }
        swap(list, i, minIndex);
    }
}

int main() {

    // 初始化顺序表，数据为 [49,38,65,97,49,76,13,27]
    SqList list;
    initSqList(&list);
    insertElem2(&list, 1, 49);
    insertElem2(&list, 2, 38);
    insertElem2(&list, 3, 65);
    insertElem2(&list, 4, 97);
    insertElem2(&list, 5, 49);
    insertElem2(&list, 6, 76);
    insertElem2(&list, 7, 13);
    insertElem2(&list, 8, 27);
    printf("排序前：\n");
    printList(&list);
    // 选择排序
    SelectSort(&list);
    printf("排序后：\n");
    printList(&list);
}
