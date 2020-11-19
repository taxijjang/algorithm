import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(gems):
    left: int = 0

    gems_cnt = len(set(gems))

    deque = collections.deque()

    answer = list()
    is_collect = collections.defaultdict(int)
    for right, gem in enumerate(gems):
        deque.append(gem)
        is_collect[gem] += 1

        while (len(is_collect) == gems_cnt):
            answer.append([left + 1, right + 1])

            if is_collect[gems[left]] - 1 <= 0:
                break

            is_collect[gems[left]] -= 1

            if is_collect[gems[left]] == 0:
                is_collect.pop(gems[left])

            left += 1
            deque.popleft()

    answer.sort(key=lambda x: (x[1] - x[0], x[0]))
    return answer[0]

if __name__ == "__main__":
    gems = sys.stdin.readline().rstrip().split()
    print(solution(gems))
