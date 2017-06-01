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
    return stack->Top1 == stack->Top2;
}

Stack CreateStack(int MaxSize) {
    Stack stack = malloc(sizeof(struct SNode));
    ElementType *elements = malloc(sizeof(ElementType) * MaxSize);
    stack->Data = elements;
    stack->MaxSize = MaxSize;
    stack->Top1 = 0;
    stack->Top2 = stack->MaxSize - 1;
    return stack;
}

bool Push(Stack S, ElementType X, int Tag) {
    if (S && !isFull(S)) {
        if (Tag == 1) {
            S->Data[S->Top1++] = X;
        } else if (Tag == 2) {
            S->Data[S->Top2--] = X;
        } else {
            printf("invalid Tag: %d\n", Tag);
            exit(-1);
        }
    } else {
        perror("Full/NULL Stack\n");
        exit(-1);
    }
}

ElementType Pop(Stack S, int Tag) {
    if (S) {
        if (Tag == 1 && S->Top1 > 0) {
            return S->Data[--S->Top1];
        } else if (Tag == 2 && S->Top2 < S->MaxSize - 1) {
            return S->Data[++S->Top2];
        } else {
            printf("Invalid Tag: %d or Empty Stack:%d", Tag, Tag);
            exit(-1);
        }
    } else {
        perror("NULL stack\n");
        exit(-1);
    }
}

void displayStack(Stack S) {
    ElementType *elements = S->Data;
    int i;
    for (i = 0; i < S->MaxSize; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");
}

void testStack() {
    Stack stack = CreateStack(5);
    Push(stack, 0, 1);
    printf("pop1: %d, Top1:%d, Top2:%d\n", Pop(stack, 1), stack->Top1, stack->Top2);
    Push(stack, 1, 1);
    printf("pop1: %d, Top1:%d, Top2:%d\n", Pop(stack, 1), stack->Top1, stack->Top2);
    Push(stack, 2, 1);
    Push(stack, 9, 2);
    Push(stack, 8, 2);
    Push(stack, 7, 2);

//    printf("pop1: %d, Top1:%d, Top2:%d\n", Pop(stack, 1), stack->Top1, stack->Top2);
    printf("pop1: %d, Top1:%d, Top2:%d\n", Pop(stack, 1), stack->Top1, stack->Top2);
    printf("pop2: %d, Top1:%d, Top2:%d\n", Pop(stack, 2), stack->Top1, stack->Top2);
    printf("pop2: %d, Top1:%d, Top2:%d\n", Pop(stack, 2), stack->Top1, stack->Top2);
//    printf("pop2: %d, Top1:%d, Top2:%d\n", Pop(stack, 2), stack->Top1, stack->Top2);
    printf("pop2: %d, Top1:%d, Top2:%d\n", Pop(stack, 2), stack->Top1, stack->Top2);
    printf("Top1:%d Top2:%d\n", stack->Top1, stack->Top2);
}