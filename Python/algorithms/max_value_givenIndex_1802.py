# Max nums[index] & ensure sum array does not exceed maxSum
# Greedy + Binary Search
# Step 1: set a value for nums[index]
# Step 2: Calculate sum of array (4 cases (2L 2R), try to rmb how?) 

#Calcualate the min sum of array
def getSum(index: int, value: int, n: int) -> int:
    count = 0
    
    #On index's left: 
    #1.1 if value > index, there are index + 1 nums in the arith seq [value - index, ..., value]
    #1.2 there are [1, 2, 3..., value] + a seq length (index - value + 1) of 1s
    if value > index: 
        count += (value + value - index)* (index+1)//2
    else: 
        count += (value+1)*value//2 +index - value + 1
    
    #On index's right:
    #2.1 if value >= n - index, there are n-index nums in arith sequence [value, ....value - n + 1 + index]
    #2.2 there are [value, value -1, ..., 1] + a seq length (n - index -value) of 1s
    if value >= n - index:
        count += (value + value - n + 1 + index)*(n-index) //2
    else:
        count += (value + 1) * value //2 + n - index - value
    
    return count - value

def maxValue(n: int, index: int, maxSum: int) -> int:
    left, right = 1, maxSum
    while left < right:
        mid = (left + right + 1) // 2
        if getsum(index, mid, n) <= maxSum:
            left = mid
        else:
            right = mid - 1
    return left
    
    