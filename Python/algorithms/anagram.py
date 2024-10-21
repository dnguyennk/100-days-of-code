class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count = [0] * 26

        # count freq of chars in s to count array
        for c in s:
            count[ord(c) - ord('a')] +=1
        #decrement freq of chars in t to count array
        for c in t:
            count[ord(c) - ord('a')] -=1
        #check if any chars in count array has non-0 freq => yes = not anagram
        for v in count:
            if v != 0:
                return False

        return True