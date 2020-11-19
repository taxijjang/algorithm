import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

visited_dfs = collections.defaultdict(bool)
visited_bfs = collections.defaultdict(bool)
tree_node_cnt = collections.defaultdict(int)
tree_node_height = collections.defaultdict(list)

tree_sort = list()


def dfs(node, tree, height):
    visited_dfs[node] = True
    tree_node_cnt[node] = 1

    if len(tree[node]) == 0:
        tree_node_cnt[node] = 1
        tree_sort.append([height, -tree_node_cnt[node], node])
        return tree_node_cnt[node]

    for son in tree[node]:
        if visited_dfs[son] == True:
            continue

        else:
            tree_node_cnt[node] += dfs(son, tree, height + 1)

    tree_sort.append([height, -tree_node_cnt[node], node])
    return tree_node_cnt[node]


def bfs(root, tree):
    queue = collections.deque([root])
    res = 0
    while queue:
        here = queue.popleft()

        for next in tree[queue]:
            # tree_node_bfs_num[]
            pass

    return None


def solution(n, edges):
    tree = collections.defaultdict(list)

    for mom, son in edges:
        tree[mom].append(son)

    dfs(0, tree, 0)
    # print(tree_node_cnt)
    global tree_sort
    tree_sort = sorted(tree_sort, key=lambda x: (x[0], -x[1], x[2]))
    print(tree_sort)
    # print(bfs(0, tree))


if __name__ == "__main__":
    n = 19
    edges = [[0, 1], [0, 2], [0, 3], [1, 4], [1, 5], [2, 6], [3, 7], [3, 8], [3, 9], [4, 10], [4, 11], [5, 12], [5, 13],
             [6, 14], [6, 15], [6, 16], [8, 17], [8, 18]]
    print(solution(n, edges))
