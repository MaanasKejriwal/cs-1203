#include <stdio.h>
#include "cstdlib"


struct node{                    //defines node structure
    int value;
    struct node *nextadd;
};


struct node *head, *tail = NULL;    //first and last node of linked list


void NodeCreate(int value) {       //creation of node
    struct node *addedNode = (struct node*)malloc(sizeof(struct node));       //allocates space for next node
    addedNode->value = value;         //saves value 'value' in node
    addedNode->nextadd = NULL;        //sets address as NULL


    if(head == NULL) {          //checking for empty list
        head = addedNode;         //empty list leads to head and tail being the same
        tail = addedNode;
    }
    else {          //sets next node as tail node
        tail->nextadd = addedNode; //sets address
        tail = addedNode;
    }
}

void swapvalues(struct node *currentval, struct node * indexval, int tempstore1){        //function that swaps values within sorting
    if(currentval->value > indexval->value) {                                       //checks if current's next value is greater that counter value
        tempstore1 = currentval->value;                                                  //if it is, stores val in temp variable
        currentval->value = indexval->value;                                        //stores next val from current val in counter's next val
        indexval->value = tempstore1;                                                    //sets next val from counter val to temp1
    }
}



void sortList() {                       //actual sort function
    struct node *currentnode = head, *nodeindex = NULL;     //current node starts with head node as it is the first
    int tempstore;                           //initialising temp variable

    if(head == NULL) {                  //checks for empty linked list
        return;
    }
    else {                              //if list has not empty then:
        while(currentnode != NULL) {        //if list has not ended then:
            nodeindex = currentnode->nextadd;   //pointer at node after current node

            while(nodeindex != NULL) {      //checks if current node is the last node = tail
                //If current node's value is greater than index's node value, swap the value between them
                swapvalues(currentnode, nodeindex, tempstore);           //calls swap function, swaps if discrepancy in order
                nodeindex = nodeindex->nextadd;                     //sets index to next index and loops if required
            }
            currentnode = currentnode->nextadd;                     //sets current address to address of next node
        }
    }
}


void DisplayList() {                        //displays linked list
    struct node *currentnode = head;    //head pointer
    if(head == NULL) {                  //checks if list is empty
        printf("List is empty \n");
        return;
    }
    while(currentnode != NULL) {            //keeps running until the list ends
        printf("%d ", currentnode->value);
        currentnode = currentnode->nextadd; //sets current node address to next node address
    }
    printf("\n");
}

int main()
{
    NodeCreate(647);            //setting values for list (could be inputted by user but instructions say given linked list)
    NodeCreate(782);
    NodeCreate(130);
    NodeCreate(809);
    NodeCreate(503);
    
    printf("Original list: ");
    DisplayList();              //shows original list to compare with new one as reference
    
    sortList();                 //list sorted
    
    printf("Sorted list: ");
    DisplayList();      //displays sorted list

    return 0;
}

//This was so exhausting
