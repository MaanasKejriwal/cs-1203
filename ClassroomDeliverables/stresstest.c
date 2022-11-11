#include<stdio.h>

int main(){

    float a;
    float increase = 0.0000000000000000001;
    float ln = 0.000000000000001; //Here is where an extra loop shows up
    int counter = 1;

    for (a=0.0; a<ln; a= a + increase) {
        printf("Loop %d\n", counter, ": ");
        counter = counter + 1;
    }

    return 0;
}
