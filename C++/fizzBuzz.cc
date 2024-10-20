#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;         //init Vector of string type
                                    // = dynamic arrays and allow to add and remove anytime
        for (int i = 1; i <= n; i++){
            if (i % 3 == 0 && i % 5 == 0){
                ans.push_back("FizzBuzz");      //string can add at anytime using push_back
            } else if (i % 3 == 0){
                ans.push_back("Fizz");
            } else if (i % 5 == 0){
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};