#!/usr/bin/python3
"""rain module"""


def rain(walls):
    """
    calculate how much water can be trapped
    Args:
        walls: list of height values
    Returns:
        amount of water able to be trapped
    """
    if len(walls) < 3:
        return 0

    total_water = 0
    left = 0
    right = len(walls) - 1
    left_max = right_max = 0

    while left < right:
        if walls[left] <= walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                total_water += left_max - walls[left]
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                total_water += right_max - walls[right]
            right -= 1

    return total_water
