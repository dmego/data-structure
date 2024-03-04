#include <stdio.h>
#include "SqList.h"

/**
 * 插入排序
 * @param list
 * @return
 */
void InsertSort(SqList *list) {
    int i, j;
    // 外层循环控制要排序的元素个数, list[0] 是哨兵；list[1] 是初始已排序数组元素，从list[2]开始排序
    for (i = 2; i <= list->length; i++) {
        // 如果当前元素 list[i] 比前一个元素 list[i - 1] 小(list[i - 1] 是已排序列表中最大的元素)，则list[i] 需要插入到 list[1 ~ i] 中间
        if (list->data[i] < list->data[i - 1]) {
            // 将 list[i] 保存到哨兵位置，以便于与后面的元素进行比较
            list->data[0] = list->data[i];
            // 将已排序列表扩大一位(list[i - 1] 元素后移一位)，为新插入的 list[i] 腾出位置
            list->data[i] = list->data[i - 1];
            // 从后往前进行比较，从 list[i - 2] 开始 与当前待排序的元素(哨兵位置list[0]) 进行比较
            // 如果 list[0] < list[j]，说明 list[0] 要插入到 list[j] 之前
            for (j = i - 2; list->data[0] < list->data[j]; j--) {
                // 将 list[j] 后移一位
                list->data[j + 1] = list->data[j];
            }
            // 如果退出循环，则说明 list[0] >= list[j], 说明list[j] 的下一个 list[j + 1] 位置是待排序元素的合适位置
            // 将待排序元素移动到 list[j + 1] 位置
            list->data[j + 1] = list->data[0];
        }
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
    // 插入排序
    InsertSort(&list);
    printf("排序后：\n");
    printList(&list);
}