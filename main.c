#include <stdio.h>
#include <stdlib.h>
#include "list/List.c"

int main() {
    List list = MakeEmpty();
    list->Data = 1;
    insert(2, &list);
    insert(3, &list);
    insert(4, &list);
    insert(5, &list);
    insert(6, &list);
    display(list);
    del(list, 8);
    find(list, 6);
    find(list, 5);
    findKth(list, -1);
    display(list);
/*    List r = Reverse(list);
    display(r);*/
    return 0;
}