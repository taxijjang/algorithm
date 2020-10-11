import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(votes, k):
    if len(votes) == 1:
        return votes.pop()
    votes_count = collections.Counter(votes)
    revers_votes_count = collections.defaultdict(list)

    for key, value in votes_count.items():
        revers_votes_count[value].append(key)

    revers_votes_count = list(sorted(revers_votes_count.items(), key=lambda x: x[0], reverse=True))
    car_cnt, vote_sum = 0, 0

    for vote, car_list in revers_votes_count:
        if car_cnt + len(car_list) < k:
            car_cnt = len(car_list)
            vote_sum += vote * len(car_list)

        elif car_cnt + len(car_list) >= k:
            vote_sum += (k - car_cnt) * vote
            car_cnt = k

    for i in range(len(revers_votes_count)):
        revers_votes_count[i] = list(revers_votes_count[i])
        revers_votes_count[i][1] = sorted(revers_votes_count[i][1])

    ban_sum = 0
    answer = ''

    for vote, car_list in sorted(revers_votes_count, key=lambda x: x[0]):
        if vote * len(car_list) + ban_sum < vote_sum:
            ban_sum += vote * len(car_list)
            continue

        else:
            while car_list:
                if ban_sum + vote < vote_sum:
                    ban_sum += vote
                    car = car_list.pop()

                else:
                    return car

    return answer


if __name__ == "__main__":
    # votes = ["AVANT", "PRIDO", "SONATE", "RAIN", "MONSTER", "GRAND", "SONATE", "AVANT", "SONATE", "RAIN", "MONSTER",
    #"GRAND", "SONATE", "SOULFUL", "AVANT", "SANTA"]

    # k = 2
    # votes = ["AAD", "AAA", "AAC", "AAB"]
    # k = 4
    votes = ['aaa','abc','acdf','qwer']
    k = 1
    print(solution(votes, k))
