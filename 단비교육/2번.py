import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

def solution(n):
    while (len(str(n)) > 1):
        n = sum(int(each_n) for each_n in str(n))

    return n

if __name__=="__main__":
    n = 10
    print(solution(n))