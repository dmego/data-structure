#include <stdio.h>
#include "SqList.h"

/**
 * 希尔排序
 * @param list
 * @return
 */
void ShellInsert(SqList *list) {
    int i, j, dk;
    // 第一层循环，对待排序列表进行分组，dk为当前分组的间隔，最后一次循环时 dk=1，即对整个列表进行直接插入排序
    for (dk = list->length / 2; dk >= 1; dk /= 2) {
        /*
         list[1] 代表第一个分组的第一个元素，在插入排序中，就是属于已排序的部分，待排序的部分是list[dk + 1];
         同理 list[2] 代表第二个分组的第一个元素，在插入排序中，属于已排序的部分，待排序的部分是list[dk + 2];
         第二层循环从 list[dk + 1] 开始，也就是对每个分组待排序部分进行插入排序
         */
        for (i = dk + 1; i <= list->length; i++) {
            /*
             list[i - dk] 就是当前分组已排序部分的最大值
             list[i] 就是当前待排序的元素，如果 list[i] < list[i - dk] 表示 list[i] 需要插入到 list[i - dk] 之前
             */
             if (list->data[i] < list->data[i - dk]) {
                 // 将待排序元素 list[i] 复制到 list[0] 位置
                 list->data[0] = list->data[i];
                 // 第三层循环，进行插入排序
                 for (j = i - dk; j > 0 && list->data[0] < list->data[j]; j -= dk) {
                     // 如果 list[0] < list[j] 则将 list[j] 后移一位
                     list->data[j + dk] = list->data[j];
                 }
                 // 循环结束后 list[j + dk] 的位置就是 list[0] 待插入位置
                 list->data[j + dk] = list->data[0];
            }
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
    // 排序
    ShellInsert(&list);
    printf("排序后：\n");
    printList(&list);
}