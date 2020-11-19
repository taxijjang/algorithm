import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(s: str) -> int:
    answer = len(s)
    for size in range(1, len(s) // 2 + 1):
        word, cnt = "", 1
        left, right = 0, size
        c_left, c_right = size, 2 * size

        while c_right <= len(s):
            if s[left: right] == s[c_left: c_right]:
                cnt, left, right = cnt + 1, left + size, right + size
                c_left, c_right = c_left + size, c_right + size

            else:
                if cnt == 1:
                    word = word + s[left: right]
                elif cnt > 1:
                    word = word + str(cnt) + s[left:right]

                cnt = 1
                left, right = c_left, c_right
                c_left, c_right = c_left + size, c_right + size

        if cnt != 1:
            word = word + str(cnt) + s[left: right]
            left = right

        word = word + s[left:]
        answer = len(word) if answer > len(word) else answer
    return answer


if __name__ == "__main__":
    while True:
        s = sys.stdin.readline().rstrip()
        print(solution(s))
