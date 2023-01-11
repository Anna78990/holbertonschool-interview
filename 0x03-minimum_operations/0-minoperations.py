#!/usr/bin/python3
""" to solve the question of README.md """


def minOperations(n):
    ctr = 0
    divide = n - 1
    divided = n

    if n <= 1:
        return 0
    if divide == 1:
        return 2

    while divide > 1:
        while divided % divide != 0:
            divide -= 1
        if divide == 1 and ctr == 0:
            return n
        else:
            ctr += (divided / divide)
            divided = divide
            divide -= 1
    if divided == 2:
        ctr += 2

    return int(ctr)
