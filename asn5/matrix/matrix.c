// CS2211a 2023, Section 1
// Assignment number 5
// Salim Terzout Yettou
// 251214366
// sterzout 
// December 6, 2023

#include "matrix.h"
#include <string.h>
Matrix matrix_construction(void){
    Matrix m = bstree_ini();
    return m;
    //initialize a matrix using a bst file
}
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2){
    Key_struct *new_key = key_ini();
    key_set(new_key,index1,index2);
    //initialize and set the key given key1 and key2 for bst search
    if (bstree_search(m,new_key) == NULL){
        return 0;
    }else if (bstree_search(m,new_key) != NULL){
        return 1;
        // if search is null return 0 else if it is not null return 1 since found
    }
    return 0;
}
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2){
    Key key = key_ini();
    key_set(key,index1,index2);
    if (bstree_search(m,key) == NULL){
        return NULL;
    }else if (bstree_search(m,key) != NULL){
        return bstree_search(m,key);
    }
    return NULL;
    // same setting of the key as before but if null we return null, if not we return data from bstSearch method
}
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value) {
    if (matrix_get(m, index1, index2) == NULL) {
        Key newKey = key_ini();
        key_set(newKey, index1, index2);
        Data itemToChange = data_ini();
        data_set(itemToChange, value);
        bstree_insert(m, newKey, itemToChange);
        // if get returns null, we use insert to the new key we made along with the data we initialize with Value
    } else {
        Key newKey = key_ini();
        key_set(newKey, index1, index2);
        Data existingData = bstree_search(m, newKey);
        data_set(existingData, value);
        // else we overwrite it as instructed
    }
}
    void matrix_list(Matrix m) {
        bstree_traverse(m);
        // list the matrix by traversing the tree
    }
    void matrix_destruction(Matrix m) {
        bstree_free(m);
        // free the matrix using bst_free method
    }
