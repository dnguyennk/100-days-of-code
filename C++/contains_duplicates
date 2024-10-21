#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { //ref to a vector aaray of ints
        unordered_set<int> s; //store #s O(1)

        for (int i = 0; i < nums.size; i++){
            if (s.find(nums[i]) != s.end()){ //if nums[i] is in the set s, if not found => return iteratot points to s.end() (past the last elt of set)
                return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};