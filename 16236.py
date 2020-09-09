import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

dx = [0,1,0,-1]
dy = [-1,0,1,0]

q = collections.deque()

size, eat, time = 0

def solution():
    N = int(input())

    board = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]


    for i in range(N):
        for j in range(N):
            if board[i][j] == 9:
                baby_shark[0], baby_shark[1] = i, j
                board[i][j] = 0
                q.append([i,j])

    print(q.pop())



if __name__ == "__main__":
    solution = solution()