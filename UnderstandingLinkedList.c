#include <stdio.h>
#include <stdlib.h>

struct  Node
{
    int data;
    struct Node* next;
};

void traverseLinkedList(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    struct Node* head;
    struct Node* fourth;
    struct Node* second;
    struct Node* third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));


    //Link first and second Node
    head->data = 10;
    head->next = second;

    //linking second and third node
    second->data = 12;
    second->next = third;

    //linking third and fourth node
    third->data = 14;
    third->next = fourth;

    //terminating the linked list
    fourth->data = 16;
    fourth->next = NULL;

    //calling the traverse function 
    traverseLinkedList(head);
    return 0;
}
