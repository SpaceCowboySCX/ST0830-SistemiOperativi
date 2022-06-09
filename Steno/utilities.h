#ifndef OSPROJECT_UTILITIES_H
    #define OSPROJECT_UTILITIES_H

    #include <stdio.h>
    #include "byteType.h"

    /**
     * This method get the length of File.
     * @param f as File.
     * @return the length.
     */
    long getFileLength(FILE *f);

    /**
     * This method check error on file.
     * @param f as File to check.
     * @return 0 if it don't find an error.
     *         1 else.
     */
    int fileErrorCheck(FILE *f);

    /**
     * This method reads the next byte if possible.
     * @param B as actual Byte.
     * @param f as File.
     * @return -1 if it can't read another byte because B is last.
     *         0 if it don't find an error.
     *         1 else.
     */
    int readNextByte(byte* B, FILE *f);
#endif //OSPROJECT_UTILITIES_H
