#include "KMP.h"

// 测试函数，打印字符串
void PrintElem(SString S) {
    int i;

    for(i = 1; i <= S[0]; i++) {
        printf("%c", S[i]);
    }

    printf("\n");
}


int main() {
    char* s = "abaaabcaabaabcacabaabcaabaabcac";
    char* t = "abaabcac";

    SString S, P;
    int* next;      // 模式串的next函数值
    int* nextval;   // 模式串的nextval函数值
    int* simpleNext;

    StrAssign(S, s);                    // 初始化主串
    printf("S       = ");
    PrintElem(S);

    StrAssign(P, t);                    // 初始化模式串
    printf("T       = ");
    PrintElem(P);


    // 注：next数组和nextval数组的0号单元是弃用的，从1号单元开始存储有效数据
    next    = (int*) malloc((P[0] + 1) * sizeof(int));
    nextval = (int*) malloc((P[0] + 1) * sizeof(int));
    simpleNext = (int*) malloc((P[0] + 1) * sizeof(int));

    get_next(P, next);
    get_nextval(P, nextval);
    simpleComputeNext(P, simpleNext);

    printf("next    : ");
    for(int i = 1; i <= P[0]; i++) {
        printf("%d", next[i]);
    }
    printf("\n");

    printf("nextval : ");
    for(int i = 1; i <= P[0]; i++) {
        printf("%d", nextval[i]);
    }
    printf("\n");

    printf("simpleNext : ");
    for(int i = 1; i <= P[0]; i++) {
        printf("%d", simpleNext[i]);
    }
    printf("\n");


    int in1 = index_KMP(S, P, 1, next);
    int in2 = index_KMP(S, P, 1, nextval);
    int in3 = KMP(S, P, simpleNext);

    printf("T 在 S 中第一次匹配成功的位置为 %d\n", in1);
    printf("T 在 S 中第一次匹配成功的位置为 %d\n", in2);
    printf("T 在 S 中第一次匹配成功的位置为 %d\n", in3);

}