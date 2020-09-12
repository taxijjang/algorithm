import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(new_id):
    first_new_id = first(new_id)
    #print(f"first_new_id -> {first_new_id}")

    second_new_id = second(first_new_id)
    #print(f"second_new_id -> {second_new_id}")

    third_new_id = third(second_new_id)
    #print(f"third_new_id -> {third_new_id}")

    fourth_new_id = fourth(third_new_id)
    #print(f"fourth_new_id -> {fourth_new_id}")

    fifth_new_id = fifth(fourth_new_id)
    fifth_new_id = fourth(fifth_new_id)
    #print(f"fifth_new_id -> {fifth_new_id}")

    sixth_new_id = sixth(fifth_new_id)
    sixth_new_id = fourth(sixth_new_id)
    #print(f"sixth_new_id -> {sixth_new_id}")

    seventh_new_id = seventh(sixth_new_id)
    #print(f"seventh_new_id -> {seventh_new_id}")

    return seventh_new_id


def seventh(sixth_new_id: str) -> str:
    seventh_new_id = sixth_new_id

    while (len(seventh_new_id) < 3):
        seventh_new_id += seventh_new_id[-1]

    return seventh_new_id


def first(new_id: str) -> str:
    first_new_id = new_id.lower()
    return first_new_id


def second(first_new_id: str) -> str:
    second_new_id = re.sub(r'[^0-9a-z-_.]', '', first_new_id)
    return second_new_id


def third(second_new_id: str) -> str:
    third_new_id = re.sub(r'[.]+', '.', second_new_id)
    return third_new_id


def fourth(third_new_id: str) -> str:
    fourth_new_id = third_new_id
    flag = True
    while (flag):
        flag = False
        if fourth_new_id != '' and fourth_new_id[0] == '.':
            fourth_new_id = fourth_new_id[1:]
            flag = True

        if fourth_new_id != '' and fourth_new_id[-1] == '.':
            fourth_new_id = fourth_new_id[:-1]
            flag = True

    return fourth_new_id


def fifth(fourth_new_id: str) -> str:
    fifth_new_id = fourth_new_id
    if fifth_new_id == '':
        fifth_new_id = 'a'
    return fifth_new_id


def sixth(fourth_new_id: str) -> str:
    sixth_new_id = fourth_new_id[:15]
    return sixth_new_id


if __name__ == "__main__":
    new_id = str(sys.stdin.readline())
    print(solution(new_id))
