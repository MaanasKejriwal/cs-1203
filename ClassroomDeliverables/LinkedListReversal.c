// Given head pointer of a linked list, reverse the list.
#include <stdio.h>
#include <stdlib.h>

struct Node {           //defines structure of node
    int val;            //value of node
    struct Node* next;      //address of node
};


static void reverse(struct Node** heads)        //reversal function
{
    struct Node* prev = NULL;                   //defines previous node
    struct Node* current = *heads;              //current
    struct Node* next = NULL;                   //next
    while (current != NULL) {                   //checker

        next = current->next;                   //assigns value of 'next' to next of current


        current->next = prev;                   //changes value of next of current to previous value


        prev = current;                         //changes prev to current
        current = next;                         //current to next
    }
    *heads = prev;
}


void push(struct Node** heads, int datanew)
{
    struct Node* new_node
            = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = datanew;
    new_node->next = (*heads);
    (*heads) = new_node;
}


void printList(struct Node* head)           //prints the list
{
    struct Node* temp = head;               //defines node
    while (temp != NULL) {                  //checker
        printf("%d ", temp->val);       //prints value next of temp
        temp = temp->next;                     //sets temp to value next of temp
    }
}


int main()                              //main function
{

    struct Node* head = NULL;

    push(&head, 20);            //puts values into linked list, can be any values
    push(&head, 4);             //value 1
    push(&head, 15);            //value 2
    push(&head, 85);            //value 3

    printf("Initial linked list\n");
    printList(head);            //prints initial linked list (given list like the question asks rather than input)
    reverse(&head);             //reverses
    printf("\nReversed linked list \n");        //prints reversed linked list
    printList(head);
    getchar();
}
