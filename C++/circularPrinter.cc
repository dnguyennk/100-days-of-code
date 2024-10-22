#include <iostream>

int getTime(string s){
    int result = 0
    //count from the 1st character (i.e A)
    int count_time = abs(s[0] - 65); //Ascii A = 65
    if (count_time > 13) result+= (26 % count_time); //the other way round
    else result+= count_time;

    //cont count other char
    for (int i = 0; i < s.size(); i++){
        count_time = abs(s[i] - s[i-1]);
        if (count_time > 13) result += (26% count_time);
        else result += count_time;
    }
    return result;

}
int main(){

}