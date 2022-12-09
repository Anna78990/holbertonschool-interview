#!/usr/bin/python3

list = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
t = tuple(list)
tup = ()


def func(*args):
    print(args[0][0])
    print(args[1])
    print(len(args))

func([[1, 2], 2], [3, 1])

