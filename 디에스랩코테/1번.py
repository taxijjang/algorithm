import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def check_outside(old_loc, new_loc , office_size):
    if new_loc < 0 or new_loc >= office_size:
        return old_loc
    else:
        return new_loc


def check_direction(now_direction, r, c, d, office_size):
    if d == 'left':
        now_direction = 3 if now_direction == 0 else now_direction - 1
    elif d == 'right':
        now_direction = 0 if now_direction == 3 else now_direction + 1
    else:
        if now_direction == 0:
            r = check_outside(r, r - 1, office_size)
        elif now_direction == 1:
            c = check_outside(c, c + 1, office_size)
        elif now_direction == 2:
            r = check_outside(r, r + 1, office_size)
        else:
            c = check_outside(c, c - 1, office_size)
    return now_direction, r, c


def solution(office, r, c, move):
    direction = 0  # 0 > 북, 1 > 동 , 2 > 남 , 3 > 서
    answer = office[r][c]
    office[r][c] = 0
    for where in move:
        direction, tmp_r, tmp_c = check_direction(direction, r, c, where, len(office))
        if where == 'go' and office[tmp_r][tmp_c] >= 0:
            answer += office[tmp_r][tmp_c]
            office[tmp_r][tmp_c] = 0
            r, c = tmp_r, tmp_c
    return answer


if __name__ == "__main__":
    # office = [[5, -1, 4], [6, 3, 1], [2, -1, 1]]
    # r, c = 1, 0
    # move = ["go", "go", "right", "go", "right", "go", "left", "go"]
    office = [[5,-1],[-1,-1]]
    r,c = 0 ,0
    move = ['go','right','go','right']
    print(solution(office, r, c, move))
