import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *
from datetime import datetime, timedelta


def time_calc(p: str, n: int) -> str:
    meridiem, time = p.split(' ')
    HH, MM, SS = str(time).split(':')

    if meridiem == 'PM' and HH != '12':
        HH = str(int(HH) + 12)

    if meridiem == 'AM' and HH == '12':
        HH = '00'

    time1 = datetime(2020, 10, 10, int(HH), int(MM), int(SS))
    time2 = str(time1 + timedelta(seconds=n))

    day, tt = time2.split(' ')

    answer = tt
    return answer


def solution(p, n):
    answer = time_calc(p, n % 86400)
    return answer


if __name__ == "__main__":
    p = "PM 01:00:00"
    n = 10

    # p = "PM 11:59:59"
    # n = 200000
    print(solution(p, n))
