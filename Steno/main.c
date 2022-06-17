#include <stdlib.h>
#include "commandList.h"
#include <stdio.h>
#include "utilities.h"
#include "stenography.h"

#define PAUSE getchar();getchar();break;

int main() {
    int a = 0;
    hiding("/home/spacecowboys01/CLionProjects/ST0830-O.S.Project/test/input_img.bmp",
           "/home/spacecowboys01/CLionProjects/ST0830-O.S.Project/test/input_text.txt",
           "/home/spacecowboys01/CLionProjects/ST0830-O.S.Project/test/qw.bmp");

    unveiling("/home/spacecowboys01/CLionProjects/ST0830-O.S.Project/test/qw.bmp",
              "/home/spacecowboys01/CLionProjects/ST0830-O.S.Project/test/qw.txt");

    printTXT("/home/spacecowboys01/CLionProjects/ST0830-O.S.Project/test/qw.txt");
   /*
    int choice = 0;
    Node *l = NULL;
    do {
        help();
        fflush(stdin);
        scanf("%d", &choice);
        system("clear");
        switch (choice) {
            case 1:
                currentPath();
                PAUSE
            case 2:
                showContent();
                PAUSE
            case 3:
                changeDirectory();
                PAUSE
            case 4:
                createTXT(inputNameFile(1));
                PAUSE
            case 5:
                printTXT(inputNameFile(1));
                PAUSE
            case 6:
                l = insertByInput(1);
                executeHiding(l);
                PAUSE
            case 7:
                l = insertByInput(-1);
                executeUnveiling(l);
                PAUSE
            case 0:
                return 0;
            default:
                perror("Command not found.\n");
                PAUSE
        }
    } while (choice != 0);
     */
}






































/*
    int choice = 0;
    do {
        if(choice != 0)
            PAUSE
        help();
        fflush(stdin);
        scanf("%d", &choice);
        system("clear");
        switch (choice) {
            case 1:
                currentPath();
                PAUSE
            case 2:
                showContent();
                PAUSE
            case 3:
                changeDirectory();
                PAUSE
            case 4:
                createTXT(inputNameFile(1));
                PAUSE
            case 5:
                printTXT(inputNameFile(1));
                PAUSE
//            case 6:
//                executeHiding(inputNameFile())
//                system("pause");
//                PAUSE
//            case 7:
//                system("pause");
//                PAUSE
            case 0:
                terminate();
                PAUSE
            default:
                perror("Command not found.\n");
                PAUSE
        }
    } while (choice != 0);
*/