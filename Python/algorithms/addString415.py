class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        result = []
        carry = 0
        #pointers
        p1 = len(num1) - 1
        p2 = len(num2) - 1
        while p1>=0 or p2>=0:
            if p1>=0:
                x1 = ord(num1[p1]) - ord('0') #convert to #
            else: 
                x1 = 0 #if negative
            if p2>=0:
                x2 = ord(num2[p2]) - ord('0') #convert to #
            else:
                x2 = 0 #if negative
            value = (x1 + x2 + carry) % 10
            carry = (x1 + x2 + carry) //10
            result.append(value)
            p1-=1
            p2-=1
        if carry:
            result.append(carry)
        return ''.join(str(x) for x in result[::-1])
        