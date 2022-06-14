#include "commandList.h"

void help(){
    printf("Type 1) currentPath:\tShow the path of current directory.\n");
    printf("Type 2) showContent:\tShow the content of current directory.\n");
    printf("Type 3) changeDirectory:\tChange the current directory to the one passed by param.\n");
    printf("Type 4) createTXT:\tCreate a new txt file in the current directory.\n");
    printf("Type 5) printTXT:\tPrint a TXT file in the current directory.\n");
    printf("Type 6) executeHiding:\tExecute hiding Algorithm");
    printf("Type 7) executeUnveiling:\tExecute unveiling Algorithm");
    printf("Type 0) terminate:\tTerminate the program execution.\n");
}

void currentPath(){
    char current_path[MAX_PATH];
    if(getcwd(current_path, sizeof(current_path)) != NULL)
        printf("%s", current_path);
    else
        perror("Error: getcwd() error.\n");
}

int showContent(){
    DIR *directory;
    struct dirent *entry;
    int number_of_files = 0;

    directory = opendir(".");
    if(directory == NULL){
        perror("Unable to read this directory.\n");
        return 1;
    }
    while ((entry = readdir(directory))){
        number_of_files++;
        printf("File %2d:\t%s\n", number_of_files, entry->d_name);
    }
    closedir(directory);
    return 0;
}

int changeDirectory(const char *PATH){
    if(strlen(PATH) > MAX_PATH)
        return -1;
    //TODO check the path
    return chdir(PATH);
}


void createTXT(){
    char string[MAX_LENGTH_STRING];

    printf("Name's file:\t");
    scanf("%s", string);

    if(extensionFileCheck(string) != 1)
        fclose(fopen(string,"at"));
    else
        perror("Error: don't try to declare a txt file with another extension.\n");
}

void printTXT(){
    FILE *file_to_print;
    char string[MAX_LENGTH_STRING], character_to_print;

    printf("Name's file:\t");
    scanf("%s", string);

    //TODO check if exist
    if(extensionFileCheck(string) != 1) {
        file_to_print = fopen(string, "r");
        character_to_print = fgetc(file_to_print);

        while(character_to_print != EOF) {
            printf("%c", character_to_print);
            character_to_print = fgetc(file_to_print);
        }
        fclose(file_to_print);
    }
}

int executeHiding(char name_file_txt[MAX_LENGTH_STRING], char name_file_immagine[MAX_LENGTH_STRING]){
    /*Apertura file
    * Controllo lunghezza immagine
    * controllo lunghezza testo
    * !deve essere (Lunghezza)/8 < Lunghezza immagine!
    */

    FILE *file_txt;
    FILE *file_img;
    FILE *file_output;

    return 0;
}


int executeUnveiling(char name_file_immagine[MAX_LENGTH_STRING]){

    FILE *file_txt;
    FILE *file_img;
    FILE *file_output;

    return 0;
}


void terminate(){
    printf("Thanks!");
    _Exit(0);
}