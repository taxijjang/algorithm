import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

SIZE = 1010
check = [0] * SIZE
goods = list()
arr = [[]] * SIZE

def solution(n, delivery):
    for d in delivery:
        if d[2] == 1:
            goods.append(d[0])
            goods.append(d[1])
            check[d[0]], check[d[1]] = 2, 2

        else:
            arr[d[0]].append(d[1])
            arr[d[1]].append(d[0])

    for good in goods:
        for next_good in arr[good]:
            if check[next_good] != 1:
                check[next_good] = 1
    answer = ''

    for i in range(1,n+1):
        if check[i] == 0:
            answer = answer + '?'
        elif check[i] == 1:
            answer = answer + 'x'
        elif check[i] == 2:
            answer = answer + 'o'

    return answer


if __name__ == "__main__":
    n = 6
    delivery = [[1, 3, 1], [3, 5, 0], [5, 4, 0], [2, 5, 0]]
    print(solution(n, delivery))
