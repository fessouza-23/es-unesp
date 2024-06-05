#include <stdio.h>

int main() {
    int myArray[5]; // Declaring an array of integers
    int size = sizeof(myArray) / sizeof(myArray[0]);
    printf("Size of the array: %d\n", size);
    return 0;
}