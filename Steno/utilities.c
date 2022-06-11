#include "utilities.h"

/**
 * This method get the length of File.
 * @param f as File.
 * @return the length.
 */
long getFileLength(FILE *f){
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    return length;
}
/**
 * This method set the offset of File .
 * @param f as File.
 */
void setFileOffset(FILE *f, long offset){
    fseek(f, offset, SEEK_SET);
}

/**
 * This method check error on file.
 * @param f as File to check.
 * @return 0 if it don't find an error.
 *         1 else.
 */
int fileErrorCheck(FILE *f){
    if(ferror(f)){
        perror("Error during file operation.");
        return 1;
    }
    return 0;
}

/**
 * This method reads the next byte if possible.
 * @param B as actual Byte.
 * @param f as File.
 * @return -1 if it can't read another byte because B is last.
 *         0 if it don't find an error.
 *         1 else.
 */
int readNextByte(byte *B, FILE *f){
    if(fread(B, sizeof(unsigned char), 1, f) == 0)
        return -1;

    return fileErrorCheck(f);
}