import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


V, E = map(int, input().split())
K = int(input())
INF = 10 * V + 1
distance = [[] for _ in range(V+1)]

for _ in range(E):
    start, end, dist = map(int, sys.stdin.readline().rstrip().split())
    distance[start].append([end,dist])


queue = []
K_distance = [INF for _ in range(V+1)]
K_distance[K] = 0
heapq.heappush(queue, [0, K])

while queue:
    mid = heapq.heappop(queue)
    for end in distance[mid[1]]:
        if K_distance[end[0]] > mid[0] + end[1]:
            K_distance[end[0]] = mid[0] + end[1]
            heapq.heappush(queue, [K_distance[end[0]], end[0]])

for i in range(1, V+1):
    if K_distance[i] == INF:
        print('INF')
    else:
        print(K_distance[i])

