//
// Created by wpy on 2017/6/1.
//

#include "Stack.c"

/*int GetHeight(BinTree BT) {
    int m = GetHeight(BT->Left);
    int n = GetHeight(BT->Right);
    if (!BT) return 0;
    return (m > n ? m : n) + 1;
}*/

void pushLeft(BinTree *root, S *s);

void pushRight(BinTree *root, S *s);

//非递归后序遍历
int GetHeight(BinTree BT) {
    if (!BT) return 0;
    S s = makeEmpty();
    BinTree root = BT;
    U item;
    U u = (U) malloc(sizeof(struct Un));
    u->p = root;
    u->tag = 0;
    push(u, &s);
    while (root) {
        while (root->Left) {
            pushLeft(&root, &s);
        }
        while (root->Right) {
            pushRight(&root, &s);
            while (root->Left) pushLeft(&root, &s);
        }
        if (!root->Left && s) {
            item = pop(&s);
            printf("%d\n", item->p->Data);
            root = s->item->p;
            if (item->tag == 0) {
                while (!root->Right) {
                    item = pop(&s);
                    printf("%d\n", item->p->Data);
                    root = s->item->p;
                }
                while (item->tag == 1) {
                    item = pop(&s);
                    printf("%d\n", item->p->Data);
                    root = s->item->p;
                }
                pushRight(&root, &s);
            } else if (item->tag == 1) {
                item = pop(&s);
                printf("%d\n", item->p->Data);
                root = s->item->p;
                while (!root->Right) {
                    item = pop(&s);
                    printf("%d\n", item->p->Data);
                    root = s->item->p;
                    if (root == BT) {
                        item = pop(&s);
                        printf("%d\n", item->p->Data);
                        root = NULL;
                        break;
                    }
                }
                if (root && root->Right)pushRight(&root, &s);
            }
        }
    }
    return 0;
}

void pushLeft(BinTree *root, S *s) {
    /*if (!(*root)->Left)
        return;*/
    U u = (U) malloc(sizeof(struct Un));
    u->p = (*root)->Left;
    u->tag = 0;
    push(u, s);
//    if ((*root)->Left)
    *root = (*root)->Left;
}

void pushRight(BinTree *root, S *s) {
    /*if (!(*root)->Right)
        return;*/

    U u = (U) malloc(sizeof(struct Un));
    u->p = (*root)->Right;
    u->tag = 1;
    push(u, s);
    if ((*root)->Right)
        *root = (*root)->Right;
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
