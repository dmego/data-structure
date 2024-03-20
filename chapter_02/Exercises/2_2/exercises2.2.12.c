/*
【2013 统考真题】已知一个整数序列A =(a0,a1,...,an)， 其中 0 < ai < n (0 <= i < n)。
 若存在 a(p1) = a(p2) = ... =a(pm) = x, 且m > n/2 (0<=pk<n, 1<=k<=m)，则称 x 为 A 的主元素
 例如 A = (0,5,5,3,5,7,5,5)，则 5 为主元素; 又如 A = (0,5,5,3,5,1,5,7),则 A 中没有主元素。
 假设 A 中 n 个元素保存在一个一维数组中, 请设计一个尽可能高效的算法，找出 A 的主元素, 若存在主元素则输出该元素; 否则输出-1。
 要求:
    1)给出算法的基本设计思想。
    2)根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
    3)说明所你设计算法的时间复杂度和空间复杂度。
 */
#include "SqList.h"


/*
 解法一：摩尔投票法：
 初始序列第一个元素为候选主元素 e, 定义一个 count 变量用来统计 e 出现的次数
 从前往后遍历序列
    如果遍历到的元素 data[i] = e, 则 count++;
    如果遍历到的元素 data[i] != e, 则 count--, 当 count = 0 时，变更候选主元素 e = data[i]

 如果题目描述是主元素一定存在，那么 e 就是主元素

 如果主元素不一定存在，就需要进行验证
    遍历序列，统计 e 出现的次数，如果出现次数满足主元素条件，则返回 e 否则返回 -1

 */
ElemType findMainItem(SqList *L) {
    ElemType main = L->data[0];
    int count = 1;
    for(int i = 1; i < L->length; i++) {
        if (L->data[i] == main) {
            count++;
        } else {
            count--;
            if (count == 0) {
                main = L->data[i];
                count = 1;
            }
        }
    }
    // 校验 e 是否为主元素
    count = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == main) {
            count++;
        }
    }
    if (count > L->length / 2) {
        return main;
    }
    return -1;
}

/*
 解法二：
 1.先排序，再取中间(n/2)的元素
 2.因为主元素不一定存在，所以还需要对主元素 e 进行校验
 3.遍历序列，统计 e 出现的次数，如果出现次数满足主元素条件，则返回 e 否则返回 -1

 注意：这种解法因为排序会导致时间复杂度比第一种高
 */

int main() {
    SqList L;
    InitList(&L);
    ListInsert(&L, 1, 0);
    ListInsert(&L, 2, 5);
    ListInsert(&L, 3, 5);
    ListInsert(&L, 4, 3);
    ListInsert(&L, 5, 5);
    ListInsert(&L, 6, 7);
    ListInsert(&L, 7, 5);
    ListInsert(&L, 8, 5);

    ElemType e;

    e = findMainItem(&L);

    printf("main elem: %d\n", e);

}
