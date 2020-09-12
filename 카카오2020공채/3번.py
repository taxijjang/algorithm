import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

info_dict = dict(
    java=dict(
        backend=dict(
            junior=dict(
                pizza=list(),
                chicken=list(),
            ),
            senior=dict(
                pizza=list(),
                chicken=list(),
            ),
        ),
        frontend=dict(
            junior=dict(
                pizza=list(),
                chicken=list(),
            ),
            senior=dict(
                pizza=list(),
                chicken=list(),
            ),
        ),
    ),
    cpp=dict(
        backend=dict(
            junior=dict(
                pizza=list(),
                chicken=list(),
            ),
            senior=dict(
                pizza=list(),
                chicken=list(),
            ),
        ),
        frontend=dict(
            junior=dict(
                pizza=list(),
                chicken=list(),
            ),
            senior=dict(
                pizza=list(),
                chicken=list(),
            ),
        ),
    ),
    python=dict(
        backend=dict(
            junior=dict(
                pizza=list(),
                chicken=list(),
            ),
            senior=dict(
                pizza=list(),
                chicken=list(),
            ),
        ),
        frontend=dict(
            junior=dict(
                pizza=list(),
                chicken=list(),
            ),
            senior=dict(
                pizza=list(),
                chicken=list(),
            ),
        ),
    ),
)


def solution(info, query):
    for info_data in info:
        language, dev, career, food, score = info_data.split()
        heapq.heappush(info_dict[language][dev][career][food], -(int(score)))

    result = list()
    for query_data in query:
        language, _, dev, _, career, _, food, score = query_data.split()
        # print(language, dev, career, food, score)
        result.append(check_language(language, dev, career, food, int(score)))

    # print(info_dict)

    return result


def check_language(language, dev, career, food, score):
    cnt = 0
    if language != "-":
        cnt = check_dev(language, dev, career, food, score)

    elif language == '-':
        cnt += check_dev('python', dev, career, food, score)
        cnt += check_dev('cpp', dev, career, food, score)
        cnt += check_dev('java', dev, career, food, score)

    return cnt


def check_dev(language, dev, career, food, score):
    cnt = 0
    if dev != '-':
        cnt = check_career(language, dev, career, food, score)

    elif dev == '-':
        cnt += check_career(language, 'backend', career, food, score)
        cnt += check_career(language, 'frontend', career, food, score)

    return cnt


def check_career(language, dev, career, food, score):
    cnt = 0
    if career != '-':
        cnt = check_food(language, dev, career, food, score)

    elif career == '-':
        cnt += check_food(language, dev, 'junior', food, score)
        cnt += check_food(language, dev, 'senior', food, score)

    return cnt


def check_food(language, dev, career, food, score):
    cnt = 0
    if food != '-':
        tmp = info_dict[language][dev][career][food].copy()

        while (len(info_dict[language][dev][career][food]) > 0 and -heapq.heappop(info_dict[language][dev][career][food]) >= score):
            cnt += 1

        info_dict[language][dev][career][food] = tmp
    elif food == '-':
        pizza_tmp = info_dict[language][dev][career]['pizza'].copy()
        while (len(info_dict[language][dev][career]['pizza']) >0 and -heapq.heappop(info_dict[language][dev][career]['pizza']) >= score):
            cnt += 1
        info_dict[language][dev][career]['pizza'] = pizza_tmp

        chicken_tmp = info_dict[language][dev][career]['chicken'].copy()
        while (len(info_dict[language][dev][career]['chicken']) >0 and -heapq.heappop(info_dict[language][dev][career]["chicken"]) >= score):
            cnt += 1

        info_dict[language][dev][career]['chicken'] = chicken_tmp

    return cnt


if __name__ == "__main__":
    info = [sys.stdin.readline().rstrip() for _ in range(6)]
    query = [sys.stdin.readline().rstrip() for _ in range(6)]

    print(solution(info, query))
