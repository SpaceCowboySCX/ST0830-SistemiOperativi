#ifndef ST0830_O_S_PROJECT_COMMANDLIST_H
#define ST0830_O_S_PROJECT_COMMANDLIST_H

#include "list.h"
#define PAUSE getchar();getchar();break;
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
int changeDirectory();

/**
 * This method create a new txt file in the current directory.
 */
void createTXT(char *name_file);

/**
 * This method print a TXT file in the current directory.
 * @param TXT
 */
void printTXT(char *name_file);

/**
 * This method read file and execute the algorithm for Hiding.
 * @param Node
 *                  pass a list.
 * @return
 */
void executeHiding(Node *list);

/**
 * This method read file and execute the algorithm for unveiling.
 * @param Node
 *                  pass a list.
 * @return
 */
void executeUnveiling(Node *list);
//TODO polish
/**
 * This method terminate the program execution.
 */
void terminate();

#endif //ST0830_O_S_PROJECT_COMMANDLIST_H