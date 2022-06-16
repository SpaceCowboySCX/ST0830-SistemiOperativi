#include "list.h"

Node* insert(Node* first_element, char name_file_txt[], char name_file_bmp[])
{
    if(first_element == NULL)
    {
        first_element = (Node*)malloc(sizeof (Node));
        strcpy(first_element->name_file_txt, name_file_txt);
        strcpy(first_element->name_file_bmp, name_file_bmp);
        return first_element;
    }
    else
    {
        if(first_element->next == NULL)
        {
            first_element->next = (Node*)malloc(sizeof (Node));
            strcpy(first_element->next->name_file_txt, name_file_txt);
            strcpy(first_element->next->name_file_bmp, name_file_bmp);
            return first_element;
        }
        Node* tmp = first_element;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = (Node*)malloc(sizeof (Node));
        strcpy(tmp->next->name_file_txt, name_file_txt);
        strcpy(tmp->next->name_file_bmp, name_file_bmp);
        return first_element;
    }
}

char* getNameFileTxt(Node* first_element)
{
    if(first_element != NULL) {
        return first_element->name_file_txt;
    }
    return NULL;
}

char* getNameFileBmp(Node* first_element)
{
    if(first_element != NULL) {
        return first_element->name_file_bmp;
    }
    return NULL;
}

Node* removeElement(Node* first_element)
{
    if(first_element != NULL){
        first_element = first_element->next;
        return first_element;
    }
    return NULL;
}

Node* getNext(Node* element)
{
    return element->next;
}



Node* getLastElement(Node* first_element)
{
    Node* tmp = first_element;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    return tmp;
}

void printList(Node *element)
{
    if(element ==NULL)
        return;
    printf("\nStampo: %s", getNameFileTxt(element));
    printf("\nStampo: %s", getNameFileBmp(element));
    if(getNext(element) != NULL)
        printList(getNext(element));
}
//ESEMPIO USO LISTA
//    Node* list = NULL;
//    list = insert(list, "1", "2");
//    list = insert(list, "3", "4");
//    list = insert(list, "5", "6");
//    list = insert(list, "7", "8");
//
//    while(list != NULL)
//    {
//        printf("\nStampo: %s", getNameFileTxt(list));
//        printf("\nStampo: %s", getNameFileBmp(list));
//        printf("\n-----------------------------------------------------------------");
//        list = removeElement(list);
//    }



