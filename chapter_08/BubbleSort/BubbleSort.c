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
            if (list->elemData[j - 1] > list->elemData[j]) {
                flag = 1;
                temp = list->elemData[j - 1];
                list->elemData[j - 1] = list->elemData[j];
                list->elemData[j] = temp;
            }
        }
        if (flag == 0) return;
    }
}



int main() {

    // 初始化顺序表，数据为 [49,38,65,97,76,13,27]
    SqList list;
    initSqList(&list);
    insertElem2(&list, 1, 49);
    insertElem2(&list, 2, 38);
    insertElem2(&list, 3, 65);
    insertElem2(&list, 4, 97);
    insertElem2(&list, 5, 76);
    insertElem2(&list, 6, 13);
    insertElem2(&list, 7, 27);
    printf("排序前：\n");
    printList(&list);
    // 排序
    BubbleSort(&list);
    printf("排序后：\n");
    printList(&list);
}