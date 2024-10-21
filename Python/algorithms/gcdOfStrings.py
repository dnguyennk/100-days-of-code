from math import gcd


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # Check if there is any non-0 gcd string
        if str1 + str2 != str2 + str1: 
            return ""
        
        # Get the GCD of the 2 lengths
        max_length = gcd(len(str1), len(str2))
        return str1[:max_length]
        