#ifndef ST0830_O_S_PROJECT_MANAGEFILE_H
#define ST0830_O_S_PROJECT_MANAGEFILE_H

#include "byteType.h"
#include <stdio.h>

/**
 * This method get the length of file.
 * @param f as File.
 * @return the length.
 */
long getFileLength(FILE *f);

/**
 * This method set the offset of File .
 * @param f as File.
 */
void setFileOffset(FILE *f, long offset);

/**
 * This method check error on file.
 * @param f as File to check.
 * @return 0 if it don't find an error.
 *         1 else.
 */
int fileErrorCheck(FILE *f);

/**
 * This method create a .txt file in the current path.
 * @param file_name
 */
void createTXT(char *file_name);

/**
 * This method print a .txt file of current directory.
 * @param file_name
 */
void printTXT(char *file_name);
#endif //ST0830_O_S_PROJECT_MANAGEFILE_H
