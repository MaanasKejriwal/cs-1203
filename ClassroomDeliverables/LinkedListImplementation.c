//Implementation of a Linked List: Given a set of values (assume int), create a linked list from them

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
}*startnode;

void listPrint()
{
    struct node *chkr;
    if(startnode == NULL)
    {
        printf("Empty List!"); //error if empty list
    }
    else
    {
        chkr = startnode;
        while(chkr != NULL)
        {
            printf(" Value : %d\n", chkr->number);  //ask for the value of the node
            chkr = chkr->next;
        }
    }
}

void linkedList(int n)
{
    struct node *fnNode, *chkr;
    int number, i;
    startnode = (struct node *)malloc(sizeof(struct node));

    if(startnode == NULL)
    {
        printf("Node is NULL");
    }
    else
    {


        printf("Input value for node 1 : ");
        scanf("%d", &number);
        startnode->number = number;
        startnode->next = NULL;
        chkr = startnode;

        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf("Memory is NULL");
                break;
            }
            else
            {
                printf("Enter value for node %d : ", i);
                scanf(" %d", &number);

                fnNode->number = number;
                fnNode->next = NULL;

                chkr->next = fnNode;
                chkr = chkr->next;
            }
        }
    }
}



void linkedList(int n); 
void listPrint();         

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    linkedList(n);
    printf("\n Here is your Linked List : : \n");
    listPrint();
    return 0;
}
