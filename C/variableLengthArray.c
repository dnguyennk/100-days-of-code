/* Write a program  to read elements in an array and find the sum of array elements*/
#include <stdio.h>
int main(){
    int sum = 0, size = 0;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    int arr[size];

    printf("Enter %d elements in the array: ", size);

    for (int i = 0; i < size; i++){
        sum += i;
    }
    printf("\nSum of all elements of array = %d", sum);
    return 0;
}