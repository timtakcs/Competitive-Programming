#  File: reward.py

#  Description: The ABC staff decides to find the minimum number of gifts as each customer's reward.
#  Student Name:
#  Student UT EID:
#  Course Name: CS 313E
#  Unique Number:

import sys

max_val = 1000


def getmin(prices, T):
	# Add your code here!
	n = len(prices)
	prices.sort()
	x = int(T * 0.1)
	dp = [999999 for i in range(x + 1)]
	dp[0] = 0

	for i in range(n):
		for j in range(x + 1):
			if j - prices[i] >= 0:
				dp[j] = min(dp[j], dp[j - prices[i]] + 1)
	
	if dp[x] == 999999: 
		return -1
	else:
		return dp[x]

if __name__ == "__main__":

	# Read input list of prices for each gift
	prices_str = sys.stdin.readline().split()
	prices = [ int(x) for x in prices_str ]

	# Read total price that the customer spends
	T = int(sys.stdin.readline())

	print(getmin(prices, T))
