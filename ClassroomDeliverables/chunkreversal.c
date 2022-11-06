// C program to reverse a linked list in chunks
#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int info;
    struct Node* after;
};

/* Reverses the linked list in groups of size chunk */
struct Node *reverse (struct Node *head, int chunk)
{
    if (!head)
        return NULL;

    struct Node* current = head;
    struct Node* after = NULL;
    struct Node* before = NULL;
    int count = 0;



    /*reverse first chunk nodes of the linked list */
    while (current != NULL && count < chunk)
    {
        after = current->after;
        current->after = before;
        before = current;
        current = after;
        count++;
    }


    if (after != NULL)
        head->after = reverse(after, chunk);


    return before;
}

void push(struct Node** head_ref, int new_info)
{

    struct Node* node_new =
            (struct Node*) malloc(sizeof(struct Node));

    node_new->info = new_info;


    node_new->after = (*head_ref);


    (*head_ref) = node_new;
}


void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->info);
        node = node->after;
    }
}


int main(void)
{

    struct Node* head = NULL;


    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("\nLinked list \n");
    printList(head);
    head = reverse(head, 3);

    printf("\nReversed Linked list \n");
    printList(head);

    return(0);
}

//reference:https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
