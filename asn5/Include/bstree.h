// CS2211a 2023, Section 1
// Assignment number 5
// Salim Terzout Yettou
// 251214366
// sterzout 
// December 6, 2023

#ifndef ASSIGNMENT_5_BSTREE_H
#define ASSIGNMENT_5_BSTREE_H
#include "datatype.h"
typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;
BStree bstree_ini(void);
void bstree_insert(BStree bst, Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traverse(BStree bst);
void bstree_free(BStree bst);
#endif //ASSIGNMENT_5_BSTREE_H
