//
// Created by mrerror404 on 6/13/22.
//
#ifndef ST0830_O_S_PROJECT_LIST_H
#define ST0830_O_S_PROJECT_LIST_H

#include "byteType.h"
#include "stdlib.h"

struct Node{
    char str[MAX_LENGTH_STRING];
    struct Node *next;
} typedef Node;

void insert(char array[]);

char* readAndRemove();

#endif //ST0830_O_S_PROJECT_LIST_H
