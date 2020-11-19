import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(phone_number):
    formats = dict(
        r1=re.compile("^010-['0-9']{4}-['0-9']{4}$"),
        r2=re.compile("^010['0-9']{8}$"),
        r3=re.compile("^['+']82-10-['0-9']{4}-['0-9']{4}$")
    )

    for index, key in enumerate(formats.keys()):
        if formats[key].match(phone_number):
            return index+1

    return -1




if __name__ == "__main__":
    phone_number = "01023456789"
    # phone_number = "010-6311-0710"
    # phone_number = "+82-10-1234-5678"
    print(solution(phone_number))
