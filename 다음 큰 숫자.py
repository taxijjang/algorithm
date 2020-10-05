import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(n):
    max_num = 1000000
    one_cnt = bin(n).count('1')

    for num in range(n + 1, max_num + 1):
        one_tmp_cnt = bin(num).count('1')
        if one_cnt == one_tmp_cnt:
            return (num)


if __name__ == "__main__":
    n = int(input())
    print(solution(n))
