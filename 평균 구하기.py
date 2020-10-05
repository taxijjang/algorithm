import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

def solution(arr):
    return sum(arr)/ len(arr)

if __name__=="__main__":
    arr = [1,2,3,4]
    print(solution(arr))