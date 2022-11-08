//
// Created by Maanas on 11/8/2022.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct node{        //defining the structure of a node, and calling it a node
    int value;              //actual value in the node
    struct node *nextadd;   //pointer to address of next node
}node;                      //referential

node * creation(int len);

void listdisplay(node * head);


int main(){                                             //for len of node
    int len = 0;                                        //initialise length as 0
    node * HEAD = NULL;                                 //first node value initialised
    printf("Enter number of nodes: \n");        //input for number of nodes
    scanf("%d", &len);
    HEAD = creation(len);
    listdisplay(HEAD);
    return 0;



    return 0;
}

node * creation(int len){
    int a = 0;
    node * head = NULL;
    node * temp = NULL;
    node * p = NULL;

    for(a=0; a< len; a++)
    {
        temp = (node*)malloc(sizeof(node));
        printf("\nEnter data for node: ", a+1);
        scanf("%d",&(temp->value));
        temp->nextadd = NULL;

        if(head == NULL)
        {
            head = temp;
        }
        else{
            p = head;
            while(p->nextadd !=NULL)
                p = p->nextadd;
            p-> nextadd= temp;

        }

    }
    return head;
}

void listdisplay(node * head){
    node * p = head;

    while(p != NULL) {
        printf("\t%d->", p->value);
        p = p->nextadd;
    }
    }

