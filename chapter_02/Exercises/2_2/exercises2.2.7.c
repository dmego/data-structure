/*
已知在一维数组 A[m + n] 中依次存放两个线性表(a1,a2,a3 ... am) 和 (b1,b2,b3...bn)。
 编写一个函数,将数组中两个顺表序的位置互换,即将 (b1,b2,b3...bn) 放在 (a1,a2,a3 ... am) 的前面
 */
#include "SqList.h"

/**
 * 倒置 List[a, b] 区间的元素
 */
void reverseList(SqList *L, int a, int b) {
    if (a >= b) return;
    int i = a;
    int j = b;
    while (i < j) {
        swap(L, i, j);
        i++;
        j--;
    }
}

/**
 * List = [1,2,3,4,5,6,7], m = 3, n = 4
 * 倒置 List[0,m + n - 1]  = [7,6,5,4,3,2,1]
 * 倒置 List[0,n - 1]      = [4,5,6,7,3,2,1]
 * 倒置 List[n, m + n - 1] = [4,5,6,7,1,2,3]
 */
void switchListPosition(SqList *A, int m, int n) {
    reverseList(A, 0, m + n - 1);
    reverseList(A, 0, n - 1);
    reverseList(A, n, m + n - 1);
}


int main() {

    SqList A;
    InitList(&A);
    ListInsert(&A, 1, 1);
    ListInsert(&A, 2, 2);
    ListInsert(&A, 3, 3);
    ListInsert(&A, 4, 4);
    ListInsert(&A, 5, 5);
    ListInsert(&A, 6, 6);
    ListInsert(&A, 7, 7);

    printf("before: \n");
    printf("A: ");
    printList(A);

    switchListPosition(&A, 3, 4);
    printf("after: \n");
    printf("A: ");
    printList(A);
}
