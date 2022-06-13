//
// Created by mrerror404 on 6/13/22.
//
#include "list.h"

Node *firstElement;
Node *lastElement;

void insert(char array[MAX_LENGTH_STRING])
{
    if(lastElement == NULL)
    {

        lastElement = (Node*)malloc(sizeof (Node));
        strcpy(lastElement->str, array);
        *firstElement = *lastElement;
    }
    Node *newNode = (Node*)malloc(sizeof (Node));
    strcpy(newNode->str, array);
    lastElement->next = newNode;
    *lastElement = *lastElement->next;
}

char readAndRemove()
{
    char result[MAX_LENGTH_STRING];
    if(firstElement != NULL)
    {
        //result = (char *) firstElement->str;
        strcpy(result, firstElement->str);
        *firstElement = *firstElement->next;
        return *result;
    }
    return 'c';
}

