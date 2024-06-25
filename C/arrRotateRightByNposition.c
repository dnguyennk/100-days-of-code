/* Write a program that should rotate right a given array by n position
    Ex: 
    Before: [5,4,7,3]   ->     Affer: [3,5,4,7]
*/
#include <stdio.h>
#define SIZE 4
#define N 2
int main(){
    int temp;
    int arr[SIZE] = {5, 4, 7, 3};
    
    for (int k = 0; k < N; k++){
        temp = arr[SIZE - 1];
        for (int i = SIZE -1; i >0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
    }
    
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}