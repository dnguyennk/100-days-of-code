#include <stdio.h>
#include <stdlib.h>

int main(){
    int* grades = NULL; //make sure not deference inappropriately
    int totalGrades;
    int *temp = NULL;

    printf("Enter total grades: ");
    scanf("%d", &totalGrades);
    //Dynamically memory alocation
    grades = (*int)malloc(totalGrades * sizeof(int));
    if (grades == NULL){
        printf("Allocating failed...\n");
        return 1;   //Exit status
    }
    for (int i = 0; i < totalGradesl; i++){
        printf("Enter grade: ");
        scanf("%d", &grades[i]);
    }
    //need additional slot fors grades => realloc
    totalGrades = totalGrades + 2; //Adjust the size 
    //grades = (int*)realloc(grades, totalGrades*sizeof(int));    //Warning: may lose previous memory
    /*best practice: create a temp pointer*/
    temp =(int*)realloc(grades, totalGrades*sizeof(int));
    if (temp!=NULL){    //Successful allocation
        grades = temp;
    }
    grades[totalGrades - 1] = 100;  //some value for newly allocated memory slot
    grades[totalGrades - 2] = 90;

    /* More example: shrink memory */
    totalGrades = totalGrades - 3;
    temp = (int*)realloc(grades, totalGrades*sizeof(int)); //size 2
    if (temp!=NULL){    //Successful allocation
        grades = temp;
    }
    free(grades); //don't forget this
}