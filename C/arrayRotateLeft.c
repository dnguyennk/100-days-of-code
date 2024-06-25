/* Write a program that should rotate left a given array by 1 position
    Ex: 
    Before: [5,4,7,3]   ->     Affer: [4,7,3,5]
*/
#include <stdio.h>
#define SIZE 4
int main(){
    int temp;
    int arr[SIZE] = {5, 4, 7, 3};
    temp = arr[0];
    for (int i = 1; i < SIZE; i++){
        arr[i-1] = arr[i];
    }
    arr[SIZE - 1] = temp;
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}