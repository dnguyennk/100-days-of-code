#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/*Return address of the 1st element*/
int *createArray();

void printArray( int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int *arr;
    arr = createArray();
    printArray(arr, SIZE);
}

int *createArray(){
    //int myArr[SIZE] //static
    int *myArr; //pointer
    myArr = (int*)malloc(SIZE*sizeof(int));   //dynamically allocate memoy on Heap
    printf("Enter %d elements to your array.\n", SIZE);
    if (!myArr){
        printf("Error, memory allocation failed.\n");

    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i);
        scanf("%d", &myArr[i]);
    }
    return myArr;
    
}
