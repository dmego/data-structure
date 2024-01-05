#include "KMP.h"

/**
 * 串的模式匹配，Brute-Force 算法
 * 类似于暴力解法
 */
int index_BF(SString S, SString P, int pos) {
    int i = pos; // 主串的 pos 位置开始匹配
    int j = 1;   // 模式串从首字符开始
    // 遍历主串和模式串
    while (i < S[0] && j < P[0]) {
        // 如果主串 i 位置 和 模式串 j 位置下标字符相同
        if (S[i] == S[j]) {
            // 如果遍历到了模式串最后一个字符，说明模式串所有的字符都匹配上了
            if (j == P[0]) {
                // 返回 模式串在主串中匹配的起始位置
                return i - j + 1;
            } else {
                // 否则，主串和模式串的指针右移，继续比较下一位字符
                i++; j++;
            }
        }
        // 如果主串 i 位置和 模式串 j 位置的下标字符不相同
        else {
            // 主串指针回退到 从前一次开始比较的位置右移一位
            i = i - j + 2;
            // 模式串指针回退到 首字符位置
            j = 1;
        }
    }
    // 没有匹配上，返回 -1
    return -1;
}

/**
 * 串的模式匹配，KMP 算法
 */
int index_KMP(SString S, SString P, int pos, int next[]) {
    if (pos < 1) return 0;
    int i = pos; // 从主串的 pos 位置匹配
    int j = 1;   // 从模式串首字符匹配
    while (i <= S[0] && j <= P[0]) {
        // 两种情况：1.在模式串P的首字符位置就失配；2. i 位置和 j 位置字符不匹配
        if (j == 0 || S[i] == P[j]) {
            i++;
            j++;
        } else {
            // 失配时，j 回退到 next[j] 位置
            j = next[j];
        }
    }
    // 如果匹配到了 模式串 最后，说明模式串匹配成功
    if (j > P[0]) {
        // 返回模式串在主串中匹配的起始位置
        return i - P[0];
    }
    return 0;
}

/**
 * KMP 算法，求 next 数组
 * next[j] 表示当模式串在 j 位置失配时，j 需要回溯到 next[j] 位置重新与主串的 i 比较
 */
void get_next(SString P, int next[]) {
/*
     i 表示模式串 T 的中正在处理字符的下标，从 1 开始, (next 数组下标也从 1 开始， 0 位置不使用)
     初始时，i = 1, 表示从模式串的第一个位置开始
     */
    int i = 1;
    /*
     j 表示模式串 T 中当前正在比较的位置，也表示 当前前缀 的后一个字符位置
     初始时，j = 0, 表示当前没有已匹配的前缀
     */
    int j = 0;

    // 模式串第一个字符处失配时，模式串需要从头比较，主串需要前进到下一个位置比较
    // 在 KMP 算法中，当遇到 next 值为 0，时，进行 i++，(主串移动到下一个位置继续比较)
    next[1] = 0;

    // 遍历模式串上的字符
    while(i < P[0]) {
        /*
         1. 当 j == 0 时，说明没有与 当前字符 T[i] 匹配的前缀，则 next[i + 1] = 1，表示在 i + 1 处失配时，j 需要回溯到首字符 1 下标
         2. 当 T[i] = T[j] 时，则 next[i + 1] = j + 1, 表示在 i + 1 失配时，j 回溯到 j + 1 位置即可
         */
        if(j == 0 || P[i] == P[j]) {
            i++;
            j++;
            next[i] = j;
        }
            /*
             3. 当 T[i] != T[j] 时，说明前后缀没有匹配上，需要缩短前后缀的长度
             */
        else {
            j = next[j];
        }
    }
}

/**
 * KMP 算法，求优化后的 next 数组
 */
void get_nextval(SString P, int nextval[]) {
    int i = 1;
    int j = 0;

    // 模式串第一个字符处失配时，模式串需要从头比较，主串需要前进到下一个位置比较
    nextval[1] = 0;

    // 遍历模式串上的字符
    while(i < P[0]) {
        if(j==0 || P[i] == P[j]) {
            i++;
            j++;

            /*
             主串 S[ii] 当前与 P[jj] 比较，T[jj] 失配，则 jj 需要回退到 next[j] 位置
             但是如果 P[next[j]] = P[jj], 则 jj 回退到 next[j] 位置没有必要，因为与主串 S[ii] 还是失配
             需要再往前回退，也就是 jj = next[next[j]] 直到 与 T[jj] 不相等

             当 P[i] = P[j] 时，next[i + 1] 应该等于 j + 1, 也就是当 S[ii] 与 P[i+1] 不匹配时，S[ii] 会与 P[j+1] 匹配
             但是如果 P[i+1] = P[j+1]， S[ii] 再与 P[j+1] 匹配没有意义，所以 next[i + 1] 的值不能等于 j + 1
             需要继续往下找，next[i + 1] = next[j + 1]
            */
            if(P[i] == P[j]) {
                nextval[i] = nextval[j];
            }
            else {
                nextval[i] = j;
            }
        } else {
            j = nextval[j];
        }
    }
}

/**
 * 自己理解实现的 KMP 算法
 * https://writings.sh/post/algorithm-string-searching-kmp#sponsor-start
 */
int KMP(SString S, SString P, int next[]) {
    int i = 1;
    int j = 1;
    while (i <= S[0] && j <= P[0]) {
        if (S[i] == P[j]) {
            if (j == P[0]) {
                return i - j + 1;
            } else {
                i++; j++;
            }
        } else {
            if (j == 1) {
                i++;
            } else {
                // j 回溯到 next[j] 位置
                j = next[j];
            }
        }
    }
    return -1;
}

/**
 * 自己理解实现的 求 next 数组
 * next[j] 表示当 p 在 j 位置失配时，j 需要回溯到 next[j] 位置重新与主串的 i 比较
 */
void computeNext(SString P, int next[]) {
    if (P[0] > 0) next[0] = 1;
    if (P[0] > 1) next[1] = 1;
    int j = 2;
    while (j < P[0]) {
        // 当前字符
        char ch = P[j];
        // 上一个字符 的 next 值
        int last = next[j - 1];
        // 当 当前字符和前一个字符的 next 值处的字符相等时
        if (ch == P[last]) {
            // 当前字符的 next值 在前一个字符的基础上 + 1
            next[j] = last + 1; // next[j - 1]  + 1
        } else {
            // 否则循环找到 当前字符和前一个字符的 next 值处的字符相等 的 next 值
            int k = next[last];
            while (k >= 0 && ch != P[k]) {
                k = next[k];
            }
            // 如果回退到 首节点还没找到，则在 j 位置失配时，j 回退到首节点
            if (k == 0 && ch != P[k]) {
                next[j] = 1;
            } else {
                // 否则，当前字符的 next 值就在 k 值基础上 + 1
                next[j] = k + 1;
            }
        }
        // j++, 继续求下一个字符的 next 值
        j++;
    }
}

/**
 * 自己理解实现的 求 next 数组的简单版本
 */
void simpleComputeNext(SString P, int next[]) {
    if (P[0] > 0) next[0] = 1;
    if (P[0] > 1) next[1] = 1;
    for (int j = 2; j <= P[0]; j++) {
        int k = next[j - 1];
        while(k != 1 && P[j] != P[k]) {
            k = next[k];
        }
        next[j] = 1;
        if (P[j] == P[k]) next[j] = k + 1;
    }
}