import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(orders, course):
    menu_combi_dict = collections.defaultdict(set)

    ### 각 주문에 대해서 2가지 이상의 모든 조합을 구합니다.
    for person, menus in enumerate(orders):
        sort_menus = sorted(menus)
        for cnt in range(2, len(sort_menus) + 1):
            menu_combis = list(itertools.combinations(sort_menus, cnt))
            for menu_combi in menu_combis:
                course_cook = ''.join(menu_combi)
                menu_combi_dict[course_cook].add(person)

    ### 조합으로 만들어진 코스 메뉴가 2번이상 주문이 되었는지 확인 합니다.
    course_cook_dict = collections.defaultdict(int)
    for key, value in menu_combi_dict.items():
        if len(value) >= 2:
            course_cook_dict[len(key)] = len(value) if course_cook_dict[len(key)] < len(value) else course_cook_dict[
                len(key)]

    result = list()

    ### 조합으로 만들어진 코스 메뉴가 입력으로 받은 코스 요리의 조건에 맞는지 확인합니다.
    for menu_cnt, person_cnt in course_cook_dict.items():
        if menu_cnt in course:
            for key, value in menu_combi_dict.items():
                if menu_cnt == len(key) and person_cnt == len(value):
                    result.append(key)

    result.sort(key=lambda x: (x))
    return result


if __name__ == "__main__":
    orders = list(map(str, sys.stdin.readline().rstrip().split()))
    print(orders)
    course = list(map(int, sys.stdin.readline().split()))
    print(course)

    print(solution(orders, course))
