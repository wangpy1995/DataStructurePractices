//
// Created by wpy on 2017/6/6.
//

#include <malloc.h>

typedef struct AVLNode *AVL;
typedef int T;

struct AVLNode {
    T data;
    AVL l_child;
    AVL r_child;
    int bf;
};

AVL newNode() {
    AVL node = (AVL) malloc(sizeof(struct AVLNode));
    node->l_child = NULL;
    node->r_child = NULL;
    node->bf = 0;
    return node;
}

int getBF(AVL node) {
    if (!node)return 0;
    int lh = getBF(node->l_child);
    int rh = getBF(node->r_child);
    return lh - rh;
}

void rotateLeft(AVL *r) {
    AVL l_child = (*r)->l_child;
    (*r)->l_child = l_child->r_child;
    l_child->r_child = *r;
    l_child->bf = getBF(l_child);
    (*r)->bf = getBF(*r);
}

void rotateRight(AVL *r) {
    AVL r_child = (*r)->r_child;
    (*r)->r_child = r_child->l_child;
    r_child->l_child = *r;
    r_child->bf = getBF(r_child);
    (*r)->bf = getBF(*r);
}

void lrRotate(AVL *r) {

}

void rlRotate(AVL *r) {

}