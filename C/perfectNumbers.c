# include <stdio.h>
/*  Write a function that recieves an integer num. 
    The function should return 1 if "num" is a pefectu number.
    Otherwise, return 0.

    A "perfect number" is a number with a values equals to the sum of all its
    divisors (not including number itself).

    For example:
    6 -> 1, 2, 3 = 6 
    12 -> 1, 2, 3, 4 , 6 = 16 (not perfect num)
    28 -> 1, 2, 4, 7, 14 = 28 (perfect number)
*/


int sum_divisor(int num){
    int sum = 1;
    for(int i = 2; i < num; i++){
        if (num % i == 0){
            sum += i;
        }
    }
    return sum;
}
int isPerfectNum(int num){
    if (num <= 1){
        return 0;
    } 
    if (num == sum_divisor(num)){
        return 1;
    }
    return 0;
}
int main(){
    int num;
    printf("Enter a number: \n");
    scanf("%d", &num);

    if (isPerfectNum(num)){
        printf("%d is a perfect number", num);
    } else{
        printf("%d is not a perfect number", num);
    }
    return 0;
}
