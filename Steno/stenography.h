#ifndef ST0830_O_S_PROJECT_STENOGRAPHY_H
#define ST0830_O_S_PROJECT_STENOGRAPHY_H

#include <stdio.h>
#include "list.h"

/**
 * This method hides a text file within an image.
 * The text file will be decomposed into bytes and
 * then into bits in order to alter the pixels of the image.
 * @param txt
 * @param img
 * @return
 */
void *hiding(void* list);

/**
 * This method write a byte to skip.
 * @param file_img
 * @param file_img_output
 */
void toSkip(FILE *file_img, FILE *file_img_output);

/**
 * This method unveil a text file from an image.
 * The text file will be recomposed into bytes and
 * then into bits in order to alter the pixels of the image.
 * @param txt
 * @param img
 * @return
 */
void* unveiling(void* list);

int lengthFileCheck(FILE *file_img, FILE *file_txt);

#endif //ST0830_O_S_PROJECT_STENOGRAPHY_H
