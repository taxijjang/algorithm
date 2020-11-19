import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *
from datetime import datetime, timedelta

kiosk_cnt = collections.defaultdict(int)
def time_calc(customer:str):
    day, time, spend = customer.split(' ')
    MMM, DDD = str(day).split('/')
    HH, MM, SS = str(time).split(':')

    now_time = datetime(2019, int(MMM), int(DDD), int(HH), int(MM), int(SS))
    next_time = now_time + timedelta(minutes=int(spend))
    #print(now_time, next_time)

    print(str(next_time))


def solution(n, customers):
    pq = []

    for kiosk in range(1, n + 1):
        heapq.heappush(pq, kiosk)

    print(pq)

    kiosk_operator = []
    for customer in customers:
        time_calc(customer)

    a = "10/01 23:20:25"
    b = "10/01 23:20:25"

    if a > b:
        print('a가 b보다 크다')
    elif a == b:
        print("a == b")
    else:
        print('b가 a보다 크다')
    answer = 0
    return answer


if __name__ == "__main__":
    n = 3
    customers = ["10/01 23:20:25 30", "10/01 23:25:50 26", "10/01 23:31:00 05", "10/01 23:33:17 24",
                 "10/01 23:50:25 13", "10/01 23:55:45 20", "10/01 23:59:39 03", "10/02 00:10:00 10"]
    print(solution(n, customers))
#2	["02/28 23:59:00 03","03/01 00:00:00 02", "03/01 00:05:00 01"]	2