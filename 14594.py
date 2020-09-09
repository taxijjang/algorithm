import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

N = int(input())
M = int(input())

break_room = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(M)]
break_room.append([1,1])
break_room.append([N,N])
break_room.sort(key=lambda x: (x[0], x[1]))

print(break_room)
if M == 0:
    print(N)

else:
    res = list()




