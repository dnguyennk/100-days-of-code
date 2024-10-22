from typing import List


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        # max would be either nums[0]* nums[1]* nums[len(nums)-1] (2 smallest negative * max of array)
        # or max = the prod of the last 3 largest numbers

        #Find the 2 smallest numbers and 3 largest numbers
        min1 = float("inf")
        min2 = float("inf")
        max1 = float("-inf")
        max2 = float("-inf")
        max3 = float("-inf")
        if len(nums) < 3: return 0
        for i in nums:
            if (i < min1):
                min2 = min1
                min1 = i
            elif (i < min2):
                min2 = i
            if (i > max1):
                max3 = max2
                max2 = max1
                max1=i
            elif (i > max2):
                max3 = max2
                max2 = i
            elif (i > max3):
                max3 = i
        
        return max(min1*min2*max1, max1*max2*max3)
        