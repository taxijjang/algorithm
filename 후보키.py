import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

key_combinations = list()
candidate_key = list()

def solution(relation):
    row_size = len(relation)
    col_size = len(relation[0])

    for i in range(1, col_size+1):
        key_combinations.extend(set(k)for k in itertools.combinations(list(i for i in range(col_size)),i))

    for key_combination in key_combinations:
        check_cadidate_key = set()

        for x in range(row_size):
            keys = ""
            for y in key_combination:
                keys += relation[x][y]

            check_cadidate_key.add(keys)
        if len(check_cadidate_key) == row_size:

            candidate_key.append(key_combination)

    delete_key = set()

    for c_key in candidate_key:
        for index, cc_key in enumerate(candidate_key):
            if c_key != cc_key and c_key.issubset(cc_key):
                delete_key.add(index)

    return len(candidate_key) - len(delete_key)
if __name__=="__main__":
    relation = [sys.stdin.readline().rstrip().split() for _ in range(5)]
    print(relation)
    print(solution(relation=relation))