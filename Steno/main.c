#include "commandList.h"

int main() {

    int choice;
    do {
        help();
        scanf("%d", &choice);
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
                printf("Command not found.\n\n");
                break;
        }
    } while (choice != 0);

    return 0;
}