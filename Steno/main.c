#include "commandList.h"
#include "list.h"
int main(){
    char word[MAX_LENGTH_STRING];
    printf("Inserisci parola\n");
    scanf("%s", word);
    insert((char *) &word);


    printf("Inserisci parola\n");
    scanf("%s", &word);
    insert(&word);

    printf("Inserisci parola\n");
    scanf("%s", &word);
    insert(&word);


    printf("%c", readAndRemove());
    printf("%s", readAndRemove());
    printf("%s", readAndRemove());
    return 0;
}