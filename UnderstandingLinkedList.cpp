#include <bits/stdc++.h>

using namespace std;

class Node{
public:    
int data;
Node* next;
};

void show(Node* ptr){
    while(ptr != NULL){
        cout<<"The element is"<<ptr->data;
        ptr = ptr->next;
    }
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;

    //allocate memory for four node in heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    /* Three blocks have been allocated dynamically.
    We have pointers to these three blocks as head,
    second and third    
    head         second         third
        |             |             |
        |             |             |
    +---+-----+     +----+----+     +----+----+
    | # | # |     | # | # |     | # | # |
    +---+-----+     +----+----+     +----+----+ 
    */

  // link head and second node
   head->data = 1;
   head->next = second;

   /* data has been assigned to the data part of first
    block (block pointed by the head). And next
    pointer of the first block points to second.
    So they both are linked.
 
    head         second         third
        |             |             |
        |             |             |
    +---+---+     +----+----+     +-----+----+
    | 1 | o----->| # | # |     | # | # |
    +---+---+     +----+----+     +-----+----+    
*/

//similarly link second node and third node
second->data = 2;
second->next = third;

//linking third and fourth node
third->data =3;
third->next = fourth;

//fourth is last node so will terminate the link list
fourth->data = 4;
fourth->next = NULL;

show(head); //calling the show method
return 0;

}