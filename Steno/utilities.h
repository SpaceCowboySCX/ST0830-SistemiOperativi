#ifndef OSPROJECT_UTILITIES_H
    #define OSPROJECT_UTILITIES_H

    #include <string.h>
    #include "byteType.h"

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
     * This method reads the next byte if possible.
     * @param B as actual Byte.
     * @param f as File.
     * @return -1 if it can't read another byte because B is last.
     *         0 if it don't find an error.
     *         1 else.
     */
    int readNextByte(byte* B, FILE *f);
    /**
     * This method check the extension of file passed by param.
     * @param string
     *                  the name of file to check.
     * @return  0 - no extension - added ".txt"
     *          1 - ".txt"
     *         -1 - ".bmp"
     */
    int extensionFileCheck(char string[MAX_LENGTH_STRING]);

#endif //OSPROJECT_UTILITIES_H
