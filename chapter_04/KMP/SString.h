/*=======================
  串的定长存存储表示（顺序串）
 =======================*/

#ifndef SSTRING_H
#define SSTRING_H

#include <stdio.h>
#include <string.h>
#include "Status.h"

#define MAXSIZE 255  // 顺序串的最大长度

/*
 顺序串的存储类型定义
 从下标为 1 的位置开始存储，下标为 0 的位置存储顺序串的长度
 */
typedef unsigned char SString[MAXSIZE + 1];

/**
 * 初始化一个顺序串
 */
Status StrAssign(SString T, const char* chars);



#endif SSTRING_H
