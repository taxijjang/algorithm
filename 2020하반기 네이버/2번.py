import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

def dfs()

def solution(n, edges):
    answer = []

    graph = collections.defaultdict(list)

    for edge in edges:


    combis = list(itertools.combinations(range(1,len(edges)+1), 2))

    for node1, node2 in combis:
        visited = collections.defaultdict(bool)
        visited[node1] = True
        visited[node2] = True


    return answer


if __name__ == "__main__":
    edges = [[0, 2], [2, 1], [2, 4], [3, 5], [5, 4], [5, 7], [7, 8], [6, 8]]
    n = 9

    print(solution(n, edges))
