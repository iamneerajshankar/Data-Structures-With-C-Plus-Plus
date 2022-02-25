#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int  data;
    Node* next;
};

void showLinkedList(Node* ptr){
    cout<<"The elements of the linked list are: ";
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void InsertAtStart(Node **head, int new_data){
     //allocate memory for new node to be inserted
     Node* new_node = new Node();

     new_node->data = new_data;
     new_node->next = *head;
     return ;

}

void InsertAtIndex(Node* insertionNode, int new_data){
 if(insertionNode == NULL){
     cout<<"The at which data to be inserted cannot be NULL"<<endl;
     return;
 }

 //allocate memory for new node to be inserted
 Node* new_node = new Node();

 // put data in new node
 new_node->data = new_data;

 // 4. Make next of new node as next of insertionNode
 new_node->next = insertionNode->next;

 //move the next of prev_node as new_node
 insertionNode->next = new_node;
}

int main(){
    //create pointer for each node
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //allocate memory for each node in heap
    head = new Node();
    second = new Node();
    third = new Node();

    // link head and second node
    head->data = 1;
    head->next = second;

    // link second and third node
    second->data = 2;
    second->next = third;

    // third is last node so terminate it
    third->data = 4;
    third->next = NULL;

    //calling the show function
    InsertAtIndex(second, 3); // passing second node will insert new node after second
    showLinkedList(head);

    InsertAtStart(&head, 9);
    showLinkedList(head);

    return 0;
    
}