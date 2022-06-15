#ifndef ST0830_O_S_PROJECT_LIST_H
#define ST0830_O_S_PROJECT_LIST_H

#include "byteType.h"
#include "stdlib.h"

struct Node{
    char str[MAX_LENGTH_STRING];
    struct Node *next;
} typedef Node;

    /**
     * This method put an element string on list.
     * @param
     *                  array of char.
     * @return
     *                  firstElement of list
     */
Node* insert(char array[]);

    /**
     * This method return firstElement on the list.
     * @return
     *                  firstElement of list
     */
Node *getFirstElement();

/**
 * This method readAndRemove 1 element on the list.
 * @return
 *                     string value of element.
 */
char* readAndRemove();


/**
 * This method return new of the list element.
 * @param element
 *                  element of the next.
 * @return
 *                  next node of element.
 */
Node* getNext(Node* element);


/**
 * This method return an string of this element.
 * @param element
 *                  element of the list.
 * @return
 *                  string of this element
 */
char* getStringOfElement(Node* element);


/**
 * This method return lastElement on the list.
 * @return
 *                  firstElement of list
 */
Node* getLastElement();

#endif //ST0830_O_S_PROJECT_LIST_H
