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
    printf("/changeDirectory:\tChange the current directory to the one passed by param.\n");
    printf("/terminate:\tTerminate the program execution.\n");
    printf("/createTXT:\tCreate a new txt file in the current directory.\n");
    printf("/updateTXT:\tUpdate a TXT file in the current directory.\n");
    printf("/currentPath:\tShow the path of current directory.\n");
    return;
};

//TODO
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

//TODO
/**
 * This method terminate the program execution.
 */
void terminate(){
    _Exit(0);
}

//TODO
/**
 * This method create a new txt file in the current directory.
 */
void createTXT(){

}

//TODO
/**
 * This method update a TXT file in the current directory.
 * @param TXT
 */
void updateTXT(FILE *TXT){

}

//TODO
/**
 * This method return the current path.
 * @return
 */
const char currentPath(){

}