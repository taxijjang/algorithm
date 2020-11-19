import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(s):
    res = 0
    sentences = list(re.split('[.?!]', s))
    for sentence in sentences:
        words = sentence.split()
        if res < len(words):
            res = len(words)

    return res
if __name__=="__main__":
    #s = "We test coders. Give us a tyr?"
    s = "Forget   CVs..Save time . x x"
    print(solution(s))