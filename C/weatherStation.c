#include <stdio.h>
# include <stdlib.h>

/* Write a program that reads:
1.  "Temperature" from the user for 7 days
2.  Calcuculates and print:
    - Average temperature
    - Hottest day of the week
    - Coldest day of the week
    */
#define SIZE 7    //days
int main(){
    float temperature[SIZE];    
    float sum = 0.0;
    float avg_temp;
    int hottest_day = 0;
    int coldest_day = 0;

    for (int i = 0; i < SIZE; i++){
        printf("Enter the temperature at day %d: ", i + 1);
        scanf("%f", & temperature[i]);
    }
    for (int i = 0; i < SIZE; i++){
        sum = sum + temperature[i];
        if (temperature[hottest_day] < temperature[i]){
            hottest_day = i;
            continue;   // no need to check coldest
        }
        if (temperature[coldest_day] > temperature[i]){
            coldest_day = i;
        }
    }
    avg_temp = sum /SIZE;
    printf("The average temperature = %f \n", avg_temp);
    printf("The hottest day of the week was at day %d \n", hottest_day + 1);
    printf("The coldest day of the week was at day %d \n", coldest_day + 1);
    return 0;
}