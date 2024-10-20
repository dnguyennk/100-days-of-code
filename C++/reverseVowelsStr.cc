/* 2 pointers: 1L 1R => find vowel both side the swap, stop when overlap
- Range of L pointer : [0, overlap point]
- Range of R pointer : [overlap point, end of string]
*/
class Solution {
public:
    //helper function
    bool isVowel(char c){
            return c == 'a' || c == 'i' || c == 'e' || c == 'u' || c == 'o' 
            || c == 'A' || c == 'I' || c == 'E' || c == 'U' || c == 'O';
    }
    
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        //While still have chars to traverse
        while (l < r){
            //Find the leftmost vowel
            while (l < s.size() && !isVowel(s[l])){ //prevent lptr out of range
                l++;
            }
            //Find the rightmost vowel
            while (r >= 0 && !isVowel(s[r])){ //prevent rptr out of range
                r--;
            }
            //Found 2 vowels both side => Swap char at l and r, then increment lptr, decrement rptr
            if (l < r){
                swap (s[l++], s[r--]); 
            }
        }
        return s;
    }    
};
