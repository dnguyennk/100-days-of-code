/*  Wrire a programe that initiallizes an array.
    3 elements should represebr a date: 1. day, 2. month, 3. year
    The program shoukd create another arrat and copy data from original array 
*/
#include <stdio.h>
#define SIZE 3

int main(){
    int date[SIZE]  = {1, 2, 2000};
    int date2[SIZE]; //__,__,____
    for (int i = 0; i < SIZE; i++){
        date2[i] = date[i];
    }
    for (int i = 0; i < SIZE; i++){
        printf("original_date[%d] = %d\n", i, date[i]);
        printf("copied_date[%d] = %d\n", i, date2[i]);
    }

    return 0;

}