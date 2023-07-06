#!/usr/bin/python3
"""
determine the fewest number of coins needed
to meet a given total total
"""


def makeChange(coins, total):
    """ determine the fewest number of coins """
    if total <= 0:
        return 0
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for i in range(0, total + 1):
        for coin in coins:
            if coin > i:
                break
            if dp[i - coin] != -1:
                dp[i] = min(dp[i], 1 + dp[i - coin])

    if dp[total] == float('inf'):
        return -1
    else:
        return dp[total]
