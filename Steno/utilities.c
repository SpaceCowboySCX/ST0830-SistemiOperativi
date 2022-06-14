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

int extensionFileCheck(char string[MAX_LENGTH_STRING]){
    //Una stringa con meno di cinque caratteri sicuramente non contiene il nome con l'estensione inclusa
    if(strlen(string) > 5) {
        //Se l'utente non ha specificato l'estensione del file, aggiungo ".txt".
        const char *extension = &string[strlen(string) - 4];
        if (strcmp(extension, ".txt") == 0)
            return 1;
        else if (strcmp(extension, ".bmp") == 0)
            return -1;
    }

    strcat(string, ".txt");
    return 0;
}

char* split(char str[])
{
    //Separatore di stringa sono presegnalati da aperte che chiuse le doppie ""
    int index = 0;
    char* token = strtok(str, " ");
    static char array[10][MAX_LENGTH_STRING];
    if(token != NULL) strcpy( array[0], token);
    while(token != NULL)
    {
        index = index + 1;
        token = strtok(NULL, " ");
        strcpy( array[index], token);
    }
    return (char*) array;
}