import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def calc(humans):
    # 사람들의 키 계산
    res = 0
    for index in range(len(humans) - 1):
        res += abs(humans[index] - humans[index + 1])
    return res

def solution(v):
    # 사람들이 줄을 설 수 있는 모든 경우
    nPr = list(itertools.permutations(v))
    answer = 0

    # 각각의 경우
    for humans in nPr:
        answer = max(answer, calc(humans))
    return answer

if __name__ == "__main__":
    v = [20, 8, 10, 1, 4, 15]
    print(solution(v))
