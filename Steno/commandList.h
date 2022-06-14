#ifndef ST0830_O_S_PROJECT_COMMANDLIST_H
    #define ST0830_O_S_PROJECT_COMMANDLIST_H

    #include "utilities.h"
    #include <stdlib.h>
    #include <unistd.h>
    #include <dirent.h>

    #define MAX_PATH 200

    /**
     * This method explain the command for the line command interface.
     */
    void help();

    /**
     * This method return the current path.
     * @return
     */
    void currentPath();

    /**
     * This method show the content of the current path.
     * @return
     */
    int showContent();

    /**
     * This method change the current directory to the one passed by param.
     * @param PATH
     */
    int changeDirectory(const char *PATH);

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
     * This method read file and execute the algorithm for Hiding.
     * @param nome_file_txt
     * @param nome_file_immagine
     * @return  0 - success
     *          1 - fail
     */
    int executeHiding(char name_file_txt[MAX_LENGTH_STRING], char name_file_immagine[MAX_LENGTH_STRING]);

    /**
     * This method read file and execute the algorithm for unveiling.
     * @param nome_file_immagine
     * @return  0 - success
     *          1 - fail
     */
    int executeUnveiling(char name_file_immagine[MAX_LENGTH_STRING]);

    /**
     * This method terminate the program execution.
     */
    void terminate();
#endif //ST0830_O_S_PROJECT_COMMANDLIST_H