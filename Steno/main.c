#include "commandList.h"
#define PAUSE getchar();getchar();
int main() {

    char a[MAX_LENGTH_STRING], b[MAX_LENGTH_STRING];
    Node* list = insertByInput(1);
    printList(list);
    return 0;
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
                break;
            case 2:
                showContent();
                break;
            case 3:
                changeDirectory();
                break;
            case 4:
                createTXT(inputNameFile(1));
                break;
            case 5:
                printTXT(inputNameFile(1));
                break;
//            case 6:
//                executeHiding(inputNameFile())
//                system("pause");
//                break;
//            case 7:
//                system("pause");
//                break;
            case 0:
                terminate();
                break;
            default:
                perror("Command not found.\n");
                break;
        }
    } while (choice != 0);
*/