#ifndef ST0830_O_S_PROJECT_LIST_H
#define ST0830_O_S_PROJECT_LIST_H

#include "byteType.h"
#include "stdlib.h"

struct Node {
    char str[MAX_LENGTH_STRING];
    struct Node *next;
} typedef Node;

void insert(char array[]);

char *readAndRemove();

//split: return un puntatore di stringhe
//da un input separa le varie stringhe, a ogni spazio incontrato separa

#endif //ST0830_O_S_PROJECT_LIST_H
