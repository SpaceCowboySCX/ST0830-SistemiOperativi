#include "utilities.h"
#include "string.h"
int main(){
    char str[255];
    printf("Inserire i file separati da uno spazio\n");
    scanf("%s\n", str);
//    printf("stampa: %s", str);
    char array;
    array = split(str);
    printf("Inserire i file separati da uno spazio\n");
    for(int i = 0; i < 10; i=i+1)
    {
        printf("stampa: %s", &array[i]);
    }

    return 0;
}