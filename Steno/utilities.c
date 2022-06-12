#include "utilities.h"

long getFileLength(FILE *f){
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    return length;
}

void setFileOffset(FILE *f, long offset){
    fseek(f, offset, SEEK_SET);
}

int fileErrorCheck(FILE *f){
    if(ferror(f)){
        perror("Error during file operation.");
        return 1;
    }
    return 0;
}

int readNextByte(byte *B, FILE *f){
    if(fread(B, sizeof(unsigned char), 1, f) == 0)
        return -1;

    return fileErrorCheck(f);
}