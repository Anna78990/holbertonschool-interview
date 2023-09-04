#!/usr/bin/python3
"""
Solve the question of README.md
Continue pasting the existing string and copy it again when n is
divisible by the existing number of characters.
"""


def minOperations(n):
    if not n or not isinstance(n, int) or n <= 1:
        return 0
    paste, ctr = 1, 0
    while paste != n:
        if (n % paste) == 0:
            cp = paste
            ctr += 1
        paste += cp
        ctr += 1
    return ctr
