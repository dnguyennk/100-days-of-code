/* Write a program that performs some calculations on complex numbers
1. Create a double complex number that perform Euler's formula 
2. Create a double complex number with the imaginary number squared using
multiplication operator
3. Create a double complex number with the imaginary number squared using
math library
4. Create a double complex number that performs a conjugate
Note: Use the complex.h header file and the creal() and cimag() functions
*/

#include <stdio.h>
#include <math.h>
#include <complex.h>
int main(){
    double complex z1 = I * I;      //imaginary unit squared
    printf("I * I = %.1f% + .1fi\n", creal(z1), cimag(z1));

    double complex z2 = cpow(I, 2);  //imaginary unit squared
    printf("pow(I, 2) =  %.1f% + .1fi\n", creal(z2), cimag(z2));

    double PI = acos(-1);
    double complex z3 = cexp(I * PI);   // Euler's formula
    printf("exp(I*PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));

    double complex z4 = 1+2*I, z5 = 1 - 2*I;    //conjugates
    printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4*z5), cimag(z4*z5));
    
    return 0;
}