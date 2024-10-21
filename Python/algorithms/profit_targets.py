#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'stockPairs' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY stocksProfit
#  2. LONG_INTEGER target
#

def stockPairs(stocksProfit, target):
    # Write your code here
    n = len(stocksProfit)
    stocksProfit = sorted(stocksProfit)
    low = 0
    high = n - 1
    pairs = 0
    while (low < high):
        if (stocksProfit[low] + stocksProfit[high] < target):
            low+=1
        elif (stocksProfit[low] + stocksProfit[high] > target):
            high-=1
        else: 
            while (low < high and stocksProfit[low] == stocksProfit[low+1]):
                low += 1
            while (low < high and stocksProfit[high] == stocksProfit[high-1]):
                high -=1
            pairs +=1
            low+=1
            high-=1
        
    return pairs
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    stocksProfit_count = int(input().strip())

    stocksProfit = []

    for _ in range(stocksProfit_count):
        stocksProfit_item = int(input().strip())
        stocksProfit.append(stocksProfit_item)

    target = int(input().strip())

    result = stockPairs(stocksProfit, target)

    fptr.write(str(result) + '\n')

    fptr.close()
