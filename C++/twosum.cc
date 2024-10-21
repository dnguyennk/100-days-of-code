class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap; // value -> index

        for (int i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            if (hashmap.find(difference) != hashmap.end()){
                return {hashmap[difference], i};
            }
            hashmap.insert({nums[i], i});
        }
        return {};
    }
};