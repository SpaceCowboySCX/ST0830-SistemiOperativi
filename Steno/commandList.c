#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "commandList.h"

#define MAX_PATH 200

//TODO
/**
 * This method explain the command for the line command interface.
 */
void help(){

    printf("Type 1) currentPath:\tShow the path of current directory.\n");
    printf("Type 2) showContent:\tShow the content of current directory.\n");
    printf("Type 3) changeDirectory:\tChange the current directory to the one passed by param.\n");
    printf("Type 4) createTXT:\tCreate a new txt file in the current directory.\n");
    printf("Type 5) updateTXT:\tUpdate a TXT file in the current directory.\n");
    printf("Type 0) terminate:\tTerminate the program execution.\n");
}

/**
 * This method change the current directory to the one passed by param.
 * @param PATH
 *
 * @return -1: error - @param PATH too long
 */
int changeDirectory(const char *PATH){
    if(strlen(PATH) > MAX_PATH)
        return -1;

    return chdir(PATH);
}

/**
 * This method terminate the program execution.
 */
void terminate(){
    _Exit(0);
}

/**
 * This method create a new txt file in the current directory.
 */
void createTXT(){
    const char *txtName;
    printf("Name's file:\t");
    scanf("%s",&txtName);

    fclose(fopen(txtName,"a"));
}

/**
 * This method update a TXT file in the current directory.
 * @param TXT
 */
void updateTXT(const char *txtName){

}

//TODO
/**
 * This method return the current path.
 * @return
 */
const char currentPath(){

}