import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


T = list(enumerate(list(map(int,sys.stdin.readline().split()))))

print(T)

stack = list()
day_dict = collections.defaultdict(int)
for temp in T:
    print(temp)

    if len(stack) == 0:
        stack.append(temp)
        continue


    while stack and stack[-1][1] < temp[1]:
        day_dict[stack[-1][0]] = temp[0] - stack[-1][0]
        stack.pop()

    stack.append(temp)

result = list()
for i in range(len(T)):
    result.append(day_dict[i])

print(result)


