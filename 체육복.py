import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(n, lost, reserve):
    dress = [1] * (n + 2)

    for man in lost:
        dress[man] -= 1

    for man in reserve:
        dress[man] += 1

    for index, cnt in enumerate(dress):
        if dress[index] > 1 and dress[index - 1] == 0:
            dress[index] -= 1
            dress[index - 1] += 1

        if dress[index] > 1 and dress[index + 1] == 0:
            dress[index] -= 1
            dress[index + 1] += 1

    answer = collections.Counter(dress[1:-1])

    return n - answer[0]


if __name__ == "__main__":
    n = int(input())
    lost = list(map(int, sys.stdin.readline().rstrip().split()))
    reserve = list(map(int, sys.stdin.readline().rstrip().split()))

    print(solution(n, lost, reserve))
