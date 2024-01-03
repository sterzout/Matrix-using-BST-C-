// CS2211a 2023, Section 1
// Assignment number 5
// Salim Terzout Yettou
// 251214366
// sterzout 
// December 6, 2023

#ifndef ASSIGNMENT_5_DATATYPE_H
#define ASSIGNMENT_5_DATATYPE_H
typedef float* Data;
typedef char* Key1;
typedef int Key2;
typedef struct {Key1 key1; Key2 key2;} Key_struct;
typedef Key_struct* Key;
Key key_ini();
void key_set(Key key, Key1 key1, Key2 key2);
int key_comp(Key key1, Key key2);
void key_print(Key key);
void key_free(Key key);
Data data_ini();
void data_set(Data data, float intdata);
void data_print(Data data);
void data_free(Data data);
#endif //ASSIGNMENT_5_DATATYPE_H
