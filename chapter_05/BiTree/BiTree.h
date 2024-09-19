/*=====================
 * 二叉树的二叉链表存储结构
 =====================*/

#ifndef BITREE_H
#define BITREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Status.h"

/* 二叉树的元素类型定义*/
typedef int TElemType;

/* 二叉树结点定义 */
typedef struct BiTNode{
    TElemType data;          // 结点数据
    struct BiTNode *lchild;  // 结点左孩子指针
    struct BiTNode *rchild;  // 结点右孩子指针
} BiTNode;

/* 指向二叉树结点的指针 */
typedef BiTNode *BiTree;


/**
 * 构建二叉树
 * @param T
 * @return
 */
Status CreateBiTree(BiTree *T);


/**
 * 先序遍历二叉树(递归)
 * @param T
 * @return
 */
Status PreOrder(BiTree T);

/**
 * 先序遍历二叉树(非递归)
 * @param T
 * @return
 */
Status PreOrder2(BiTree T);

/**
 * 中序遍历二叉树(递归)
 * @param T
 * @return
 */
Status InOrder(BiTree T);

/**
 * 中序遍历二叉树(非递归)
 * @param T
 * @return
 */
Status InOrder2(BiTree T);

/**
 * 后序遍历二叉树(递归)
 * @param T
 * @return
 */
Status PostOrder(BiTree T);

/**
 * 后序遍历二叉树(非递归)
 * @param T
 * @return
 */
Status PostOrder2(BiTree T);


/**
 * 二叉树的层序遍历
 * @param T
 * @return
 */
Status LevelOrder(BiTree T);


/**
 * 访问树(打印根结点)
 * @param T
 */
void Visit(BiTree T);

#endif BITREE_H
