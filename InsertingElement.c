/*
A c-program to demonstrate insertion of element (at begining, at end and at specified location)
in a linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

void displayLinkedList(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


struct Node* InsertAtStart(struct Node* head, int data){

    //allocate memory for element Node in the linked list in Heap
    struct Node* element = (struct Node*) malloc(sizeof(struct Node));
    element->data = data;
    element->next = head;

    return element;
}

struct Node* InsertAtIndex(struct Node* head, int data, int index){
    //allocate memory for element Node in the linked list in Heap
    struct Node* element = (struct Node*) malloc(sizeof(struct Node));
    struct Node* p = head; // declare a pointer pointing to head element

   int i=0;
    while(i != index-1){ 
        p= p->next;
        i++;
    }

    element->data = data;
    element->next = p->next;
    p->next = element;

    return head;
}


int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node* ) malloc(sizeof(struct Node));
    second = (struct Node* ) malloc(sizeof(struct Node));
    third = (struct Node* ) malloc(sizeof(struct Node));
    fourth = (struct Node* ) malloc(sizeof(struct Node));

    //linking first and second Node
    head->data = 12;
    head->next = second;

    //linking second and third Node
    second->data = 14;
    second->next = third;

    //linking third and fourth Node
    third->data = 16;
    third->next = fourth;

    //terminating the linked list
    fourth->data = 18;
    fourth->next = NULL;

    //calling the display function 
    displayLinkedList(head);
    //head = InsertAtStart(head, 10);
    head = InsertAtIndex(head, 21, 3);
    displayLinkedList(head);
    return 0;
}


