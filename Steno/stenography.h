#ifndef ST0830_O_S_PROJECT_STENOGRAPHY_H
    #define ST0830_O_S_PROJECT_STENOGRAPHY_H

    #include <stdlib.h>
    #include <string.h>
    #include "utilities.h"
    /**
     * This method hides a text file within an image.
     * The text file will be decomposed into bytes and
     * then into bits in order to alter the pixels of the image.
     * @param txt
     * @param img
     * @return
     */
    int hiding(FILE txt, FILE img);

    /**
     * This method unveil a text file from an image.
     * The text file will be recomposed into bytes and
     * then into bits in order to alter the pixels of the image.
     * @param txt
     * @param img
     * @return
     */
    int unveiling(FILE image, FILE text);
#endif //ST0830_O_S_PROJECT_STENOGRAPHY_H
