import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def check(user_id: str, banned_id: str) -> bool:
    if len(user_id) != len(banned_id):
        return False

    else:
        for i in range(len(user_id)):
            if banned_id[i] == '*' or user_id[i] == banned_id[i]:
                continue
            else:
                return False

        return True


def solution(user_id, banned_id):
    answer = set()
    result = [[] for _ in range(len(banned_id))]

    for i in range(len(banned_id)):
        for u in user_id:
            if check(u, banned_id[i]):
                result[i].append(u)

    result = list(itertools.product(*result))

    for r in result:
        if len(set(r)) == len(banned_id):
            answer.add("".join(sorted(set(r))))

    return len(answer)


if __name__ == "__main__":
    user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
    banned_id = ["fr*d*", "abc1**"]

    # user_id =["frodo", "fradi", "crodo", "abc123", "frodoc"]
    # banned_id = ["*rodo", "*rodo", "******"]
    #
    # user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
    # banned_id = ["fr*d*", "*rodo", "******", "******"]
    print(solution(user_id, banned_id))
