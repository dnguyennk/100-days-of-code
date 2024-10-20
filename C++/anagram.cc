class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int count[26] = {0};

        //Count freq of chars in s
        for (char c: s){
            count[c-'a']++;
        }
        //Decrement freq of chars in t
        for (char c: t){
            count[c-'a']--;
        }
        //if any chars has non-zero frequency => not anagram
        for (int v: count){
            if (v != 0) return false;
        }
        return true;
    }
};