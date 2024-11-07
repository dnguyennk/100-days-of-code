class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //Find the greatest number of candies
        int maxCandies = 0;
        for (int candy: candies){
            maxCandies = max(maxCandies, candy);
        }
        // For each kid, check if they have the max candies
        vector<bool> result;
        for (int candy: candies){
            result.push_back(candy+ extraCandies >= maxCandies);
        }
        return result;

    }
};