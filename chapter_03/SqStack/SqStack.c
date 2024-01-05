#include "SqStack.h"


/**
 * 初始化，构造一个空栈
 * @param S
 * @return
 */
Status initStack(SqStack* S) {
    if (S == NULL) return ERROR;
    // 栈尾指针 指向 新分配的 存储空间
    S->base = malloc(sizeof(SElemType) * STACK_SIZE);
    if (S->base == NULL) {
        exit(OVERFLOW);
    }
    // 栈顶指针 指向 栈尾指针，表示空栈
    S->top = S->base;
    // 栈的大小设置为初值
    S->stackSize = STACK_SIZE;

    return OK;
}

/**
 * 销毁一个顺序栈(销毁结构)
 * @param S
 * @return
 */
Status destroyStack(SqStack* S) {
    if (S == NULL) return ERROR;
    // 销毁顺序栈 栈底指针指向地址的内存
    free(S->base);
    // 重置栈的 栈顶 栈底 以及栈的大小
    S->base = NULL;
    S->top = NULL;
    S->stackSize = 0;
    return OK;
}


/**
 * 清空一个顺序栈，只是清理顺序栈存储的数据，不释放内存
 * @param S
 * @return
 */
Status clearStack(SqStack* S) {
    if (S->base == S->top) return ERROR;
    // 将栈顶指针 重新指向 栈底指针
    S->top = S->base;
    return OK;
}

/**
 * 判断栈时候为空
 * @param S
 * @return
 */
Status stackEmpty(SqStack S) {
    // 如果栈顶元素 = 栈底元素，说明栈为空
    if (S.base == S.top) {
        return TRUE;
    }
    else return FALSE;
}

/**
 * 返回当前栈中包含有效元素的数量
 * @param S
 * @return
 */
int stackLength(SqStack S) {
    if (S.base == NULL) return 0;
    // 注意：S.top 栈顶指针指向栈顶元素的上一个位置
    return (int)(S.top - S.base);
}

/**
 * 获取栈顶元素，使用 elem 指针接收
 * @param S
 * @param elem
 * @return
 */
Status getTop(SqStack S, SElemType* elem) {
    if (S.base == NULL || S.base == S.top) return ERROR;
    // 注意：S.top 栈顶指针指向栈顶元素的上一个位置
    *elem = *(S.top - 1);
    return OK;
}

/**
 * 元素入栈，将 elem 压入栈顶
 * @param S
 * @param elem
 * @return
 */
Status push(SqStack* S, SElemType elem) {
    // 当栈不存在时，返回 ERROR
    if (S == NULL || S->base == NULL) return ERROR;
    // 将 elem 元素赋值给
    *(S->top) = elem;
    // 栈顶指针往前移动一位
    S->top++;
    return OK;
}

/**
 * 元素出栈，删除栈顶元素，使用 elem 指针接收
 * @param S
 * @param elem
 * @return
 */
Status pop(SqStack* S, SElemType *elem) {
    // 当栈不存在时，返回 ERROR
    if (S == NULL || S->base == NULL) return ERROR;
    // 将栈顶元素的值赋值给 elem 指向的地址
    *elem = *(S->top - 1);
    // 栈顶指针往下移动一位，删除栈顶元素
    S->top--;
    return OK;
}

/**
 * 从栈底到栈顶遍历输出顺序栈
 * @param S
 * @return
 */
Status stackTraverse(SqStack S) {
    if (S.base == NULL) return ERROR;
    SElemType* p = S.base;
    while (p < S.top) {
        printf("%d ", *p);
        p++;
    }
    printf("\n");
    return OK;
}