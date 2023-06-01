import sys
""" Solve n's queen problem"""


def is_safe(board, row, col):
    """Check if it is safe to place a queen at board[row][col]"""
    for c in range(col):
        if board[row][c] == 1:
            return False

    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while i < N and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1

    return True


def solve_nqueens(board, col):
    """ solve n's queen """
    if col == N:
        print_solution(board)
        return True

    for row in range(N):
        if is_safe(board, row, col):
            board[row][col] = 1

            solve_nqueens(board, col + 1)

            board[row][col] = 0


def print_solution(board):
    """ print solution """
    solution = []
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                solution.append([i, j])
    print(solution)


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

if N < 4:
    print("N must be at least 4")
    sys.exit(1)

board = [[0] * N for _ in range(N)]

solve_nqueens(board, 0)
