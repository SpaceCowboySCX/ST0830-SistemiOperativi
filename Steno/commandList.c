#include "commandList.h"
#include "utilities.h"
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "stenography.h"
#include "implementationThread.h"

void help() {
    printf("Type 1) currentPath:\tShow the path of current directory.\n"
           "Type 2) showContent:\tShow the content of current directory.\n"
           "Type 3) changeDirectory:\tChange the current directory to the one passed by param.\n"
           "Type 4) createTXT:\tCreate a new txt file in the current directory.\n"
           "Type 5) printTXT:\tPrint a TXT file in the current directory.\n"
           "Type 6) executeHiding:\tExecute hiding Algorithm\n"
           "Type 7) executeUnveiling:\tExecute unveiling Algorithm\n"
           "Type 0) terminate:\tTerminate the program execution.\n");
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
        printf("File %3d:\t%s\n", number_of_files, entry->d_name);
    }
    closedir(directory);
    return 0;
}

int changeDirectory() {
    char path[MAX_PATH];
    printf("Insert path:\t");
    fflush(stdin);
    scanf("%s", path);
    return chdir(path);
}

void executeHiding(Node *list) {
    if(list == NULL)
        return;
//    FILE *file_txt;
//    FILE *file_output;
//    FILE *file_img = fopen(getNameFileBmp(list), "rb");
    char *file_txt = getNameFileTxt(list);
    char *file_img = getNameFileBmp(list);

    char *file_output;
    {
        /*
        //Controllo i nomi dei file
        if (file_img == NULL) {
            printf("The image input file is not present in the current directory.\n");
            return 1;
        }
    //    if (getNameFileTxt(list) == NULL)
    //        file_txt = stdin;
    //    else
    //        file_txt = fopen(getNameFileTxt(list), "rb");
        if(file_txt == NULL)
    //
    //    int length_of_output = lengthFileCheck(file_img, file_txt);
    //    fseek(file_txt, 0, SEEK_SET);
    //    fseek(file_img, 0, SEEK_SET);
    //
    //    if (length_of_output == -1)
    //        return 1;
    //
         */
        //removeElement(list);
    }
    //Creo la stringa, ovvero il nome del file di output.
    //Avrà lo stesso nome del file txt, modifico la stringa sostituendo l'estensione del file.
    char name_file_output[MAX_LENGTH_STRING];
    strcpy(name_file_output, getNameFileTxt(list));
    name_file_output[strlen(getNameFileTxt(list)) - 4] = '\0';
    strcat(name_file_output, ".bmp");
    //file_output = fopen(name_file_output, "wb");
    strcpy(list->name_file_generate, name_file_output);
/*
    //Creo una copia byte a byte dell'immagine originale
    for (int index = 0; index < length_of_output; index++) {
        byte B;
        fread(&B, 1, sizeof(byte), file_img);
        fwrite(&B, 1, sizeof(byte), file_output);
    }
*/
    createThread(list);
    //hiding(list);

    executeHiding (removeElement(list));
    //return 0;
}


int executeUnveiling(Node *list) {
    {
//    FILE *file_img = fopen(getNameFileBmp(list), "rb");
//    FILE *file_output;
//    if (file_img == NULL) {
//        printf("The image input file is not present in the current directory.\n");
//        return 1;
//    }
    }
    //Creo la stringa, ovvero il nome del file di output.
    //Avrà lo stesso nome del file bmp, modifico la stringa sostituendo l'estensione del file.
    char name_file_output[MAX_PATH];
    strcpy(name_file_output, getNameFileBmp(list));
    name_file_output[strlen(getNameFileBmp(list)) - 4] = '\0';
    strcat(name_file_output, ".txt");
    //file_output = fopen(name_file_output, "ab");

    unveiling(getNameFileBmp(list), name_file_output);
    return 0;
}