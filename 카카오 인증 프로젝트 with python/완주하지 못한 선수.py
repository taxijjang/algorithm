import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(participant, completion):
    # part_count = dict(collections.Counter(participant))
    #
    # for com in completion:
    #     if part_count[com] -1 == 0:
    #         part_count.pop(com)
    #     else:
    #         part_count[com] -= 1
    #
    # answer = list(part_count.keys())
    # return answer[0]

    answer = collections.Counter(participant)-collections.Counter(completion)
    return list(answer.keys())[0]

participant=["leo", "kiki", "eden"]

completion=["eden", "kiki"]

print(solution(participant,completion))

