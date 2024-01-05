#include <stdio.h>
#include "SqList.h"

/**
 * 折半插入排序
 * @param list
 * @return
 */
void BInsertSort(SqList *list) {
    int i, j;
    // 外层循环控制要排序的元素个数, list[0] 是哨兵；list[1] 是初始已排序数组元素，从list[2]开始排序
    for (i = 2; i <= list->length; i++) {
        // 将待排序元素复制到哨兵 list[0] 位置
        list->elemData[0] = list->elemData[i];
        // 利用折半查找，找到待排序元素要插入的位置
        int low = 1, high = i - 1;
        // 循环条件为 low <= high, 循环结束时，一定是 low = high + 1
        while (low <= high) {
            // 计算中间位置
            int mid = (low + high) / 2;
            // 如果 list[0] < list[mid] 说明待排序元素应该插入到 list[mid] 之前位置
            if (list->elemData[0] < list->elemData[mid]) {
                high = mid - 1;
            }
            /*
             这里有两种情况：
             1. 如果 list[0] > list[mid] 说明待排序元素应该插入到 list[mid] 之后位置
             2. 如果 list[0] == list[mid] 说明待排序元素与 list[mid] 相等，为了保证算法的稳定性
             应该继续在 mid 位置后面继续查找，直到找到一个比待排序元素 list[0] 大的元素
             也就是说，循环结束时，一定存在 list[low - 1] <= list[0] < list[low]
             low 位置就是待排序元素应该插入的位置
             */
            else {
                low = mid + 1;
            }
        }
        // 将 low 位置及其后面的元素后移一位
        for (j = i - 1; j >= low; j--) {
            list->elemData[j + 1] = list->elemData[j];
        }
        // 将待排序元素复制到 list[low] 位置
        list->elemData[low] = list->elemData[0];
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
    // 插入排序
    BInsertSort(&list);
    printf("排序后：\n");
    printList(&list);
}