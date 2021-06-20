import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


def solution(S, C):
    user_list = (S + '; ').split('; ')[:-1]
    print(user_list)
    email_last = '@' + C.lower() + '.com>'
    email_count_dict, email_dict = collections.defaultdict(int), collections.defaultdict(str)
    for user in user_list:
        name_list = user.split(' ')
        first_name, last_name = name_list[0], name_list.pop()
        first_convert_name, last_convert_name = first_name.lower(), last_name.lower().replace('-', '_')
        print(first_convert_name, last_convert_name)
        email_first = first_name + ' ' + last_name
        email_count[email_first] += 1
        email_dict[email_first] += first_convert_name

    print(email_dict)
    # return user_list, email_last


if __name__ == "__main__":
    S = "John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter Brain Parker"
    C = "Example"
    print(solution(S, C))
