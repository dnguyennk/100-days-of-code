#include <stdio.h>
#include <string.h>
/* Benefit: Do not need to make multple functions to swap */
void genericSwap(void *a, void*b, int size){  //size >0
    //Size - the number of bytes
    void *temp = malloc(size);
    /* Memory copy function
        void *memcpy(void *dest, const void*src, size_t num) */
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}
int main(){
    int num1 = 5;
    int num2= 7;
    double avg1= 90.5, avg2 = 89.7;
    genericSwap(&avg1, &avg2, sizeof(double));
    genericSwap(&num1, &num2, sizeof(int));

    

}