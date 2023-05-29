#!/usr/bin/python3
"""
Test 0x16 - Rotate 2D Matrix
"""

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    list_matrix = []
    for n in range(0, 3):
        print(matrix[0][n])

    print("----")
    for n in range(2, -1, -1):
        print(matrix[0][n])

    print(matrix)

    for i in range(0, len(matrix)):
        list_matrix.append([])
        for j in range(0, len(matrix[i])):
            list_matrix[i].append(matrix[i][j])

    list_matrix[0][0] = 10
    print("-list_matrix-")
    print(list_matrix)
    print("-matrix-")
    print(matrix)
