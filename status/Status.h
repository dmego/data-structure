//
// Created by dmego on 2023/10/23.
//

#ifndef STATUS_H
#define STATUS_H

/* 状态码 */
#define OK 1;     // 通过/成功
#define ERROR 0;  // 不通过/失败
#define TRUE 1;   // 真/是
#define FALSE 0;  // 假/否

#ifndef OVERFLOW
#define OVERFLOW -2 // 堆栈上溢
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

/* 状态码类型 */
typedef int Status;

/* 布尔类型 */
typedef int Boolean;

#endif //STATUS_H