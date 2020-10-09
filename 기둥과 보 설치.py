import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

SIZE = 1002
struct = [[0] * SIZE] * SIZE
queries = list()


def query(x, y, a, b):
    # a -> 0 기둥, 1 보
    # b -> 0 삭제, 1 설치

    if b == 0:  # 삭제
        pass

    elif b == 1:  # 설치
        if a == 0:  # 기둥
            if y == 0 or struct[x][y] != 0:
                struct[x][y] += 1
                struct[x][y+1] +=1
            pass
        elif a == 1:  # 보
            pass


def check():
    pass


def solution(n, build_frame):
    print(struct)

    for x, y, a, b in build_frame:
        pass

    return None


if __name__ == "__main__":
    n = 5
    build_frame = [[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1], [5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1],
                   [3, 2, 1, 1]]

    # n = 5
    # build_frame = [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]
    print(solution(n, build_frame))
