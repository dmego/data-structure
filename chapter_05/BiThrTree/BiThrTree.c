#include "BiThrTree.h"


/**
 * 前序线索化二叉树
 * 返回前驱结点
 * @param p 当前遍历的结点
 * @param pre 当前结点 p 的前驱结点
 */
void InThread(ThreadTree p, ThreadNode **pre) {
    if (p != NULL) {
        InThread(p->lchild, pre); // 递归线索化左子树
        if (p->lchild == NULL) { // 如果 p 的左子树为空，则左子树需要指向其前驱
            p->lchild = *pre; // 当前结点的左子树指向前驱结点
            p->ltag = 1; // ltag 赋值 1, 表示指向的是线索
        }
        if (*pre != NULL && (*pre)->rchild == NULL) { // 如果前驱结点 pre 的右子树不为空，则其右子树需要指向后继
            (*pre)->rchild = p; // 前驱结点的右子树指向其后继
            (*pre)->rtag = 1; // rtag 赋值 1，表示指向的是线索
        }
        *pre = p;
        InThread(p->rchild, pre); // 递归线索化右子树
    }
}

/**
 * 创建一棵前序线索化二叉树
 * @param T
 */
void CreateInThread(ThreadTree T) {
    ThreadNode *pre = NULL;
    if (T != NULL) {
        InThread(T, &pre);
        // 处理最后一个结点的右子树
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}


/**
 * 找到中序线索化二叉树中的第一个结点
 * 最左下结点
 * @param p
 * @return
 */
ThreadNode *InFirstNode(ThreadNode *p) {
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

/**
 * 找到中序线索化二叉树中，结点 p 的后继结点
 * @param p
 * @return
 */
ThreadNode *InNextNode(ThreadNode *p) {
    // 如果其 rtag 为 1， 说明其后继就是 rchild 指向结点
    if (p->rtag == 1) return p->rchild;
    // 否则 p 结点的后继是其右子树的最左下结点
    else return InFirstNode(p->rchild);
}

/**
 * 遍历中序线索化二叉树
 * @param T
 */
void InOrder(ThreadTree T) {
    ThreadNode *firstNode = InFirstNode(T);
    for (ThreadNode *p = firstNode; p != NULL; p = InNextNode(p)) {
        Visit(p);
    }
}

/**
 * 访问树(打印根结点)
 * @param T
 */
void Visit(ThreadTree T) {
    printf("%d ", T->data);
}