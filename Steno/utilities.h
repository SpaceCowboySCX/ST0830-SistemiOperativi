#ifndef OSPROJECT_UTILITIES_H
#define OSPROJECT_UTILITIES_H
//Costante globale per la lunghezza delle stringhe
#define MAX_LENGTH_STRING 30
#include "list.h"

#define MAX_PATH 200

/**
 * This method check the extension of file passed by param.
 * @param string
 *                  the name of file to check.
 * @return  1 - ".txt"
 *          0 - other file
 *         -1 - ".bmp"
 */
int extensionFileCheck(char string[MAX_LENGTH_STRING]);

/**
 * This method take in input a file name to return.
 * @return
 *          a file name;
 */
char *inputNameFile(int state);

/**
 * This method bring in input the element of List
 * @return
 *                  firstElement of list.
 */
Node * insertByInput(int isHiding);

#endif //OSPROJECT_UTILITIES_H
