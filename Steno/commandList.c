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

    //Creo la stringa, ovvero il nome del file di output.
    //Avrà lo stesso nome del file txt, modifico la stringa sostituendo l'estensione del file.
    char name_file_output[MAX_LENGTH_STRING];
    strcpy(name_file_output, getNameFileTxt(list));
    name_file_output[strlen(getNameFileTxt(list)) - 4] = '\0';
    strcat(name_file_output, ".bmp");

    strcpy(list->name_file_generate, name_file_output);
    createThreadHiding((void*) list);

    executeHiding (removeElement(list));
}


void executeUnveiling(Node *list) {

    //Creo la stringa, ovvero il nome del file di output.
    //Avrà lo stesso nome del file bmp, modifico la stringa sostituendo l'estensione del file.
    if(list == NULL)
        return;
    char name_file_output[MAX_PATH];
    strcpy(name_file_output, getNameFileBmp(list));
    name_file_output[strlen(getNameFileBmp(list)) - 4] = '\0';
    strcat(name_file_output, ".txt");
    strcpy(list->name_file_generate, name_file_output);


    createThreadUnveiling((void*) list);
    executeUnveiling(removeElement(list));

}