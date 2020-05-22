import sys
from collections import deque, Counter
from queue import PriorityQueue
from itertools import permutations,combinations,product
sys.setrecursionlimit(10000)

def solution(clothes):
    clothe = {}

    for name,what in clothes:
        if what in clothe.keys():
            clothe[what] += 1
        else:
            clothe[what] = 1

    answer = 1
    for value in clothe.values():
        if len(clothe) == 1:
            return value
        
        else:
            answer *= (value+1)
    return answer - 1

clothes = [["yellow_hat", "headgear"], ["blue_sunglasses", "asdf"], ["green_turban", "headgear"]]

print(solution(clothes))