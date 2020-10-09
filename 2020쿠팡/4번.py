import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

dp = collections.defaultdict(lambda: collections.defaultdict(lambda: collections.defaultdict(int)))
graph = collections.defaultdict(list)


def dfs(starting, start, end, destination):
    if end == destination:
        dp[starting][start][end] = 1
        return dp[starting][start][end]

    if dp[starting][start][end] != -1:
        return dp[starting][start][end]

    dp[starting][start][end] = 0

    for next_end in graph[end]:
        dp[starting][start][end] += dfs(starting, end, next_end, destination)

    return dp[starting][start][end]

def solution(depar, hub, dest, roads):
    for start, end in roads:
        dp[depar][start][end] = -1
        dp[hub][start][end] = -1
        graph[start].append(end)

    '''hub -> dest'''
    for end in graph[hub]:
        dfs(hub, hub, end, dest)

    #print(hub, dp[hub][hub])
    '''depar -> hub'''
    for  end in graph[depar]:
        dfs(depar, depar, end, hub)

    #print(depar, dp[depar][depar])

    hub_dest, depar_hub = 0, 0

    for _, hub_cnt in dp[hub][hub].items():
        hub_dest += hub_cnt

    for _, depar_cnt in dp[depar][depar].items():
        depar_hub += depar_cnt

    answer = hub_dest * depar_hub
    return answer


if __name__ == "__main__":
    depar = 'SEOUL'
    hub = 'DAEGU'
    dest = 'YEOSU'
    roads = [["ULSAN", "BUSAN"], ["DAEJEON", "ULSAN"], ["DAEJEON", "GWANGJU"], ["SEOUL", "DAEJEON"], ["SEOUL", "ULSAN"],
             ["DAEJEON", "DAEGU"], ["GWANGJU", "BUSAN"], ["DAEGU", "GWANGJU"], ["DAEGU", "BUSAN"], ["ULSAN", "DAEGU"],
             ["GWANGJU", "YEOSU"], ["BUSAN", "YEOSU"]]

    # depar = 'ULSAN'
    # hub = 'SEOUL'
    # dest = 'BUSAN'
    # roads = [["SEOUL","DAEJEON"],["ULSAN","BUSAN"],["DAEJEON","ULSAN"],["DAEJEON","GWANGJU"],["SEOUL","ULSAN"],["DAEJEON","BUSAN"],["GWANGJU","BUSAN"]]
    print(solution(depar, hub, dest, roads))
