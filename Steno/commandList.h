#ifndef ST0830_O_S_PROJECT_COMMANDLIST_H
    #define ST0830_O_S_PROJECT_COMMANDLIST_H

    #include "utilities.h"
    #include <stdlib.h>
    #include <unistd.h>

    #define MAX_PATH 200

    /**
     * This method explain the command for the line command interface.
     */
    void help();

    /**
     * This method change the current directory to the one passed by param.
     * @param PATH
     */
    int changeDirectory(const char *PATH);

    /**
     * This method terminate the program execution.
     */
    void terminate();

    /**
     * This method create a new txt file in the current directory.
     */
    void createTXT();

    /**
     * This method print a TXT file in the current directory.
     * @param TXT
     */
    void printTXT(const char *txtName);

    /**
     * This method return the current path.
     * @return
     */
    void currentPath();

    void executeHiding();

    void executeUnveiling();
#endif //ST0830_O_S_PROJECT_COMMANDLIST_H