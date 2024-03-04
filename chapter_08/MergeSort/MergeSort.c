#include <stdio.h>
#include "SqList.h"

/**
 * 将 list[low, high] 的前后两个有序表 list[low, mid]、list[mid+1, high] 归并成一个有序表 list[low, high]
 * @param list
 * @param low
 * @param mid
 * @param high
 */
void Merge(SqList *list, SqList *tList, int low, int mid, int high) {
    // 将 list[low, high] 复制到临时顺序表 tList[low, high]
    for (int i = low; i <= high; i++) {
        ListInsert(tList, i, list->data[i]);
    }
    // 遍历临时顺序表 tList，将前后两个子表归并到 原始表 list
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (tList->data[i] <= tList->data[j]) list->data[k++] = tList->data[i++];
        else list->data[k++] = tList->data[j++];
    }
    while (i <= mid) {
        list->data[k++] = tList->data[i++];
    }
    while (j <= high) {
        list->data[k++] = tList->data[j++];
    }
}

/**
 * 采用2路归并的思想，递归对 list[low, high] 进行归并
 * @param list
 * @param low
 * @param high
 */
void MSort(SqList *list, SqList *tList, int low, int high) {
    // 递归结束条件，当 low = high 时，说明需要归并的list子区间只有一个元素，直接返回。
    if (low >= high) return;
    int mid = (low + high) / 2;
    // 递归对 list[low, mid] 区间进行归并排序
    MSort(list, tList, low, mid);
    // 递归对 list[mid + 1, high] 区间进行归并排序
    MSort(list, tList, mid + 1, high);
    // 将 list[low, mid] 和 list[mid+1, high] 两个区间进行 归并
    Merge(list, tList, low, mid, high);
}

/**
 * 归并排序
 * @param list
 * @return
 */
void MergeSort(SqList *list) {
    // 初始化一个临时顺序表
    SqList tList;
    InitList(&tList);
    // 调用 MSort 递归进行2路归并排序
    MSort(list, &tList, 1, list->length);
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
    // 归并排序
    MergeSort(&list);
    printf("排序后：\n");
    printList(&list);
}
