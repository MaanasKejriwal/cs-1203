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
    HEAD = creation(len);                       //creates list
    listdisplay(HEAD);                          //displays list
    return 0;



    return 0;
}

node * creation(int len){               //list creation function
    int a = 0;                          //initialisation of temp variables
    node * head = NULL;                 //Start
    node * temp = NULL;                 //temp
    node * p = NULL;                    

    for(a=0; a< len; a++)           //checker 
    {
        temp = (node*)malloc(sizeof(node));         //allocating space for temp
        printf("\nEnter data for node: ", a+1);     //Inputs node data
        scanf("%d",&(temp->value));                 //stores in next address 
        temp->nextadd = NULL;                       //makes it null

        if(head == NULL)                            //checker
        {
            head = temp;                            //changes head value to temp value
        }
        else{
            p = head;   
            while(p->nextadd !=NULL)
                p = p->nextadd;
            p-> nextadd= temp;

        }

    }
    return head;                                   //returns head value
}

void listdisplay(node * head){                    //display list function
    node * p = head;

    while(p != NULL) {                              
        printf("\t%d->", p->value);              //formats and display a linked list
        p = p->nextadd;
    }
    }

