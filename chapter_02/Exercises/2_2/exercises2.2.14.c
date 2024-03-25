/*
【2020 统考真题] 定义三元组(a,b,c)(a,b,c均为整数)的距离 D =|a - b| + |b - c| + |c - a|
 给定3个非空整数集合 L1, L3, S3，按升序分存别储在3个数组中。请设计一个尽可能高效的算法，
 计算并输出所有可能的三元组(a,b,c)(a∊L1，b∊L3，c∊S3)中的最小距离。
 例如 L1= {-1,0,9}，L3 = {-25,-10,10,11}，S3 = {2,9,17,30,41}， 则最距小离为 2， 相应的三元组为 (9,10,9)。
 要求:
    1)给出算法的基本设计思想。
    2)根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
    3)说明所你设计算法的时间复杂度和空间复杂度。
 */
#include "SqList.h"
#define INT_MAX 0x7fffffff


// 返回绝对值
int abs(int e) {
    if (e < 0) return -e;
    else return e;
}

// 判断三个数zho a 是否是最小数
bool judgeMin(int a, int b, int c) {
    if (a <= b && a <= c) return true;
    else return false;
}

/*
 * D =|a - b| + |b - c| + |c - a|
 */
int findMinDistance(SqList *L1, SqList *L2, SqList *L3) {
    int min = INT_MAX;
    int i = 0, j = 0, k = 0;
    while (i < L1->length && j < L2->length && k < L3->length) {
        // 计算 D =|a - b| + |b - c| + |c - a|
        int des = abs(L1->data[i] - L2->data[j]) + abs(L2->data[j] - L3->data[k]) + abs(L3->data[k] - L1->data[i]);
        // 更新 min 值
        min = des < min ? des : min;
        if (min == 0) return min;
        // 将 a , b, c 当中的最小值更新，继续循环算距离 D
        if (judgeMin(L1->data[i], L2->data[j], L3->data[k]) && i < L1->length) {
            i++;
        } else if (judgeMin(L2->data[j], L1->data[i], L3->data[k]) && j < L2->length) {
            j++;
        } else if (judgeMin(L3->data[k], L2->data[j], L1->data[i]) &&  k < L3->length){
            k++;
        }
    }
    return min;
}


int main() {

    SqList L1;
    InitList(&L1);
    ListInsert(&L1, 1, -1);
    ListInsert(&L1, 2, 0);
    ListInsert(&L1, 3, 2);
    ListInsert(&L1, 4, 3);
    ListInsert(&L1, 5, 9);

    SqList L2;
    InitList(&L2);
    ListInsert(&L2, 1, 1);
    ListInsert(&L2, 2, 5);
    ListInsert(&L2, 3, 6);
    ListInsert(&L2, 4, 7);
    ListInsert(&L2, 5, 8);

    SqList L3;
    InitList(&L3);
    ListInsert(&L3, 1, 4);
    ListInsert(&L3, 2, 10);
    ListInsert(&L3, 3, 17);
    ListInsert(&L3, 4, 30);
    ListInsert(&L3, 5, 41);

    int min = findMinDistance(&L1, &L2, &L3);
    printf("min distance: %d\n", min);
}
