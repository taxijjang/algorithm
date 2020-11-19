import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

INF = 2222222222
d = [(-1, 0), (0, 1), (1, 0), (0, -1)]

dp_size = 30
dp = [[INF] * dp_size for _ in range(25)]
visited = [[False] * dp_size for _ in range(25)]

# 0 위로 직진, 1 오른쪽으로 직진, 2 아래로 직진, 3 왼쪽으로 직진
direct = [0, 1, 2, 3]


def solution(board) -> int:
    dp[0][0] = 0
    for dir, dd in enumerate(d):
        print(dir, dd[0], dd[1])
    dfs(0, 0, 1, board)
    dfs(0, 0, 2, board)

    return dp[len(board) - 1][len(board) - 1]


def dfs(h_x, h_y, h_dir, board) -> None:
    for dir, dd in enumerate(d):
        n_x, n_y = h_x + dd[0], h_y + dd[1]
        n_dir = direct[dir]
        n_cost = cost_calc(h_dir, n_dir)
        if n_x < 0 or n_x >= len(board) or n_y < 0 or n_y >= len(board) or board[n_x][n_y] == 1:
            continue

        if dp[n_x][n_y] < dp[h_x][h_y] + n_cost:
            continue

        dp[n_x][n_y] = dp[h_x][h_y] + n_cost
        dfs(n_x, n_y, n_dir, board)


def cost_calc(h_dir, n_dir) -> int:
    # 직선일때 cost
    if h_dir == n_dir:
        return 100

    # 코너를 돌때 cost
    else:
        return 600


if __name__ == "__main__":
    n = int(input())
    board = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(n)]

    solution(board=board)
    print(dp[len(board) - 1][len(board) - 1])
