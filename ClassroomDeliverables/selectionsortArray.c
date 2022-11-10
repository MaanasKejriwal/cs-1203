//selection sort of arrays

//algorithm:
//1. Entire list is traversed and smallest element is found
//2. Swap to first index
//3. Start from second position and do the same, finding least element and swapping
//4. Keep repeating until reaching end of list, list is sorted

#include "stdio.h"

void sortArray(int arr1[], int len){        //Actual selection sort function 
    int a, b, minposition;                  //declaration of variables

    for(a = 0; a < len-1;a++){              //checker loop
        minposition = a;                    //setting minposition
        for(b = a+1; b < len; b++)          //checker loop
            if(arr1[b] < arr1[minposition]) //checks if element in position b is less than current min element
                minposition = b;            //if it is, sets current index to min index

            if(minposition != a){             
                int temp = arr1[minposition];
                arr1[minposition] = arr1[a];
                arr1[a] = temp;}
    }
}

void arrayDisplay(int arr1[], int len){         //to display the array
    int a;                                      //initialisation
    for(a=0; a<len; a++)                        //checker loop (counter)
        printf("%d ", arr1[a]);         //prints array
    printf("\n");
}

int main(){                             
    int arr1[]= {43, 29, 75, 38, 1, 99};        //pre-defined array as per instructions, can be any array
    int len = sizeof(arr1)/sizeof(arr1[0]);     //sets len value
    sortArray(arr1, len);                       //sorts array
    printf("Sorted List: ");            
    arrayDisplay(arr1, len);                    //prints sorted array
    return 0;
}
