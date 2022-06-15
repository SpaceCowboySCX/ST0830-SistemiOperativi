#ifndef ST0830_O_S_PROJECT_LIST_H
#define ST0830_O_S_PROJECT_LIST_H

#include "byteType.h"
#include "stdlib.h"

struct Node{
    char name_file_txt[MAX_LENGTH_STRING];
    char name_file_bmp[MAX_LENGTH_STRING];
    struct Node *next;
} typedef Node;


/**
* This method put an element string on list.
* @param first_element
*                  first element of the list.
* @param string
*                  name_file_txt.
* @param string
*                  name_file_bmp.
* @return
*                  firstElement of list.
*/
Node* insert(Node* first_element, char name_file_txt[], char name_file_bmp[]);

/**
* This method remove an element on list.
* @param first_element
*                  name_file_txt.
* @return
*                  return first element of the list after remove list.
*/
Node* removeElement(Node* first_element);


/**
 * This method return next of the list element.
 * @param element
 *                  element.
 * @return
 *                  next node of element.
 */
Node* getNext(Node* element);


/**
 * This method return an name of file txt of this element.
 * @param element
 *                  element of the list.
 * @return
 *                  string name of file txt of this element.
 */
char* getNameFileTxt(Node* element);


/**
 * This method return an name of file bmp of this element.
 * @param element
 *                  element of the list.
 * @return
 *                  string name of file bmp of this element.
 */
char* getNameFileBmp(Node* element);


/**
 * This method return lastElement on the list.
 * @param first_element
 *                  first element of the list.
 * @return
 *                  firstElement of list.
 */
Node* getLastElement(Node* first_element);

#endif //ST0830_O_S_PROJECT_LIST_H
