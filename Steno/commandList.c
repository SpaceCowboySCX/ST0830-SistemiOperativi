#include "commandList.h"

void help() {
    printf("Type 1) currentPath:\tShow the path of current directory.\n");
    printf("Type 2) showContent:\tShow the content of current directory.\n");
    printf("Type 3) changeDirectory:\tChange the current directory to the one passed by param.\n");
    printf("Type 4) createTXT:\tCreate a new txt file in the current directory.\n");
    printf("Type 5) printTXT:\tPrint a TXT file in the current directory.\n");
    printf("Type 6) executeHiding:\tExecute hiding Algorithm\n");
    printf("Type 7) executeUnveiling:\tExecute unveiling Algorithm\n");
    printf("Type 0) terminate:\tTerminate the program execution.\n");
}

void currentPath() {
    char current_path[MAX_PATH];
    if (getcwd(current_path, sizeof(current_path)) != NULL)
        printf("This is your current path:\n%s\n", current_path);
    else
        perror("Error: getcwd() error.\n");
}

int showContent() {
    DIR *directory;
    struct dirent *entry;
    int number_of_files = 0;

    directory = opendir(".");
    if (directory == NULL) {
        perror("Unable to read this directory.\n");
        return 1;
    }
    while ((entry = readdir(directory))) {
        number_of_files++;
        printf("File %2d:\t%s\n", number_of_files, entry->d_name);
    }
    closedir(directory);
    return 0;
}

int changeDirectory() {
    char path[MAX_PATH];
    printf("Insert path:\t");
    scanf("%s", path);
    return chdir(path);
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

char *inputNameFile(int state) {
    static char file_name[MAX_LENGTH_STRING];
    do {
        printf("\t!Attention!\nYou must enter the extension at the end of name's file.\n");
        printf("Name's file:\t");
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

int executeHiding(char name_file_txt[MAX_LENGTH_STRING], char name_file_immagine[MAX_LENGTH_STRING]) {
    FILE *file_txt;
    FILE *file_output;
    FILE *file_img = fopen(name_file_immagine, "rb");
    //Controllo i nomi dei file
    if (file_img == NULL) {
        printf("The image input file is not present in the current directory.\n");
        return 1;
    }
    if (name_file_txt == NULL) {
        //TODO pulire il buffer
        file_txt = stdin;
    } else {
        file_txt = fopen(name_file_txt, "rb");
    }

    int length_of_output = lengthFileCheck(file_img, file_txt);
    fseek(file_txt, 0, SEEK_SET);
    fseek(file_img, 0, SEEK_SET);

    if (length_of_output == -1)
        return 1;

    //Creo la stringa, ovvero il nome del file di output.
    //Avrà lo stesso nome del file txt, modifico la stringa sostituendo l'estensione del file.
    char name_file_output[MAX_PATH];
    strcpy(name_file_output, name_file_txt);
    name_file_output[strlen(name_file_txt) - 4] = '\0';
    strcat(name_file_output, ".bmp");
    file_output = fopen(name_file_output, "wb");

    //Creo una copia byte a byte dell'immagine originale
    for (int index = 0; index < length_of_output; index++) {
        byte B;
        fread(&B, 1, sizeof(byte), file_img);
        fwrite(&B, 1, sizeof(byte), file_output);
    }

    hiding(file_img, file_txt, file_output);
    return 0;
}

int executeUnveiling(char name_file_img[MAX_LENGTH_STRING]) {
    FILE *file_img = fopen(name_file_img, "rb");
    FILE *file_output;
    if (file_img == NULL) {
        printf("The image input file is not present in the current directory.\n");
        return 1;
    }

    //Creo la stringa, ovvero il nome del file di output.
    //Avrà lo stesso nome del file bmp, modifico la stringa sostituendo l'estensione del file.
    char name_file_output[MAX_PATH];
    strcpy(name_file_output, name_file_img);
    name_file_output[strlen(name_file_img) - 4] = '\0';
    strcat(name_file_output, ".txt");
    file_output = fopen(name_file_output, "wb");

    unveiling(file_img, file_output);
    return 0;
}

void terminate() {
    printf("Thanks!");
    _Exit(0);
}