class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        //if window > n - m then what happen to the length of needle?
        for (int windowStart = 0; windowStart <= n - m; windowStart++){
            for (int i = 0; i < needle.size(); i++){
                if (needle[i] != haystack[windowStart+i]){
                    break; 
                }
                if (i == m-1){  //Why m-1? try to rmb
                    return windowStart;
                }
            }
        }
        return -1;
    }
};