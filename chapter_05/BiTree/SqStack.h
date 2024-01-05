/*======================
  栈的顺序存储结构(顺序栈)
 =======================*/

#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
#include "BiTree.h"

// 宏定义
#define STACK_SIZE 100

/* 顺序栈的元素类型定义 */
typedef BiTree SElemType;

typedef struct {
    SElemType* top;  // 栈顶指针
    SElemType* base; // 栈底指针
    int stackSize;   // 当前已分配的存储空间（元素个数）
} SqStack;

/**
 * 初始化，构造一个空栈
 * @param S
 * @return
 */
Status initStack(SqStack* S);

/**
 * 销毁一个顺序栈(销毁结构)
 * @param S
 * @return
 */
Status destroyStack(SqStack* S);


/**
 * 清空一个顺序栈，只是清理顺序栈存储的数据，不释放内存
 * @param S
 * @return
 */
Status clearStack(SqStack* S);

/**
 * 判断栈时候为空
 * @param S
 * @return
 */
Status stackEmpty(SqStack S);

/**
 * 返回当前栈中包含有效元素的数量
 * @param S
 * @return
 */
int stackLength(SqStack S);

/**
 * 获取栈顶元素，使用 elem 指针接收
 * @param S
 * @param elem
 * @return
 */
Status getTop(SqStack S, SElemType *elem);

/**
 * 元素入栈，将 elem 压入栈顶
 * @param S
 * @param elem
 * @return
 */
Status push(SqStack* S, SElemType elem);

/**
 * 元素出栈，删除栈顶元素，使用 elem 指针接收
 * @param S
 * @param elem
 * @return
 */
Status pop(SqStack* S, SElemType *elem);

/**
 * 从栈底到栈顶遍历输出顺序栈
 * @param S
 * @return
 */
Status stackTraverse(SqStack S);

#endif