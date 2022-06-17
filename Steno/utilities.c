#include "utilities.h"

#include <stdio.h>
#include <string.h>

int extensionFileCheck(char string[MAX_LENGTH_STRING]) {
    //Una stringa con meno di cinque caratteri sicuramente non contiene il nome con l'estensione inclusa
    if(string == NULL){
        perror("You can't insert a null name of file.\n");
        return 0;
    }
    if (strlen(string) >= 5) {
        const char *extension = &string[strlen(string) - 4];
        if (strcmp(extension, ".txt") == 0 || strcmp(extension, ".TXT") == 0)
            return 1;
        else if (strcmp(extension, ".bmp") == 0 || strcmp(extension, ".BMP") == 0)
            return -1;
    }
    return 0;
}

char *inputNameFile(int state) {
    static char file_name[MAX_LENGTH_STRING];
    do {
        printf("\t!Attention!\nYou must enter the extension at the end of name's file.\n");
        printf("Name's file:\t");

        fflush(stdin);
        scanf("%s", file_name);

        if (extensionFileCheck(file_name) == state)
            return file_name;
        else if (state == 1)
            perror("\nIt's not txt file.\n");
        else if (state == -1)
            perror("\nIt's not bmp file.\n");
        else
            perror("\nThe extension file it's not accepted.\n");
    } while (1);
}

Node *insertByInput(int isHiding) {
    Node *list = NULL;
    char name_file_txt[MAX_LENGTH_STRING] = "";
    char name_file_bmp[MAX_LENGTH_STRING];

    int number_of_file;
    do {
        printf("How many File? MAX 10\n");
        fflush(stdin);
        scanf("%d", &number_of_file);
    } while (number_of_file <= 0 || number_of_file > 10);

    for (int i = 0; i < number_of_file; i++) {
        if (isHiding == 1) {
            printf("\tInsert the .txt file.\n");
            strcpy(name_file_txt, inputNameFile(1));
        }
        printf("\tInsert the .bmp file.\n");
        strcpy(name_file_bmp, inputNameFile(-1));
        list = insert(list, name_file_txt, name_file_bmp);
    }

    return list;
}