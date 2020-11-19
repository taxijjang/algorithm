import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(k, score):
    answer = len(score)
    visited = [False for _ in range(len(score))]
    modify_score_cnt = collections.defaultdict(list)


    for rank in range(len(score) - 1):
        score_gap = score[rank] - score[rank + 1]
        modify_score_cnt[score_gap].append([rank, rank + 1])

    for gap, ranks in modify_score_cnt.items():
        if len(ranks) >= k:
            for left,right in ranks:
                visited[left] = True
                visited[right] = True

    print(modify_score_cnt)
    for i in range(len(visited)):
        if visited[i] == True:
            answer -= 1

    answer = 0 if answer == len(score) else answer
    return answer


if __name__ == "__main__":
    #k = 3
    #score = [24, 22, 20, 10, 5, 3, 2, 1]
    k = 2
    #score = [1300000000,700000000,668239490,618239490,568239490,568239486,518239486,157658638,157658634,100000000,100]
    #score = [100,98,95,5,4,3,2,1]
    score = [1]
    print(solution(k, score))
