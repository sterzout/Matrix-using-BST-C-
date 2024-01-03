// CS2211a 2023, Section 1
// Assignment number 5
// Salim Terzout Yettou
// 251214366
// sterzout 
// December 6, 2023
#include "bstree.h"
#include <stdlib.h>
#include <string.h>
BStree bstree_ini(void){
    BStree tree;
    tree = (BStree_node**)malloc(sizeof(BStree));
    *tree = NULL;
    return tree;
    // allocate memory for a new node this time
}
BStree_node *new_node(Key key, Data data){
    BStree_node* node = (BStree_node*) malloc(sizeof(BStree_node));
    node->key = key;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    // create a new singular node and return it
    return node;
}
void recursiveInsert(BStree_node *node, Key key, Data data) {
    if (key_comp(node->key, key) == 0) {
        return;
        // if the node is already there then we return
    } else if (key_comp(node->key, key) == 1) {
        if (node->left == NULL) {
            node->left = new_node(key, data);
            //if the node we want to insert is less than current node we check if left subtree is null to insert it
            return;
        } else {
            recursiveInsert(node->left, key, data);
            //if the node we want to insert is greater than current node we look for its place in the left subtree
        }
    } else if (key_comp(node->key, key) == -1) {
        if (node->right == NULL) {
            node->right = new_node(key, data);
            //if the node we want to insert is less than current node we check if right subtree is null to insert it
            return;
        } else {
            recursiveInsert(node->right, key, data);
            //if the node we want to insert is greater than current node we look for its place in the right subtree
        }
    }
}
void bstree_insert(BStree bst, Key key, Data data) {
    if (*bst == NULL) {
        *bst = new_node(key, data);
    } else {
        recursiveInsert(*bst, key, data);
    }
}
Data bstree_search(BStree bst, Key key) {
    if (*bst == NULL) {
        return NULL;
        //if null return null
    }
    BStree_node *headNode = *bst;
    // else we start from the root and traverse with keycomp
    do {
        if (key_comp(headNode->key, key) == 0) {
            return headNode->data;
            // if keycomp returns 0, we found our node and return the data
        }
        else if (key_comp(headNode->key, key) > 0) {
            headNode = headNode->left;
            // if node we are at is greater than node we are looking for then we go left
        }
        else if (key_comp(headNode->key, key) < 0) {
            headNode = headNode->right;
            // if node we are at is smaller than node we are looking for then we go right
        }
    } while (headNode != NULL);
    // we do this until headnode is null then we return null
    return NULL;
}
void inOrderTraversal(BStree_node *node){
    if (node == NULL){
        return;
    }else{
        inOrderTraversal(node->left);
        key_print(node->key);
        data_print(node->data);
        inOrderTraversal(node->right);
        // typical inorder traversal printing key and data along the way
    }
}
void bstree_traverse(BStree bst) {
    if (bst == NULL) {
        return;
        // if null do nothing else then we will traverse starting from root with our helper method
    }
    BStree_node *node = *bst;
    inOrderTraversal(node);
}
void freeTraverse(BStree_node *node){
    if (node == NULL){
        return;
    }else {
        freeTraverse(node->left);
        freeTraverse(node->right);
        free(node);
        // traverse and free through traversal since it is a tree and has nodes
    }
}
void bstree_free(BStree bst) {
    if (*bst == NULL){
        return;
    }
    freeTraverse(*bst);
    // free bst memory
}
