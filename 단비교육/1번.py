import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

def solution(numbers):
    numbers_counter = collections.Counter(numbers)
    numbers_cnt = len(numbers)

    for key, value in numbers_counter.items():
        if value > numbers_cnt // 2:
            return key

    return -1

if __name__=="__main__":
    numbers = [6,1,6,6,7,6,6,7]
    print(solution(numbers))