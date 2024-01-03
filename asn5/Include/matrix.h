// CS2211a 2023, Section 1
// Assignment number 5
// Salim Terzout Yettou
// 251214366
// sterzout 
// December 6, 2023

#ifndef ASSIGNMENT_5_MATRIX_H
#define ASSIGNMENT_5_MATRIX_H
#include "bstree.h"
typedef BStree Matrix;
typedef Key1 Index1;
typedef Key2 Index2;
typedef float Value;
Matrix matrix_construction(void);
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2);
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2);
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);
#endif //ASSIGNMENT_5_MATRIX_H
