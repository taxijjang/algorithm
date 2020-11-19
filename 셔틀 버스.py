import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

<<<<<<< HEAD

def solution(n, t, m, timetable):
    start_time = [9, 0]
    end_time = [23, 59]

    print(n, t, m)
    print(timetable)
    timetable = [list(map(int, time.split(':'))) for time in timetable]
    timetable.sort(key=lambda x: (x[0], x[1]))
    timetable = collections.deque(timetable)

    print(timetable)

    for _ in range(n):
        for crew in timetable:
            HH,MM = crew

        pass

    return 0




if __name__ == "__main__":
    n, t, m = list(map(int, sys.stdin.readline().rstrip().split()))
    timetable = list(map(str, sys.stdin.readline().rstrip().split()))
    print(solution(n, t, m, timetable))
=======
def solution(n,t,m,timetable):
    answer = 0

    return answer

if __name__=="__main__":
    n,t, m = 1, 1, 5
    timetable = ["08:00", "08:01", "08:02", "08:03"]
    print(solution(n,t,m,timetable))
>>>>>>> 3e67a4349801910099547952016d80fdf1770dce
