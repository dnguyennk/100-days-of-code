/* Delete from an array. Result should be in new array, new sequence, new elements */
#include <stdio.h>
#include <stdlib.h>
/* Pointer to void (pointer to array, total amount of bytes, 
the inital bytes we want to remove, # of bytes of single element we will skip)*/
void *remove(void *arr, unsigned size, unsigned index, unsigned sourceSize){
    void *newArr = malloc(size - sourceSize);
    if (!newArr) return NULL;
    memcpy(newArr, arr, index); //1st part copy to newArr
    //2nd part copy to newArr, after skipping number of bytes
    memcpy((char*)newArr+index, (char*)arr+index+sourceSize, size -index-sourceSize);
    return newArr;
}
void printArr(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}

int main(){
    
    int* grades = (int*)malloc(3 * sizeof(int));
	int grade;
	int* updatedArr = NULL;
	if (!grades) return NULL;
	grades[0] = 90;
	grades[1] = 80;
	grades[2] = 100;
	printArr(grades, 3);
	// deleting the third element... at index [1]
	updatedArr = (int*)remove(grades, 3 * sizeof(int), 1 * sizeof(int), sizeof(int));
	if (!updatedArr) return NULL;
	printArr(updatedArr, 2);

    return 0;
}