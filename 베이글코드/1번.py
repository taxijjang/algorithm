import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(n, ladder):
    for i in range(len(ladder)):
        ladder[i].append(0)
        print(ladder)

    answer = []

    for y in range(n):
        x = len(ladder) -1
        while x >= 0:
            if y + 1 < n and ladder[x][y] == 1:
                x, y = x - 1, y + 1
            elif y - 1 >= 0 and ladder[x][y - 1] == 1:
                x, y = x - 1, y - 1
            elif ladder[x][y] == 0:
                x, y = x - 1, y
        answer.append(y + 1)
    return answer


if __name__ == "__main__":
    n = 4

    ladder = [[1, 0, 1], [0, 1, 0], [0, 0, 1], [0, 0, 0], [1, 0, 0]]
    # ladder = [[1,0,0], [0,1,0], [0,0,1]]
    # ladder = [[0, 0], [0, 0]]
    ladder = [[0,0,0], [0,0,0],[0,0,0]]
    #ladder = [[0,1,0],[1,0,1],[0,1,0]]
    print(solution(n, ladder))
