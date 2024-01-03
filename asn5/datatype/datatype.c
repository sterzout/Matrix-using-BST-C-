// CS2211a 2023, Section 1
// Assignment number 5
// Salim Terzout Yettou
// 251214366
// sterzout 
// December 6, 2023

#include "datatype.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Key key_ini(){
    Key key;
    key = malloc(sizeof(Key_struct));
    return key;
    //initialize key and allocate memory
}
void key_set(Key key, Key1 key1, Key2 key2){
    key->key1 = (char*)malloc(1*(strlen(key1)+1));
    strcpy(key->key1,key1);
    key->key2 = key2;
    //set key1 and allocate memory and set key1 and key2
}
int key_comp(Key key1, Key key2) {
        int stringComparisonVal = strcmp(key1->key1, key2->key1);
        if (stringComparisonVal < 0) {
            return -1;
            // if key1->key1 is smaller return -1
        }
        if (stringComparisonVal > 0) {
            return 1;
            // if key1->key1 is greater return -1
        }
        else if (!(stringComparisonVal > 0) && !(stringComparisonVal < 0)){
            // if it is neither less or more than it is equal and we compare their key2's
                if (key1->key2>key2->key2) {
                    return 1;
                }
                if (key1->key2<key2->key2) {
                    return -1;
                }
                if (key1->key2 == key2->key2) {
                    return 0;
                }
                // same comparisons this time with key2, if key2 is also equal then we have to return 0;
        }
    return 0;
}
void key_print(Key key) {
    if (key->key1 != NULL) {
        printf("%-8d %-29s", key->key2, key->key1);
        // print key1 and key2 with this format which fits
    }
}
void key_free(Key key){
    free(key);
    //free key
}
Data data_ini(){
    Data data;
    data = malloc(sizeof(float));
    return data;
    // allocate memory for a new data item and return data
}
void data_set(Data data, float intdata){
    if (data != NULL) {
        *data = intdata;
    } else{
        return;
        // set data to the intData or if it is null we do nothing
    }
}
void data_print(Data data){
        printf("%-6.0f\n", *data);
    // print data value with this format which fits
}
void data_free(Data data){
        free(data);
        //free data memory
}
