/* Print Date in Hexadecimal - Question

Write a program that should receive from the user 3 values: Year, Month, Date
Print the date in Hexadecimal Format
Ex:                                 Output
Day 20, Month = 8, Year = 2012       Day = 0x14, Month = 0x8, Year = 0x7DC
*/
# include <stdio.h>

int main(){
    int day, month, year;
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    printf("Day: 0x%X\n", day);
    printf("Day: 0x%X\n", month);
    printf("Day: 0x%X\n", year);
    
    return 0;

}