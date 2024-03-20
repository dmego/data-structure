/*
【2010 统考真题】设将 n(n > 1) 个整数存放到一数维组 R 中, 设计一个在时间和空间
 两方面都可尽能高效的算法。将 R 中保存的序列循环 左移 p (0 < p < n) 个位置
 即将 R 中的数据由 (X1,X2,X3,...Xn-1) 变换为(Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1)。
 要求:
    1)给出算法的基本设计思想 。
    2)根据设计思想，采用C 或 C++ 或 Java 语言描述算法，关键之处出给注释。
    3)说明你所设计算法的时间复杂度和空间复杂度。
 */
#include "SqList.h"


// 反转 L[a, b] 区间的元素
void reverse(SqList *L, int a, int b) {
    int i = a, j = b;
    while (i < j) {
        swap(L, i, j);
        i++;
        j--;
    }
}

void leftMove(SqList *L, int p) {
    if (p == 0 || p == L->length) return;
    p = L->length - 1 - p;
    reverse(L, 0, p);
    reverse(L, p + 1, L->length - 1);
    reverse(L, 0, L->length - 1);
}


int main() {
    SqList L;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 4);
    ListInsert(&L, 5, 5);
    ListInsert(&L, 6, 6);
    ListInsert(&L, 7, 7);

    printf("before more: \n");
    printList(L);

    leftMove(&L, 3);
    printf("after move: \n");
    printList(L);
}
