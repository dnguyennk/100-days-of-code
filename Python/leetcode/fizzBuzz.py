#elegant way: String concatenation
# allow to solve extended porblem
# ie FizzBuzzJazz

from typing import List


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        #return list
        ans = []

        for num in range (1, n+1):
            div_by_3 = (num % 3 == 0)
            div_by_5 = (num % 5 == 0)

            curr = ""

            if div_by_3:
                # Divides by 3
                curr += "Fizz"
            if div_by_5:
                # Divides by 5
                curr += "Buzz"
            if not curr: 
                #if current string empty (ie not divides by any of above)
                curr = str(num)
            # appent the current string to the answer list
            ans.append(curr)
        
        return ans

