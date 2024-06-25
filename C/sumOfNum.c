/*  Write a progtam that receives a "num" from user.
    The program should print the SUM of all integers from 1 up to num. 
    i.e. 3 -> 1 + 2 + 3 = 6
*/
# include <stdio.h>

int main(){
    int num;
    int sum = 0;
    printf("Enter num: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++){
        sum += i;
    }
    printf("The sum of all numbers from 1 up to %d is: %d \n", num, sum);
    return 0;
}
