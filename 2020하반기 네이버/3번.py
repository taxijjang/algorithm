import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

fire_wood = dict()
fire_wood[2] = 1  # 1
fire_wood[3] = 1  # 7
fire_wood[4] = 1  # 4
fire_wood[5] = 3  # 2, 3, 5,
fire_wood[6] = 3  # 0, 6, 9
fire_wood[7] = 1  # 8

res = 0


def dfs(k: int, sum: int) -> int:
    if k < 2:
        if k == 0:
            global res
            res += sum
        return 0

    for fire_wood_cnt in range(2, 7):
        if fire_wood_cnt > k:
            break

        else:
            dfs(k - fire_wood_cnt, sum * fire_wood[fire_wood_cnt])


def solution(k: int) -> int:
    if k < 2:
        return 0

    dfs(k, 1)

    global res
    return res


if __name__ == "__main__":
    num = int(input())
    print(solution(k=num))
