#include "LinkList.h"

/**
 * 初始化一个单链表
 * 注意⚠️：
 *      LinkList 是 LNode 指针类型
 *      这里的 list 是 LinkList 指针，也就是指向 链表头指针 的指针
 *      (*list) 是取出了访问 list 指向的地址，也就是 链表头指针
 * @param list
 * @return
 */
Status initLinkList(LinkList* list) {
    // malloc(sizeof(LNode)): 新建一个 LNode 节点，作为头结点
    // 然后 链表的头指针(*list) 指向 新建头结点的地址
    (*list) = malloc(sizeof(LNode));
    if ((*list) == NULL) {
        // 新建头结点失败，退出
        exit(OVERFLOW);
    }
    // 将链表头结点的指针域置为 NULL
    (*list)->next = NULL;

    return OK;
}

/**
 * 在单链表 list 的 index 位置插入元素 elem
 * @param list
 * @param index
 * @param elem
 * @return
 */
Status insertElem(LinkList list, int index, ElemType elem) {
    // 如果 链表不存在，返回 ERROR
    if (list == NULL) return ERROR;
    // 校验 index 位置是否合法
    if (index < 1) return ERROR;

    // 头指针
    LNode *dummy = list;
    // 链表下标，从头结点开始遍历
    int i = 0;
    // 遍历条件：dummy != NULL，也就是没有遍历到链表末尾
    // i < index - 1, 也就是最后 dummy 要指向 index 位置的前一个结点(index - 2 下标处)
    while (dummy != NULL && i < index - 1) {
        dummy = dummy->next;
        i++;
    }

    // 如果遍历到头了(dummy = null) 或者 下标 i 指向到了 index - 1 位置，返回 ERROR
    if (dummy == NULL || i > index - 1) return ERROR;

    // 新建一个 LNode 结点，使用 node 指针指向新结点地址
    LNode* node = malloc(sizeof(LNode));
    if (node == NULL) {
        exit(OVERFLOW);
    }
    // 将 elem 存储到新结点的值域
    node->data = elem;
    // 新节点的 next 指针 指向 dummy 的 next 结点
    node->next = dummy->next;
    // dummy 的 next 指针 指向 新结点，也就是让新结点插入到了 index - 1 下标 (index 位置)
    dummy->next = node;

    return OK;
}

/**
 * 取出 单链表 list 的 index 位置的元素， 赋值给 elem 指针指向的地址
 * @param list
 * @param index
 * @param elem
 * @return
 */
Status getElem(LinkList list, int index, ElemType* elem) {
    // 如果 链表不存在 或者 链表中没有存储元素，返回 ERROR
    if (list == NULL || list->next == NULL) return ERROR;
    // 校验 index 位置是否合法
    if (index < 1) return ERROR;

    // 头指针
    LNode* dummy = list;
    // 链表下标，从头结点开始遍历
    int i = 0;

    // 遍历条件：dummy != NULL 也就是没有遍历到链表末尾
    // i < index, 也就是 dummy 最后需要指向 index - 1 下标节点(index 位置)
    while (dummy != NULL && i < index) {
        dummy = dummy->next;
        i++;
    }
    // 如果遍历到头了(dummy = null) 或者 下标 i 指向到了 index 位置，返回 ERROR
    if (dummy == NULL || i > index) return ERROR;
    // 将 dummy 指针指向的结点的数据域 赋值给 elem 指针 指向的地址
    *elem = dummy->data;


    /*
     另一种写法，dummy 指向 index - 1(index - 2 下标) 位置，dummy->next 指向 index (index - 1 下标)位置
     取值时使用： dummy->next->data
     while (dummy->next != NULL && i < index - 1) {
        dummy = dummy->next;
        i++;
     }
     if (dummy->next == NULL || i > index - 1) return ERROR;
     *elem = dummy->next->data;
    */

    return OK;
}

/**
 * 删除 单链表 index 位置的元素，并将删除的元素赋值给 elem
 * @param list
 * @param index
 * @param elem
 * @return
 */
Status deleteElem(LinkList list, int index, ElemType* elem) {
    // 如果 链表不存在 或者 链表中没有存储元素，返回 ERROR
    if (list == NULL || list->next == NULL) return ERROR;
    // 校验 index 位置是否合法
    if (index < 1) return ERROR;
    // 头指针
    LNode* dummy = list;
    // 从头结点开始遍历
    int i = 0;

    // 遍历到 index - 2 下标(index - 1 位置，也就是要删除的元素的前一个)
    while (dummy->next != NULL && i < index - 1) {
        dummy = dummy->next;
        i++;
    }

    if (dummy->next == NULL || i > index - 1) return ERROR;
    // 要删除的元素(这里取的是 dummy->next 所以前面的判断是判断 dummy->next 是否存在)
    LNode *delete = dummy->next;
    // 保存要删除元素的值到 elem
    *elem = delete->data;
    // 将 index - 2 下标结点的 next 指针 指向 要删除元素的 next 结点
    dummy->next = delete->next;
    // 要删除元素的 next 指向 NULL;
    delete->next = NULL;
    // 回收要删除元素的内存
    free(delete);

    return OK;
}

/**
 * 在单链表中定位 elem 元素的位置
 * @param list
 * @param elem
 * @return
 */
int locateElem(LinkList list, ElemType elem) {
    // 如果 链表不存在 或者 链表中没有存储元素，返回 -1
    if (list == NULL || list->next == NULL) return -1;
    LNode* dummy = list->next;
    int locate = 1;
    while (dummy != NULL) {
        if (dummy->data == elem) {
            break;
        }
        dummy = dummy->next;
        locate++;
    }
    // 如果 elem 在单链表中存在，返回 位置(下标+1)
    // 如何不存在，返回 -1
    return dummy == NULL ? -1 : locate;
}

/**
 * 前插法创建一个单链表
 * @param list
 * @param num 插入元素个数
 * @return
 */
Status headCreateList(LinkList* list, int num) {
    if (num < 1) return ERROR;
    printf("请降序输入 %d 个元素: ", num);
    // 头指针 指向头结点，在插入过程中，头指针一直指向头结点
    LNode* head = *list;
    for (int i = 0; i < num; i++) {
        LNode* node = malloc(sizeof(LNode));
        if (node == NULL) {
            exit(OVERFLOW);
        }
        scanf("%d", &(node->data));
        node->next = head->next;
        head->next = node;
    }
    return OK;
}

/**
 * 后插法创建一个单链表
 * @param list
 * @param num 插入元素个数
 * @return
 */
Status tailCreateList(LinkList* list, int num) {
    if (num < 1) return ERROR;
    printf("请升序输入 %d 个元素: ", num);
    // 尾指针，开始指针头结点，插入结点后，指向插入的结点
    LNode* tail = *list;
    for (int i = 0; i < num; i++) {
        LNode* node = malloc(sizeof(LNode));
        if (node == NULL) {
            exit(OVERFLOW);
        }
        scanf("%d", &(node->data));
        tail->next = node;
        // 改变尾指针的指向
        tail = tail->next;
    }
    return OK;
}


void printLinkList(LinkList list) {
    LNode* dummy = list->next;
    while(dummy != NULL) {
        printf("%d ,", dummy->data);
        dummy = dummy->next;
    }
}
