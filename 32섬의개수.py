import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

d = [[-1, 0], [0, 1], [1, 0], [0, -1]]


def soultion(map):
    def dfs(i, j):
        if i < 0 or i >= len(map) or j < 0 or j >= len(map) or map[i][j] != 1:
            return
        for dx, dy in d:
            dfs(i+dx, j+dy)

    cnt = 0
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j] == 1:
                dfs(i,j)
                cnt += 1

    return cnt


if __name__ == "__main__":
    map = [
        [1, 1, 1, 1, 0],
        [1, 1, 0, 1, 0],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]

    print(soultion(map))
