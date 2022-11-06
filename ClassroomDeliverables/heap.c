#include<stdio.h>
#include<limits.h>

/* Heap declared globally */

int heap[1000000], size;

void Init() {
    size = 0;
    heap[0] = -INT_MAX;
}

/*To insert heap elem */
void Insert(int elem) {
    size++;
    heap[size] = elem; /*Insert in the -1 position*/
    int current = size;
    while (heap[current / 2] > elem) {
        heap[current] = heap[current / 2];
        current /= 2;
    }
    heap[current] = elem;
}

int DeleteMin() {
    /* Since heap[1] is the minimum elem, it is removed. We put the last elem in its place and see if it fits.
     If it doesn't fit, take min elem among its children replacing parent with it.
     Process repeats.*/
    int minElement, lastElement, child, current;
    minElement = heap[1];
    lastElement = heap[size--];
    /* index counter */
    for (current = 1; current * 2 <= size; current = child) {
        /* Indexes of children are i*2 and i*2 + 1*/
        child = current * 2;
        /*child is not size because heap[size+1] doesn't exist, (has only one
         child) */
        if (child != size && heap[child + 1] < heap[child]) {
            child++;
        }

        if (lastElement > heap[child]) {
            heap[current] = heap[child];
        } else /* Fits */
        {
            break;
        }
    }
    heap[current] = lastElement;
    return minElement;
}

int main() {
    int elemnum;
    printf("Program to demonstrate Heap:\nEnter the number of elements: ");
    scanf("%d", &elemnum);
    int i, elem;
    Init();
    printf("Enter the elements: ");
    for (i = 0; i < elemnum; i++) {
        scanf("%d", &elem);
        Insert(elem);
    }
    for (i = 0; i < elemnum; i++) {
        printf("%d ", DeleteMin());
    }
    printf("\n");
    return 0;
}

//reference: https://www.sanfoundry.com/c-program-implement-heap/
