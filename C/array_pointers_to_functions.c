#include <stdio.h>
#include <stdlib.h>

/* Array of Pointers to Functions */
void addition(int a, int b){
    printf("%d + %d = %d\n", a, b, a+b);
}
void subtraction(int a, int b){
    printf("%d - %d = %d\n", a, b, a-b);
}
void multiplication(int a, int b){
    printf("%d * %d = %d\n", a, b, a*b);
}
void division(int a, int b){
    if (b!=0)
        printf("%d / %d = %d\n", a, b, a/b);
    else {
        printf("Cannot divide by 0!");
    }
}
/* Note that add more function, function pointer still works fine*/
void remainder(int a, int b){
        if (b!=0)
        printf("%d %% %d = %d\n", a, b, a%b);
    else {
        printf("Cannot divide by 0!");
    }
}
int main(){
    /*Array of 4, points to each function*/
    void (*functionPtrArray[]) (int, int) ={addition, subtraction, multiplication, division, remainder};
    int num1, num2;
    int choice;
    printf("Choose: \n0 - addition\n1 - subtraction\n2 - multiplication\n3 - division\n4 - remainder");
    scanf("%d", &choice);
    printf("Enter number 1: "); 
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);

    /* Call the appropriate function - do not forget to specify the index of function we want to call*/
    (*functionPtrArray[choice]) (num1, num2);


    /* Traditional approach
    char opperation;
    printf("Enter the operation that you want to perform (+ - * /): ");
    scanf("%c", & opperation);
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);

    
    switch (opperation){
        case '+':
            addition(num1, num2);
            break;
        case '-':
            subtraction(num1, num2);
            break;
        case '*':
            multiplication(num1, num2);
            break;
        case '/':
            division(num1, num2);
            break;
        default:
            printf("Please try again!");

    }
    */

    return 0;
}