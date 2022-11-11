//Quicksort of array and linked list

//Algorithm:
//1. Pick a random element from the list and swap it with the 0’th element (first position). We call this element the pivot element
//2. Generate two new lists - lesser and greater
//3. Compare every element in the list with the pivot element and push it into the corresponding list (if greater than pivot, add to greater list and so on)
//4. We now combine the lists in the following way lesser - pivot - greater. Now, we have obtained the correct, sorted rank of the pivot element! (everything in lesser list is lower than the pivot value and everything in the greater list is larger than the pivot value)
//5. Now we can sort the lesser list and greater list individually using the same algorithm as above. i.e. repeat steps 1-4 for the lesser list and greater list simultaneously

#include "stdio.h"

int splitHere(int array[], int left, int right) {       //This is to find where to partition the array

    int pivotElement = array[right];        //choosing current index -1th element as the pivot

    int pt = (left - 1);                    //pointer

    for (int checker = left; checker < right; checker++) {      //This will lead to array traversal and comparison with pivotElement
        if (array[checker] <= pivotElement) {

            pt = pt + 1;                //if smaller element, swap

            int temp = array[pt];               //swapping using a temporary variable
            array[pt] = array[checker];
            array[checker]= temp;
        }
    }

    int temp = array[pt+1];                     //swapping pivot with the element
    array[pt+1] = array[right];
    array[right] = temp;                        //swapping using temp variable

    return (pt + 1);                            //partition index
}

void quickSort(int array[], int left, int right) {      //quicksort main function
    if (left < right) {

        int pivotElement = splitHere(array, left, right);           //defining pivot element: left of pivot = less than pivot, right of pivot = more than pivot

        quickSort(array, left, pivotElement - 1);               //to find elements less than pivot

        quickSort(array, pivotElement + 1, right);              //to find elements right of pivot
    }
}

void ArrayDisplay(int array[], int len) {                           //displaying Array
    for (int a = 0; a < len; ++a) {
        printf("%d  ", array[a]);
    }
}

int main() {
    int arr[] = {43, 9, 25313, 91, 11, 65, 78, 23};         //using pre-defined array as per instructions, could be any array

    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    ArrayDisplay(arr, len);                                 //printing defined array as pre-sort reference

    quickSort(arr, 0, len - 1);                   //quicksort using element at index 0 and index -1

    printf("\n");
    printf("Sorted Array using Quick Sort: ");
    ArrayDisplay(arr, len);                                 //printing sorted array
}
