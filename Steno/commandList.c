#include "commandList.h"

void help(){
    printf("Type 1) currentPath:\tShow the path of current directory.\n");
    printf("Type 2) showContent:\tShow the content of current directory.\n");
    printf("Type 3) changeDirectory:\tChange the current directory to the one passed by param.\n");
    printf("Type 4) createTXT:\tCreate a new txt file in the current directory.\n");
    printf("Type 5) checkTXT:\tPrint a TXT file in the current directory.\n");
    printf("Type 6) executeHiding:\tExecute hiding Algorithm");
    printf("Type 7) executeUnveiling:\tExecute unveiling Algorithm");
    printf("Type 0) terminate:\tTerminate the program execution.\n");
}

int changeDirectory(const char *PATH){
    if(strlen(PATH) > MAX_PATH)
        return -1;
    //TODO check the path
    return chdir(PATH);
}

void terminate(){
    printf("Thanks!");
    _Exit(0);
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

//void printTXT(){
//    FILE *fileToPrint;
//    char string[MAX_LENGTH_STRING], characterToPrint;
//
//    printf("Name's file:\t");
//    scanf("%s", string);
//
//    //TODO check if exist
//    if(extensionFileCheck(string) != 1) {
//        fileToPrint = fopen(string, "r");
//        characterToPrint = fgetc(fileToPrint);
//
//        while(characterToPrint != EOF) {
//            printf("%c", characterToPrint);
//            characterToPrint = fgetc(fileToPrint);
//        }
//        fclose(fileToPrint);
//    }
//}


void currentPath(){
    char currentPath[MAX_PATH];
    if(getcwd(currentPath, sizeof(currentPath)) != NULL)
        printf("%s", currentPath);
    else
        perror("Error: getcwd() error.\n");
}

void executeHiding(){
    /*Apertura file
    * Controllo lunghezza immagine
    * controllo lunghezza testo
    * !deve essere (Lunghezza)/8 < Lunghezza immagine!
    */
}