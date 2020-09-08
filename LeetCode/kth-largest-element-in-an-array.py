import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

nums = list(map(int, sys.stdin.readline().split()))
kk = int(sys.stdin.readline())

nums_dict = collections.Counter(nums)

heap = []

# for k, v in nums_dict.items():
#     heapq.heappush(heap, (-k, v))
#
# for _ in range(len(heap)):
#     num = heapq.heappop(heap)
#     print(num[0],num[1])
#     if kk - num[1] > 0:
#         kk =  kk - num[1]
#     else:
#         print(-num[0])
#         break

print(nums)
heapq.heapify(nums)
print(nums)

heapq.heapify()
heapq.heappush()
heapq.heappop()
heapq.heappushpop()
heapq.heapreplace()
heapq.merge()
heapq.nlargest()
heapq.nsmallest()
