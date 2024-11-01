class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        //Trim space left and right (if any)
        while (left <= right && s[left] == ' ') ++left;
        while (left<= right && s[right] == ' ') --right;

        //a deque to add words without unwanted space
        /* A deque: similar as vector but more efficient front back, not guaranteed to store all elements in contiguous storage */
        deque<string> d; //add word in reverve order
        string word;

        while (left <= right){
            if (s[left] == ' ' && !word.empty()){   //1 word done
                d.push_front(word);
                word.clear();
            } else if (s[left] != ' '){     //still reading a character
                word += s[left];      
            }
            ++left; //dont forget increase pointer
        }
        d.push_front(word); //add the last word to deque

        string ans = "";
        while (!d.empty()){
            ans += d.front();    //pick 1st word => tranfer to ans
            d.pop_front();          // remove it from deque
            if (!d.empty()){
                ans += " ";     // still having a word => dont forget add space
            }
        }
        return ans;

        
    }
};