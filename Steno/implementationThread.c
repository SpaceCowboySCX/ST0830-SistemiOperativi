#include "implementationThread.h"
#include "stenography.h"

pthread_t threadId;
//int i = 0;

void createThread(Node* list){
    pthread_create(&threadId, NULL, (void *) hiding, (void*) list);
//    i++;
}