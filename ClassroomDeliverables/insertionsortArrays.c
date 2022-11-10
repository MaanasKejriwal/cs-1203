//Given an array (assume int) sort the array using Selection Sort

//Algorithm:
//1. Check which element is lesser between first and second index elements
//2. If element 2 is lesser, swap and store new element at first position in sub array
//3. Check element 2 and 3 in the same way and swap if needed, and store in same sub array
//4. Keep swapping and placing, and while placing the element needs to be compared with the sub array and placed in it accordingly

#include <stdio.h>

void swapelements(int checker2, int arr2[], int a){     //function that swaps the elements (during sorting)
    while(checker2 < arr2[a] && a >= 0){                //Checker loop
        arr2[a + 1] = arr2[a];                          //swaps elements
        a = a - 1;                                      //decreases a by 1
    }
    arr2[a + 1] = checker2;
}

void SortArray(int arr1[], int len) {           //Sorting using insertion sort
    for (int k = 1; k < len; k++) {             //counter loop
        int checker1 = arr1[k];                 //starts with a temp variable to traverse the array
        int a = k - 1;                          //previous index value

        swapelements(checker1, arr1, a);        //sends values to swapelements function
    }
}

void ArrayDisplay(int arr1[], int len) {          //function to display sorted array
    for (int a = 0; a < len; a++) {               //checker loop to make it terminable
        printf("%d ", arr1[a]);           //prints array
    }
    printf("\n");
}

int main() {                                    //main function
    int values[] = {9, 5, 1, 4, 3};             //pre-defined array as per instructions, can be any array
    printf("Original Array: ");
    int len1 = sizeof(values) / sizeof(values[0]);  //len of original array
    ArrayDisplay(values, len1);                     //displays original array for reference
    int len2 = sizeof(values) / sizeof(values[0]);  //len of new array
    SortArray(values, len2);                        //sorts new array
    printf("Sorted array in ascending order: ");    //displays new array
    ArrayDisplay(values, len2);
}
