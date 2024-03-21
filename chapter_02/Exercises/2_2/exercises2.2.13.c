/*
【2018 统考真题】给定一个含 n (n >= 1)个整数的数组，请设计一个在时间上尽可能高效的算法
 找出数组中未出现的最小正整数。例如，数组 {-5,3,2,3} 中未出现的最小正整数是 1;
数组 {1,2,3} 中未出现的最小正整数 4 是。
 要求:
    1)给出算法的基本设计思想。
    2)根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
    3)说明所你设计算法的时间复杂度和空间复杂度。
 */
#include "SqList.h"

/*
  定义一个长度为 L-length + 1 的数组
    最小正整数 最小值取 1， 而最大值一定取 L->length + 1 (假设序列中的值从1开始的递增序列)
 */
ElemType findMinPositiveNum(SqList *L) {
    // 定义一个数组，用于存储当前数组下标所代表的正整数在数组中是否有出现
    int num[L->length + 1];
    // 初始化数组元素都为 0
    for (int i = 0; i < L->length + 1; i++) {
        num[i] = 0;
    }
    // 遍历序列，如果序列中的元素在 0 <= e <= L->length 之间，存在到 num 对应下标下
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] > 0 && L->data[i] <= L->length) {
            num[L->data[i]] = 1;
        }
    }
    // 遍历 num 数组，如果对应下标下值不等于 1，则说明这个下标就是最小正整数
    for (int i = 1; i < L->length + 1; i++) {
        if (num[i] == 0) {
            return i;
        }
    }
    // 否则 最小正整数就是最大值 L->length + 1
    return L->length + 1;
}


int main() {

    SqList L;
    InitList(&L);
    ListInsert(&L, 1, -3);
    ListInsert(&L, 2, 5);
    ListInsert(&L, 3, -2);
    ListInsert(&L, 4, 3);
    ListInsert(&L, 5, -1);
    ListInsert(&L, 6, 0);
    ListInsert(&L, 7, 1);
    ListInsert(&L, 8, 4);

    ElemType e;

    e = findMinPositiveNum(&L);

    printf("min positive num: %d\n", e);

}
