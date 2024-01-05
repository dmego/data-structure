#include "BiTree.h"
#include "LinkQueue.h"
#include "SqStack.h"

/**
 * 构建二叉树
 * @param T
 * @return
 */
Status CreateBiTree(BiTree* T) {

}


/**
 * 先序遍历二叉树(递归)
 * @param T
 * @return
 */
Status PreOrder(BiTree T) {
    if (T != NULL) {
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    return OK;
}

/**
 * 先序遍历二叉树(非递归)
 * @param T
 * @return
 */
Status PreOrder2(BiTree T) {

}

/**
 * 中序遍历二叉树(递归)
 * @param T
 * @return
 */
Status InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
    return OK;
}

/**
 * 中序遍历二叉树(非递归)
 * @param T
 * @return
 */
Status InOrder2(BiTree T) {
    if (T == NULL) {
        printf("二叉树为空\n");
        return OK;
    }
    SqStack S;
    BiTree elem;
    // 初始化一个栈
    initStack(&S);
    // 当 树不为空 或者 栈不为空 时
    while (T != NULL || !stackEmpty(S)) {
        // 循环将树的左结点入栈
        while (T != NULL) {
            push(&S, T);
            T = T->lchild;
        }
        // 栈顶结点出栈
        pop(&S, &T);
        // 访问结点元素
        Visit(T);
        // T 执行 T 的右子树，继续遍历
        T = T->rchild;
    }
    return OK;
}

/**
 * 后序遍历二叉树(递归)
 * @param T
 * @return
 */
Status PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);
    }
    return OK;
}

/**
 * 后序遍历二叉树(非递归)
 * @param T
 * @return
 */
Status PostOrder2(BiTree T) {

}


/**
 * 二叉树的层序遍历
 * @param T
 * @return
 */
Status LevelOrder(BiTree T) {
    if (T == NULL) {
        printf("二叉树为空\n");
        return OK;
    }
    LinkQueue Q;
    BiTree elem;

    // 初始化一个队列
    InitQueue(&Q);
    // 将二叉树根结点入队未
    EnQueue(&Q, T);
    while (!QueueEmpty(Q)) {
        // 队头结点出队
        DeQueue(&Q, &elem);
        Visit(elem);
        // 如果左子树不为空，入队尾
        if (elem->lchild != NULL) {
            EnQueue(&Q, elem->lchild);
        }
        // 如果右子树不为空，入队尾
        if (elem->rchild != NULL) {
            EnQueue(&Q, elem->rchild);
        }
    }
    return OK;
}

/**
 * 访问树(打印根结点)
 * @param T
 */
void Visit(BiTree T) {
    printf("%d ", T->data);
}