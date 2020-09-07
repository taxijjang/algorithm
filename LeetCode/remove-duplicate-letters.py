from collections import *
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

s = input()

alpa_dict = defaultdict()

counter , seen, stack = Counter(s), set(), list()

for char in s:
    counter[char] -= 1
    print(char)

    if char in seen:
        continue

    while stack and char < stack[-1] and counter[stack[-1]] > 0:
        seen.remove(stack.pop())
        print(seen)

    stack.append(char)
    seen.add(char)

print(seen)
print(stack)
