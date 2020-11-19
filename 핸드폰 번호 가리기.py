import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(phone_number: str) -> str:
    return '*' * len(phone_number[:-4]) + phone_number[-4:]


if __name__ == "__main__":
    phone_number = sys.stdin.readline().rstrip()
    print(solution(phone_number))
