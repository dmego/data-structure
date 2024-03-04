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
 * 使用筛选法调整堆(假设 list[k + 1, len] 已经是堆，将 list[k, len] 调整为以 list[k] 为根的堆)
 * @param list
 * @param k
 * @param len
 */
void HeapAdjust(SqList *list, int k, int len) {
    // 将要调整的子树的根节点 list[k] 暂存到 list[0]
    list->data[0] = list->data[k];
    /*
      遍历以 list[k] 为根的子树，将该子树调整为堆
      初始时 i = k * 2, 也就是 list[k] 结点的左孩子结点
      增量条件为 i = i * 2, 也就是逐层往下，将所有子树调整为堆
      (如果循环继续的话，下一个 i 将是 list[k] 左孩子的左孩子，或是 list[k] 右孩子的左孩子)
     */
    for (int i = k * 2; i <= len; i *= 2) {
        // 比较 list[k] 左右孩子的大小，保证 list[i] 是左右孩子中的最大值
        if (i + 1 <= len && list->data[i] < list->data[i + 1]) i++;
        // 如果根结点 list[k] 比左右孩子都要大，则不需要进行调整，退出循环
        if (list->data[0] >= list->data[i]) break;
        else {
            // 否则，将 较大值 list[i] 复制到根结点 list[k] 位置
            list->data[k] = list->data[i];
            // k = i, list[k] 表示下一次循环要调整的子树的根结点
            k = i;
        }
    }
    // 循环结束后，将 原始根结点 list[0] 复制到 list[k] 位置
    list->data[k] = list->data[0];
}

/**
 * 建立大根堆
 * 1.将一个无序的序列调整为堆，则需要将这个序列对应的 完全二叉树 的每一棵子树调整为堆
 * 2.以顺序表存储的完全二叉树，[1 ... ⎿2/n⏌] 区间存储的是根结点，[⎿2/n⏌+1 ... n] 区间存储的是叶子结点
 * 3.从 ⎿2/n⏌下标处的结点开始，调用 HeapAdjust 方法调整以该结点为根的子树成为堆，直至下标为 1 的结点。大根堆建立
 * @param list
 */
void BuildMaxHeap(SqList *list) {
    for (int i = list->length / 2; i >= 1; i--) {
        HeapAdjust(list, i, list->length);
    }
}

/**
 * 堆排序
 * @param list
 * @return
 */
void HeapSort(SqList *list) {
    // 建立大根堆
    BuildMaxHeap(list);
    // 遍历待排序 顺序表(大根堆)，进行堆排序
    for (int i = 1; i <= list->length; i++) {
        // 大根堆的根结点 list[1] 为当前顺序表中的最大值，将其移动到以排序顺序正确位置
        swap(list, 1, list->length - i + 1);
        /*
         因为进行了元素交换，待排序序列 堆被破坏，需要重新调整堆
         注意：
            经过前面的元素交换，已排序序列扩大了一位
            待排序的序列由 [1 ... n - i + 1] 缩小为 [1 ... n - i]
            所以调整时，序列的 len 发生了变化
         */
        HeapAdjust(list, 1, list->length - i);
    }

    /*
     // 从后往前遍历
     for (int i = list->length; i > 1; i--) {
        swap(list, 1, i);
        HeapAdjust(list, 1, i - 1);
     }
     */
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
    // 堆排序
    HeapSort(&list);
    printf("排序后：\n");
    printList(&list);
}