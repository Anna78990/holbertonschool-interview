#!/usr/bin/python3


def makeChange(coins, amount):
    """
    determine the fewest number of coins needed
    to meet a given amount total
    """
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0

    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], 1 + dp[i - coin])

    if dp[amount] == float('inf'):
        return -1
    else:
        return dp[amount]
