import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *
import time


# def solution(n, quests):
#     init_state = ['0'] * (n + 1)
#     solve_quests = ['0'] * (n + 1)
#     check_solve_quest = set()
#     quest_states = dict()
#
#     for index in range(n):
#         quest_states[index + 1] = ['0'] * (n + 1)
#         check_solve_quest.add(index + 1)
#
#     for first_quest, second_quest in quests:
#         quest_states[second_quest][first_quest] = 1
#
#     answer = []
#     while (len(check_solve_quest) > 0):
#         for quest in check_solve_quest:
#             if quest_states[quest] == solve_quests or \
#                     quest_states[quest] == init_state:
#                 solve_quests[quest] = '1'
#                 check_solve_quest.remove(quest)
#
#                 print(solve_quests)
#                 print(check_solve_quest)
#                 time.sleep(1)
#                 break
#             else:
#                 print(solve_quests)
#                 print(check_solve_quest)
#     return answer

def solution(n, quests):
    check_solve_quest = collections.defaultdict(bool)
    quest_states = collections.defaultdict(list)
    quest_set = set()

    for index in range(n):
        quest_set.add(index+1)
    for first_quest,second_quest in quests:
        quest_states[second_quest].append(first_quest)

    print(quest_set, quest_states)
    return None

if __name__ == "__main__":
    n = 5
    quests = [[1, 3], [1, 4], [3, 5], [5, 4]]
    print(solution(n, quests))
