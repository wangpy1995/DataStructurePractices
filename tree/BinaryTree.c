//
// Created by wpy on 2017/6/1.
//

#include <stdlib.h>
#include <stdio.h>
#include "Stack.c"

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


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
    while(root->Left){
        U u = (U)malloc(sizeof(union Un));
        u.p=root->Left;
        u.tag=0;
        push(u,s);
    }
    while ()
}