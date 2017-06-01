//
// Created by wpy on 2017/6/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Position;
typedef int ElementType;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

bool isFull(Stack stack) {
    return stack->Top1 + stack->Top2 == stack->MaxSize;
}

Stack CreateStack(int MaxSize) {
    Stack stack = malloc(sizeof(struct SNode));
    ElementType *elements = malloc(sizeof(ElementType) * MaxSize);
    stack->Data=elements;
    stack->Top1=0;
    stack->Top2=stack->MaxSize-1;
    return stack;
}

bool Push(Stack S, ElementType X, int Tag);

ElementType Pop(Stack S, int Tag);