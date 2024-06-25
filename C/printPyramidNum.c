# include <stdio.h>
/* Write a program that receives a "num" from user. Print a pyramid of numbers 
in the increment sequence */

int main(){
    int n;
    int value = 1;
    printf("Enter the number of rows in the pyramid: ");
    scanf("%d", &n);
    int space = n-1;

    for (int i = 1; i < n+1; i++){
        for (int k = space; k > 0; k--){
            printf(" ");
        }
        for (int j = 1; j < i + 1; j++){
            printf("%d ", value);
            value+=1;
        }

        printf("\n");
        space--;
    }
    return 0;
}
