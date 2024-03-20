/*
【2011 统考真题】一 个长度为 L (L >= 1)的升序序列 S， 处在第[L/2]个位置的数称为 S 的中位数.
 例如若序列 S1=(11,13,15,17.19)，则S1的中位数是 15，两个序列的中位数是含它们所有元素升序序列的中位数.
 例如, 若 S2=(2,4,6.8,20)，则 S1 和 S2 的中位数是 11。
 现在有两个等长升序序列 A 和 B，试设计一个在时间和空间两方面都可尽能高效的算法，找出两个序列 A 和 B 的中位数
 要求:
    1)给出算法的基本设计思想。
    2)根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
    3)说明所你设计算法的时间复杂度和空间复杂度。
 */
#include "SqList.h"


void findMidFromTwoList(SqList *S1, SqList *S2, ElemType *mid) {
    int len = S1->length;
    int i = 0, j = 0;
    int k = 0;
    // 类似两个序列合并，但是不实现合并，而是只存储比较得到的元素
    ElemType value;
    while (i < len && j < len) {
        if (S1->data[i] <= S2->data[j]) {
            value = S1->data[i];
            i++;
        } else {
            value = S2->data[j];
            j++;
        }
        // 两个序列合并之后，中位数所在的下标 为 len - 1
        if (k == len - 1) {
            *mid = value;
            return;
        }
        k++;
    }

    while (i < len) {
        value = S1->data[i];
        i++;
        if (k == len - 1) {
            *mid = value;
            return;
        }
        k++;
    }

    while (j < len) {
        value = S2->data[j];
        j++;
        if (k == len - 1) {
            *mid = value;
            return;
        }
        k++;
    }

}


int main() {
    SqList S1;
    InitList(&S1);
    ListInsert(&S1, 1, 3);
    ListInsert(&S1, 2, 4);
    ListInsert(&S1, 3, 6);
    ListInsert(&S1, 4, 7);
    ListInsert(&S1, 5, 9);

    SqList S2;
    InitList(&S2);
    ListInsert(&S2, 1, 1);
    ListInsert(&S2, 2, 2);
    ListInsert(&S2, 3, 5);
    ListInsert(&S2, 4, 8);
    ListInsert(&S2, 5, 10);

    ElemType mid;

    findMidFromTwoList(&S1, &S2, &mid);
    printf("mid: %d\n", mid);
}
