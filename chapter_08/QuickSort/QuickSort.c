#include <stdio.h>
#include "SqList.h"

/**
 * 交换 list 中 i 和 j 两个位置的元素
 * @param list
 * @param i
 * @param j
 */
void swap(SqList *list, int i, int j) {
    int temp = list->data[i];
    list->data[i] = list->data[j];
    list->data[j] = temp;
}

/**
 * 双边循环法：对 list 中的 子表 [low, high] 进行一趟排序，返回枢轴下标
 * @param list
 * @param low
 * @param high
 * @return 枢轴下标
 */
int partition1(SqList *list, int low, int high) {
    // 取区间第一个元素为枢轴，并保存置 list[0] 位置
    int pivot = list->data[low];
    list->data[0] = pivot;
    // 循环遍历区间
    while (low < high) {
        // 先从区间从右往左搜索，如果list[high] >= 枢轴元素，符合定义，high--
        while (low < high && list->data[high] >= pivot) high--;
        // 否则，找到第一个小于 pivot 关键字的记录后，将其移动置 low 位置
        list->data[low] = list->data[high];

        // 再从区间从左往右搜索，如果list[low] <= 枢轴元素，符合定义，low++
        while (low < high && list->data[low] <= pivot) low++;
        // 否则，找到第一个大于 pivot 关键字的记录后，将其移动置 high 位置
        list->data[high] = list->data[low];
    }

    // 循环结束之后，low = high = 枢轴位置，将枢轴元素复制到该位置
    list->data[low] = list->data[0];
    // 返回枢轴下标
    return low;
}

/**
 * 单边循环法：对 list 中的 子表 [low, high] 进行一趟排序，返回枢轴下标
 * @param list
 * @param low
 * @param high
 * @return 枢轴下标
 */
int partition2(SqList *list, int low, int high) {
    // 取区间第一个元素为枢轴
    int pivot = list->data[low];
    // mark 表示 小于等于枢轴的区域边界,初始时为枢轴下标
    int mark = low;
    // 遍历区间
    for (int i = low + 1; i <= high; i++) {
        // 如果 list[i] <= pivot, 则将 mark 区间边界扩大一位，将 list[i] 复制进去
        if (list->data[i] <= pivot) {
            // 交换 list[mark + 1] 和 list[i] 元素位置
            swap(list, mark + 1, i);
            // mark 区间边界 + 1
            mark++;
        }
    }
    // 循环结束后，mark 指向小于等于枢轴的区域边界，mark 位置就是枢轴位置, 将 mark 位置与 low 位置元素交换
    swap(list, mark, low);
    return mark;
}

/**
 * 递归对 list 的 [low, high] 区域递归进行排序
 * @param list
 * @param low
 * @param high
 */
void sort(SqList *list, int low, int high) {
    // 当 low == high 时，区域[low, high] 只有一个元素时，所有元素处于正确位置，无须排序，递归结束
    if (low >= high) return;
    // 采用双边循环法，对 [low, high] 区域进行一趟遍历，返回枢轴下标【一趟排序，枢轴元素已处于正确位置】
    int pivotIndex = partition2(list, low, high);
    // 递归对 枢轴左边元素进行排序
    sort(list, low, pivotIndex - 1);
    // 递归对 枢轴右边元素进行排序
    sort(list, pivotIndex + 1, high);
}

/**
 * 快速排序
 * @param list
 * @return
 */
void QuickSort(SqList *list) {
    sort(list, 1, list->length);
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
    QuickSort(&list);
    printf("排序后：\n");
    printList(&list);
}