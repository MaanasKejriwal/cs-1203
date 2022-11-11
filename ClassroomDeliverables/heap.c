// Given an array, build a heap and sort it!

#include <stdio.h>

void createHeap(int arr[], int len, int a) {            //function to create heap
    int greatestElem = a;                               //find largest element
    int leftChild = 2 * a + 1;                          //checking left child
    int rightChild = 2 * a + 2;                         //checking right child

    if (leftChild < len && arr[leftChild] > arr[greatestElem])      //if leftchild is the greatest element condition
        greatestElem = leftChild;                                   //setting greatest element as left child

    if (rightChild < len && arr[rightChild] > arr[greatestElem])    //if rightchild is the greatest element condition
        greatestElem = rightChild;                                  //setting greatest element as right child

    if (greatestElem != a) {                                        //swap until a is not the greatest element
        int t = arr[a];                                             //swapping using a temp variable
        arr[a] = arr[greatestElem];
        arr[greatestElem] = t;
        createHeap(arr, len, greatestElem);                         //heap creation
    }
}

void sortMain(int arr[], int len) {                                 //main sorting function
    for (int a = len / 2 - 1; a >= 0; a--)
        createHeap(arr, len, a);                                    //heap creation

    for (int a = len - 1; a >= 0; a--) {                            //actual heap sort
        int t = arr[0];                                             //swapping elements
        arr[0] = arr[a];
        arr[a] = t;

        createHeap(arr, a, 0);                                  //heapification to get a
    }
}

void ArrayDisplay(int arr[], int len) {                             //function to display array
    for (int a = 0; a < len; ++a)
        printf("%d ", arr[a]);
    printf("\n");
}


int main() {                                                        //main function
    int data[] = {75, 24, 53, 86, 12, 43, 11, 0};                   //original array is pre-defined as per instructions, could be any random array
    int len = sizeof(data) / sizeof(data[0]);

    printf("Original Array: ");                                 //displaying original array for reference pre-sorting
    ArrayDisplay(data, len);

    sortMain(data, len);                                                //sorting

    printf("Array after sorting: ");
    ArrayDisplay(data, len);                                            //displaying sorted array
}
