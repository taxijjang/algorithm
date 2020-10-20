import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

def solution(orders):
    name_menus = collections.defaultdict(set)
    for order in orders:
        query = order.split(' ')
        name, menus = query[0], query[1:]

        for menu in menus:
            name_menus[name].add(menu)

    name_menucnt = collections.defaultdict(int)
    for key, value in name_menus.items():
        name_menucnt[key]= len(name_menus[key])

    name_menucnt = sorted(name_menucnt.items(), key=lambda x: x[1], reverse=True)

    answer = []

    order_cnt = name_menucnt[0][1]

    for name, cnt in name_menucnt:
        if cnt == order_cnt:
            answer.append(name)


    return sorted(answer)
if __name__=="__main__":
    orders = ["alex pizza pasta", "alex pizza pizza", "alex noodle", "bob pasta", "bob noodle sandwich pasta", "bob steak noodle"]
    print(solution(orders))