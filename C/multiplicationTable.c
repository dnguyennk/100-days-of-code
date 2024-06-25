#include <stdio.h>
#include <stdlib.h>
/*  Write a program that receives an integer and prints its multiplication table
    Example: Multiplication table of 3
    1. 3 * 1 = 3
    2. 3 * 2 = 6
    ....
    10. 3 * 10 = 30
 */

int main(){
    int num, multiplicator;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the multiplicator: ");
    scanf("%d", &multiplicator);


    for (int i = 0; i < multiplicator + 1; i++){
        printf("%d * %d = %d\n", num, i, num*i);
    }
    return 0;
}