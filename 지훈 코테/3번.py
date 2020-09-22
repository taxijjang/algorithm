import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(ranks):
    ranks_cnt = collections.Counter(ranks)

    res = 0
    for key, value in ranks_cnt.items():
        if ranks_cnt[key+1] != 0:
            res += value
    return res
if __name__=="__main__":
    ranks = [3,4,3,0,2,2,3,0,0]
    print(solution(ranks))