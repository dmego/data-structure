/*==============================
 字符串模式匹配相关算法
 ==============================*/

#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
#include "SString.h"


/**
 * 串的模式匹配，Brute-Force 算法
 * 类似于暴力解法
 */
int index_BF(SString S, SString P, int pos);

/**
 * 串的模式匹配，KMP 算法
 */
int index_KMP(SString S, SString P, int pos, int next[]);

/**
 * KMP 算法，求 next 数组
 */
void get_next(SString P, int next[]);

/**
 * KMP 算法，求优化后的 next 数组
 */
void get_nextval(SString P, int next[]);

/**
 * 自己理解实现的 KMP 算法
 */
int KMP(SString S, SString P, int next[]);

/**
 * 自己理解实现的 求 next 数组
 */
void computeNext(SString P, int next[]);

/**
 * 自己理解实现的 求 next 数组的简单版本
 */
void simpleComputeNext(SString P, int next[]);


#endif KMP_H