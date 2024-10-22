from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p1 = 0

        for i in range(len(nums)):
            if (nums[i] != 0):
                nums[p1], nums[i] = nums[i], nums[p1] #swap in python
                p1 += 1

        return nums