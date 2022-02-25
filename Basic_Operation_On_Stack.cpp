/*
A stack is a linear data structure. Any operation on the stack is performed in LIFO
(Last In First Out) order. This means the element to enter the container last would be
the first one to leave the container.

Some of the basic operations we would want to perform on stacks:
    1. push(): to push an element into the stack
    2. pop(): to remove the topmost element from the stack
    3. peek(index): to return the value at a given index
    4. isempty() / isfull() : to determine whether the stack is empty or full to carry
       efficient push and pull operations.


*/

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

/*************************Checking whether stack is empty or not****************************/
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

/*************************Checking whether stack is full or not****************************/
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*************************Logic to perform the push operation****************************/
int push(struct stack *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("The stack is full- StackOverflow");
        return -1;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
        return element;
    }
}

/*************************Logic to perform the pop operation****************************/
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The is stack is empty \n");
        return -1;
    }
    else
    {
        int element = ptr->arr[ptr->top];
        ptr->top--;
        return element;
    }
}

/*************************Logic to perform the peek operation****************************/
int peek(struct stack *ptr, int i){
    int index = ptr->top - i +1;
    if(index<0){
        printf("This is not valid postion in the stack\n");
        return -1;
    }
    else{
        return ptr->arr[index];
    }
}

/*************************Logic to perform the peekTop operation**************************/
int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}


int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    
    // before pushing any element
    printf("\n*****************************************************\n");
    printf("The stack is created succcessfully\n");

    // before pusshing any element
    printf("Is the stack Full? 1-Yes and 0-No: %d\n", isFull(sp));
    printf("Is the stack Empty?1-Yes and 0-No: %d\n", isEmpty(sp));

    printf("\n*****************************************************\n");
    printf("We are pusing elements to stack:\n");
    printf("Pushing 2 to the stack....\n");
    push(sp, 2);
    printf("Pushing 3 to the stack....\n");
    push(sp, 3);
    printf("Pushing 4 to the stack....\n");
    push(sp, 4);
    printf("Pushing 5 to the stack....\n");
    push(sp, 5);
    printf("Pushing 6 to the stack....\n");
    push(sp, 6);
    printf("Pushing 7 to the stack....\n");
    push(sp, 7);

    // after pusshing any element
    printf("\n*****************************************************\n");

    printf("The stack status after pushing some elements:\n");
    printf("Is the stack Full? 1-Yes and 0-No: %d\n", isFull(sp));
    printf("Is the stack Empty?1-Yes and 0-No: %d\n", isEmpty(sp));

    // performing the pop operation
    printf("\n*****************************************************\n");
    printf("The element %d is popped from the stack.\n", pop(sp));
    printf("The element %d is popped from the stack.\n", pop(sp));

    // performing the peek operation
    printf("\n*****************************************************\n");
        // Printing values from the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }

    // performing the stackTop operation
    printf("\n*****************************************************\n");
    printf("The top element using stackTop is: %d\n", stackTop(sp));

    // performing the stackBottom operation
    printf("\n*****************************************************\n");
    printf("The bottom element using stackBottom is: %d\n",stackBottom(sp));


    return 0;
}