// Binary Search Tree

//Algorithm for binary search:
//Let us say we want to find an element x in an array
//We compare x with the middle element of the array
//If x is less than the middle element, we search in the first half of the array, and if not then the right
//There is a small chance we find that the middle element is itself x, which is where we stop the search in this case
//We keep halving the array in this way until we find the element

//For binary search tree:
//It is the same, but we go root by root, getting rid of them as we traverse


#include <stdio.h>
#include <stdlib.h>

struct Node {               //defining a node in the array
    int data;               //value
    struct Node *left, *right;
};


struct Node *addedNode(int elem) {          //adding a node
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));        //allocation of space
    t->data = elem;                                     //assigning value elem to next node value
    t->left = t->right = NULL;                          //assigning NULL to right and left
    return t;
}


void traverse(struct Node *val) {               //traversing the tree
    if (val != NULL) {                          //making sure elements are not over (runs until they are)
        traverse(val->left);                    //checking variables left of selected
        printf("%d -> ", val->data);
        traverse(val->right);                   //checking variables right of selected
    }
}

struct Node *add(struct Node *Node, int data) {         //new node
    if (Node == NULL) return addedNode(data);           //if empty tree, the node is returned
    if (data < Node->data)                              //if current element is less than next value
        Node->left = add(Node->left, data);             //data is added to node left of current
    else
        Node->right = add(Node->right, data);           //same but on right side (more than)

    return Node;
}

struct Node *leastNode(struct Node *Node) {             //checking lowest
    struct Node *active = Node;
    while (active && active->left != NULL)              //finding the extreme left element
        active = active->left;
    return active;
}

struct Node *delete(struct Node *val, int data) {   //node deletion
    if (val == NULL) return val;                    //to check if there are any elements in the tree
    if (data < val->data)                           //to look for the node that must be deleted
        val->left = delete(val->left, data);        //deletion
    else if (data > val->data)
        val->right = delete(val->right, data);

    else {                                          //if node has no further branches
        if (val->left == NULL) {
            struct Node *t = val->right;
            free(val);
            return t;
        } else if (val->right == NULL) {
            struct Node *t = val->left;
            free(val);
            return t;
        }

        struct Node *t = leastNode(val->right);
        val->data = t->data;                               // Place the next branch replacing the deleted node
        val->right = delete(val->right, t->data);           //deleting the node
    }
    return val;
}

int main() {                    //main functiom
    struct node *val = NULL;
    val = add(val, 274);   //adding some arbitrary values to the array (pre-defined list); could be any random array
    val = add(val, 2472);
    val = add(val, 85);
    val = add(val, 539);
    val = add(val, 9);
    val = add(val, 429);
    val = add(val, 95);
    val = add(val, 72);

    printf("Traversing the Array: ");
    traverse(val);                              //current binary search tree

    printf("\nArray post deleting a random element (429): \n");     //deletion
    val = delete(val, 429);
    printf("New traversal of array: ");
    traverse(val);
}