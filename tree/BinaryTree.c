//
// Created by wpy on 2017/6/1.
//

#include <stdlib.h>
#include <stdio.h>

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

}