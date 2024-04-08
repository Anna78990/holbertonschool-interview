#!/usr/bin/python3
"""
make pascal triangle of a given number
"""


def pascal_triangle(n):
    """
    make pascal triangle of a given number
    """
    list_c = []
    for column in range(0, n):
        if (column == 0):
            list_c.append([1])
        else:
            list_c.append([])
            for row in range(0, column + 1):
                if row == 0 or row == (column):
                    list_c[column].append(1)
                else:
                    n = list_c[column - 1][row - 1] + list_c[column - 1][row]
                    list_c[column].append(n)
    return (list_c)
