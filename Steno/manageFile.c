#include "manageFile.h"

long getFileLength(FILE *f) {
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    return length;
}

void setFileOffset(FILE *f, long offset) {
    fseek(f, offset, SEEK_SET);
}

int fileErrorCheck(FILE *f) {
    if (ferror(f)) {
        perror("Error during file operation.");
        return 1;
    }
    return 0;
}

int readNextByte(byte *B, FILE *f) {
    if (fread(B, sizeof(unsigned char), 1, f) == 0)
        return -1;

    return fileErrorCheck(f);
}


void createTXT(char *file_name) {
    fclose(fopen(file_name, "at"));
    printf("File created.\n");
}

void printTXT(char *file_name) {
    FILE *file_to_print;
    char character_to_print;

    if (extensionFileCheck(file_name) == 1) {
        file_to_print = fopen(file_name, "r");
        character_to_print = (char) fgetc(file_to_print);

        while (character_to_print != EOF) {
            printf("%c", character_to_print);
            character_to_print = (char) fgetc(file_to_print);
        }
        fclose(file_to_print);
    } else
        perror("Error: don't try to print a non-txt file.\n");
}