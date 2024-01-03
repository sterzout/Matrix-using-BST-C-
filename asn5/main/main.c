// CS2211a 2023, Section 1
// Assignment number 5
// Salim Terzout Yettou
// 251214366
// sterzout 
// December 6, 2023

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <string.h>
int main() {
    FILE *file = fopen("tester.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Cannot open file.\n");
        return 0;
        // try to open file if not say cannot open and return 0
    }
    //else continue with matrix construction
    Matrix m = matrix_construction();
    char string[132];
    char string1[15] = "Number";
    char string2[15]= "Street";
    char string3[15]= "Occurrences";
    printf("%-15s%-18s%-18s\n", string1,string2,string3);
    //print the first title line for the all our data later on
    while (fgets(string, sizeof(string), file) != NULL) {
        //as fgets is not null we keep getting each string line by line
        Key key = key_ini();
        int key2;
        char key1[132];
        char *token = strtok(string, " ");
        //tokenize each line by a space to sepasshrate the strings
        if (token != NULL) {
            long valueToConvert = strtol(token, NULL, 10);
            key2 = (int) valueToConvert;
            key->key2 = key2;
            token = strtok(NULL, "\n");
            //check the first split token for the integer and convert it. Use base 10 for the number, set it to key2
            // take the second part continuing from previous string token until new line which means the rest of the string
            // after the integer
        }
        if (token != NULL) {
            strcpy(key1, token);
            key->key1 = strdup(key1);
            // if this token is not null we extract its string as the key1 for our character array
            // then we duplicate it over to our key->key1 as the char component of the key
        }
        //now the key is complete and we can set it
        key_set(key, key->key1, key->key2);
        if (matrix_index_in(m, key->key1, key->key2) == 1) {
            float countOfKey = *matrix_get(m,key->key1,key->key2);
            countOfKey = countOfKey + 1;
            matrix_set(m, key->key1, key->key2, countOfKey);
            //once the key is set we use it to check the matrix if it is in then 1 is returned, and we know it's in the
            // matrix. then we use get to retrieve out data and if it is in this if statement that means it is in the
            //matrix, and we can increment that count by 1 to indicate there is a copy
        } else {
            float countForZero = 1;
            matrix_set(m, key->key1, key->key2, countForZero);
            //else if there is no copy then return is 0 and we set the data to 1.
        }
        // we do these for every single key we need to enter into the matrix along with data.
    }
    matrix_list(m);
    // use our formatted list function for the matrix to print it out
    matrix_destruction(m);
    // destruct matrix to free memory once we are done with it
    fclose(file);
    // close the file we initially opened
}
