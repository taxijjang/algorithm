import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(A, K):
    A_size = len(A)

    if A[0] != 1:
        return False

    for index in range(1,A_size):
        if A[index] - A[index-1] > 2:
        #print(index)

    return True

if __name__=="__main__":
    A = [1,1,2,3,3]
    K = 3
    print(solution(A,K))