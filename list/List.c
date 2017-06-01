//
// Created by wpy on 2017/6/1.
//

#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Reverse(List L) {
    if (!L || !L->Next)return L;
    List ptr = L;
    List temp;
    List head = ptr;
    while (ptr->Next) {
        temp = ptr->Next;
        ptr->Next = temp->Next;
        temp->Next = head;
        head = temp;
    }
    return head;
}

void insert(ElementType item, List *list) {
    List temp = (List) malloc(sizeof(struct Node));
    temp->Data = item;
    temp->Next = *list;
    *list = temp;
}

void displayList(List list) {
    List p = list;
    while (p->Next) {
        printf("%d -> ", p->Data);
        p = p->Next;
    }
    printf("%d\n", p->Data);
}

List MakeEmpty() {
    List list = (List) malloc(sizeof(struct Node));
    return list;
}

void del(List list, ElementType X) {
    List p = list;
    while (p && p->Data != X) {
        p = p->Next;
    }
    if (!p) {
        printf("element %d not exists\n", X);
        return;
    }
    p->Data = p->Next->Data;
    p->Next = p->Next->Next;
    free(p->Next);
}

int find(List list, ElementType X) {
    int count = 0;
    while (list && list->Data != X) {
        list = list->Next;
        count++;
    }
    if (!list)
        printf("not found\n");
    else
        printf("found element: %d at %d\n", X, count);
    return count;
}

ElementType findKth(List list, int K) {
    if (K < 0) {
        printf("invalid number K: %d\n", K);
        return NULL;
    }
    int i;
    for (i = 0; i < K; i++) list = list->Next;
    if (!list) {
        printf("not exist\n");
        return NULL;
    } else {
        printf("find %dth element: %d\n", K, list->Data);
        return list->Data;
    }
}

int length(List list) {
    int count = 0;
    while (list) {
        list = list->Next;
        count++;
    }
    return count;
}

void testList() {
    List list = MakeEmpty();
    list->Data = 1;
    insert(2, &list);
    insert(3, &list);
    insert(4, &list);
    insert(5, &list);
    insert(6, &list);
    displayList(list);
    del(list, 8);
    find(list, 6);
    find(list, 5);
    findKth(list, -1);
    displayList(list);
/*    List r = Reverse(list);
    displayStack(r);*/
}