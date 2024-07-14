#include <stdio.h>
#include <stdlib.h>

void ageFunc(int age){
    printf("Your age is %d\n", age);
}
int main(){
    int age;
    //Declare function pointer
    void (*ptrFuction) (int);
    scanf("%d", &age);
    
    
    ptrFuction = &ageFunc;
    printf("The address of the function &ageFunc is: %p\n", ptrFuction);    
    ptrFuction = ageFunc;
    printf("The address of the function ageFunc is: %p\n", ptrFuction); //Same address as &ageFunc

    (ptrFuction) (age); //call the function that the function pointer points to, with the value "age" as an argument


    return 0;
}
/* Common mistake with function pointer
    1. Inappropriate declaration of a Pointer to a Function
        int *ptrFunct() != int (*ptrFunc)();

*/