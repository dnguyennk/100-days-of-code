/* Reset all the elements of an array to 0 */
#include <stdio.h>
void printArr(int *ptr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", ptr[i]);
    }
}
void resetElement(int *ptr, int size){
    for (int i = 0; i < size; i++){
        ptr[i] = 0;
    }
}
int main(){
    int arr[3] = {1, 3, 10};
    printf("Before reset: \n");
    printArr(arr, 3);
    resetElement(arr, 3);
    printf("After Reset: \n");
    printArr(arr, 3);
}