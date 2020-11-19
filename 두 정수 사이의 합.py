import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

def solution(a, b):
    # answer = 0
    # min_num = min(a,b)
    # max_num = max(a,b)
    # for num in range(min_num, max_num + 1):
    #     answer += num
    # return answer

    return sum(range(min(a,b), max(a,b)+1))


if __name__=="__main__":
    a, b = map(int,sys.stdin.readline().rstrip().split())
    print(solution(a,b))