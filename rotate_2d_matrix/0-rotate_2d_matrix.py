#!/usr/bin/python3
"""
rotate given an n x n 2D matrix 90 degrees clockwise.
"""


def rotate_2d_matrix(matrix):
    n = len(matrix)
    list_matrix = []

    for i in range(0, len(matrix)):
        list_matrix.append([])
        for j in range(0, len(matrix[i])):
            list_matrix[i].append(matrix[i][j])

    for m in range(n, 0, -1):
        rtt_idx = n - m
        for p in range(0, n):
            s = m - 1
            matrix[p][s] = list_matrix[rtt_idx][p]
