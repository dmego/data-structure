/*
给定三个序列 A、B、C 长度均为 n，且均为无重复元素的递增序列，请设计一个时间上可尽能高效的算法，
逐行输出同时存在于这三个序列中的所有元素，例如数组 A 为[1,2,3]，数组 B 为 [2,3,4]，数组 C 为[-1,0,2]，则输出 2。
要求:
    1)给出算法的基本设计思想。
    2)根据设计思想，采用C 或 C++ 语言描述算法，关键之处给出注释。
    3)说明你的算法的间时复杂度和空间复杂度
 */
#include "SqList.h"

void printSameItem(SqList *A, SqList *B, SqList *C) {
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length && k < C->length) {
        if (A->data[i] == B->data[j] && B->data[j] == C->data[k]) {
            printf("simple item: %d\n", A->data[i]);
            i++; j++; k++;
        } else {
            // 找到三个元素中的最大值
            ElemType temp = A->data[i] > B->data[j] ? A->data[i] : B->data[j];
            ElemType max =  temp > C->data[k] ? temp : C->data[k];

            if (A->data[i] < max) {
                i++;
            }
            if (B->data[j] < max) {
                j++;
            }
            if (C->data[k] < max) {
                k++;
            }
        }
    }
}


int main() {

    SqList A;
    InitList(&A);
    ListInsert(&A, 1, 1);
    ListInsert(&A, 2, 2);
    ListInsert(&A, 3, 3);
    SqList B;
    InitList(&B);
    ListInsert(&B, 1, 2);
    ListInsert(&B, 2, 3);
    ListInsert(&B, 3, 4);
    SqList C;
    InitList(&C);
    ListInsert(&C, 1, -1);
    ListInsert(&C, 2, 0);
    ListInsert(&C, 3, 2);

    printSameItem(&A, &B, &C);

}
