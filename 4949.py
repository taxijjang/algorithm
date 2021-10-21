# problem
# https://www.acmicpc.net/problem/4949
# solve
# https://www.acmicpc.net/source/34633189
import sys
import re
from collections import deque


def input():
    return sys.stdin.readline().rstrip()


def check_bracket(brackets):
    stack_bracket = []
    while brackets:
        now_bracket = brackets.popleft()
        if not stack_bracket and (now_bracket == ']' or now_bracket == ')'):
            return 'no'
        if (now_bracket == ']' and stack_bracket[-1] == '[') or (now_bracket == ')' and stack_bracket[-1] == '('):
            stack_bracket.pop()
        else:
            stack_bracket.append(now_bracket)
    if stack_bracket:
        return 'no'
    return 'yes'


def main():
    results = []

    rex = re.compile(r'[()\[\]]')

    while True:
        str = input()
        if str == '.':
            break
        brackets = deque(re.findall(rex, str))
        results.append(check_bracket(brackets))

    print(*results, sep='\n')


if __name__ == "__main__":
    main()
