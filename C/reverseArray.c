/*  Write a function that receives an array of characters (recursively) */
#include <stdio.h>
#include <string.h>
#define SIZE 4  
void swap(char* ptr1, char* ptr2){
    char temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
void printArray(char* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%c ", arr[i]);
    }
}
void reverseArrIterative(char* arr, int size){
    for (int i = 0; i < size/2; i++){   //don't forget /2
        swap(&arr[i], &arr[size-1-i]);
    }
}
void reverseArrRecursive(char* arr, int size){
    if (size >1){
        swap(&arr[0], &arr[size -1]);   // can be: swap(arr, arr+size-1)
        reverseArrRecursive(arr+1, size-2);
    }
}
int main(){
    char arr[SIZE] = {'a', 'f', 'k', 'd'};
    printArray(arr, SIZE);
    printf("\n");
    reverseArrRecursive(arr, SIZE);
    printArray(arr, SIZE);
    
    return 0;
}