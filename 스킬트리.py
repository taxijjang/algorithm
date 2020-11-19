import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(skill, skill_trees):
    skill_dict = {key: value for value, key in enumerate(skill)}

    answer = 0
    for skill_tree in skill_trees:
        priority = 0
        flag = True
        for skill_tree_element in skill_tree:
            if skill_tree_element in skill_dict.keys():
                if skill_dict[skill_tree_element] == priority:
                    priority += 1
                else:
                    flag = False
        if flag:
            answer += 1

    return answer


if __name__ == "__main__":
    skill = "CBD"
    skill_trees = "BACDE", "CBADF", "AECB", "BDA"
    print(solution(skill, skill_trees))
