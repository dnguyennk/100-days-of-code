#include <stdio.h>
#include <stdlib.h>

int main(){
    double *bArr;
    int arraySize;
    scanf("%d", &arraySize);
    bArr = (double*)malloc(sizeof(double)*arraySize); //implicit typecast

    /* Make sure the program allocates memory successfully (not return null) */
    if (bArr != NULL) printf("Allocation Succeeded.\n");
    else printf("Allocation failed.\n");
    return 0;
}