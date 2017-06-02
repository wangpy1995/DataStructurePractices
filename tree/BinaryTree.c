//
// Created by wpy on 2017/6/1.
//

#include <stdlib.h>
#include <stdio.h>
#include "Stack.c"

/*int GetHeight(BinTree BT) {
    int m = GetHeight(BT->Left);
    int n = GetHeight(BT->Right);
    if (!BT) return 0;
    return (m > n ? m : n) + 1;
}*/

//非递归后序遍历
int GetHeight(BinTree BT) {
    if (!BT) return 0;
    S s = makeEmpty();
    BinTree root = BT;
    S item;
    int tag;
    U u = (U *) malloc(sizeof(union Un));
    u->p = &root;
    u->tag = 0;
    push(u, &s);
    while (root) {
        pushLeft(&root, &s);
        pushRight(&root, &s);
        if (!root && s) {
            item = pop(&s);
            printf("%d\n", item->item->p->Data);
            root = s->item->p;
            if (item->item->tag == 0) {
                if (!root->Right) {
                    item = pop(&s);
                    printf("%d\n", item->item->p->Data);
                    root = s->item->p;
                } else pushRight(&root, s);
            } else if (item->item->tag == 1) {
                item = pop(&s);
                printf("%d\n", item->item->p->Data);
                root = s->item->p;
            }
        }
    }
    return 0;
}

void pushLeft(BinTree *root, S *s) {
    /*if (!(*root)->Left)
        return;*/
    while (*root) {
        U u = (U *) malloc(sizeof(union Un));
        BinTree l = (*root)->Left;
        u->p = &l;
        u->tag = 0;
        push(u, s);
        *root = (*root)->Left;
    }
}

void pushRight(BinTree *root, S *s) {
    /*if (!(*root)->Right)
        return;*/
    while (*root) {
        U u = (U *) malloc(sizeof(union Un));
        BinTree r = (*root)->Right;
        u->p = &r;
        u->tag = 1;
        push(u, s);
        *root = (*root)->Right;
    }
}

BinTree createTreeNode(ElementType data) {
    BinTree node = (BinTree) malloc(sizeof(struct TNode));
    node->Data = data;
    node->Left = NULL;
    node->Right = NULL;
    return node;
}

void testTreeStack() {
    BinTree root = (BinTree) malloc(sizeof(struct TNode));
    root->Data = 1;
    BinTree n2 = createTreeNode(2);
    BinTree n3 = createTreeNode(3);
    BinTree n4 = createTreeNode(4);
    BinTree n5 = createTreeNode(5);
    BinTree n6 = createTreeNode(6);
    BinTree n7 = createTreeNode(7);
    BinTree n8 = createTreeNode(8);
    BinTree n9 = createTreeNode(9);
    BinTree n10 = createTreeNode(10);
    BinTree n11 = createTreeNode(11);
    root->Left = n2;
    root->Right = n3;
    n2->Left = n4;
    n2->Right = n5;
    n3->Left = n6;
    n4->Left = n7;
    n4->Right = n8;
    n6->Right = n9;
    n7->Left = n10;
    n8->Left = n11;
    GetHeight(root);
}
