class Solution:
    def climbStairs(self, n: int) -> int:
        #Fibonanci
        if n == 1:
            return 1
        f1 = 1
        f2 = 2
        for i in range(3, n+1):
            f3 = f1 + f2
            f1 = f2
            f2 = f3
        return f2
        