import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(N):
    answer = []
    for K in range(2,10):
        digit_num = digit(N,K)
        res = digit_mul(digit_num)
        answer.append([K, res])

    answer.sort(key=lambda x : (-x[1], -x[0]))
    return answer[0]


def digit(N, K):
    '''진법으로 변환'''
    num = ""
    while N >= 1:
        num = str(N % K) + num
        N = N // K
    return num

def digit_mul(digit_n):
    '''자릿수 곱하기'''
    res = 1
    for n in digit_n:
        n = int(n)
        res = res * n if n !=0 else res

    return res

if __name__ == "__main__":
    N = int(input())
    print(solution(N))
