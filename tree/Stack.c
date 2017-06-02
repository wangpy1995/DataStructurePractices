//
// Created by wpy on 2017/6/1.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
union Un {
    BinTree p;
    //0->l_child 1->r_child
    int tag;
};
typedef union Un *U;
typedef struct LSNode *S;
struct LSNode {
    S next;
    U item;
};

S makeEmpty() {
    S stack = (S) malloc(sizeof(struct LSNode));
    stack->next = NULL;
    return stack;
}

void push(U item, S *stack) {
    if (!*stack) {
        perror("NULL Stack");
        return;
    }
    S temp = makeEmpty();
    temp->item = item;
    temp->next = *stack;
    *stack = temp;
}

S pop(S *stack) {
    if (!stack) {
        perror("NULL Stack");
        return NULL;
    }
    S *s = stack;
    *stack = (*stack)->next;
    return *s;
}