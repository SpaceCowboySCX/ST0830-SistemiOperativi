#include "list.h"

Node *first_element;
Node *last_element;

void insert(char string_to_insert[MAX_LENGTH_STRING]) {
    if (last_element == NULL) {
        last_element = (Node *) malloc(sizeof(Node));
        strcpy(last_element->str, string_to_insert);
        first_element = last_element;
        //first_element->next = last_element;
    } else {
        Node *new_node = (Node *) malloc(sizeof(Node));
        strcpy(new_node->str, string_to_insert);
        last_element->next = new_node;
        if (first_element->next == NULL)first_element->next = last_element;
        last_element = last_element->next;
    }
}

char *readAndRemove() {
    static char result[MAX_LENGTH_STRING];
    if (first_element != NULL) {
        //result = (char *) firstElement->str;
        strcpy(result, first_element->str);
        first_element = first_element->next;
        return result;
    }
    return NULL;
}