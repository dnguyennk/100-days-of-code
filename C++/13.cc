class Solution {
public:
    static unordered_map<char, int> map;
    int romanToInt(string s) {
        char lastSymbol = s[s.size()-1];
        int lastValue = map[lastSymbol];
        int total= lastValue; //pay attention

        //loop R -> L, 1 at a time, if s[i] < lastValue then - (+ otherwise)
        for(int i = s.size()-2; i >= 0; i--){
            char currentSymbol = s[i];
            int currentValue = map[currentSymbol];
            if (currentValue < lastValue){
                total -= currentValue;
            } else{
                total += currentValue;
            }
            lastValue = currentValue;
        }
        return total;
    }
};
unordered_map<char, int> Solution::map ={{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};