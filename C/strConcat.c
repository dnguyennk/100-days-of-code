#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Write a function that receive a string and return a concatenated
string (an address) 
Example: Hello
Return: HelloHello_ */

char *strConcat(char * orginalStr){
    char *newStr;
    int len_orginalStr = strlen(orginalStr);
    /* Dynamic allocation - array of characters, same double size of the original + 1*/
    newStr =  (*char)malloc(len_orginalStr*sizeof(char) +1);
    /* Copy elements */
    int i;
    for (i = 0; i < len_orginalStr; i++){
        newStr[i] = orginalStr[i];
        newStr[i + len_orginalStr] = orginalStr[i];
    }
    newStr[i + len_orginalStr] = '\0';
    return newStr;
}
int main(){

    return 0;
}
