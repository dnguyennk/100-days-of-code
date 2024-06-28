#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int* realloc(int* oldArr, int oldSize, int newSize){
        int *newArr;
        //Allocate new memory
        newArr; = (int*)malloc(newSize*sizeof(int));
        //Copy old array values to the new array 
        for (int i = 0; i < oldSize;i++){
            newArr[i] = oldArr[i];
        }
        //Free the old array memory
        free(oldArr);
        //Return the address of new array
        return newArr;
    }
}