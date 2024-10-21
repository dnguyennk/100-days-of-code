from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {} #(Map) value: index
        for i in range(len(nums)):
            difference = target - nums[i]
            if difference in hashmap:
                return [hashmap[difference], i] # the pair of indices
            #update hashmap if not found any
            hashmap[nums[i]] = i
        return [] #return empty list if no sol found  


        