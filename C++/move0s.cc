class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[p1++] = nums[i]; //Write and increase p1
            }
        }
        //After writing all non-zero value, write the rest 0 into array
        for (int i = p1; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};