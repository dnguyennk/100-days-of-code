class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # create hashset
        hashset = set()

        for n in nums:
            #if there is duplicate
            if n in hashset:
                return True
            hashset.add(n) #if not any dup
        return False

        