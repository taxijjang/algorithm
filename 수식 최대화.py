import sys
import re
from itertools import product
from itertools import permutations
from itertools import combinations

def solution(expression):
    answer = 0
    kihos = [
        ('*', '-', '+'),
        ('*', '+', '-'),
        ('+', '*', '-'),
        ('+', '-', '*'),
        ('-', '*', '+'),
        ('-', '+', '*'),
    ]

    for kiho in kihos:
        res = int(calc(kiho,0,expression))
        answer = max(answer, abs(res))
    return answer


def calc(p, n, expression):
    if n == 2:
        return str(eval(expression))
    if p[n] == '*':
        res = eval('*'.join([calc(p, n+1, e) for e in expression.split('*')]))
    if p[n] == '-':
        res = eval('-'.join([calc(p, n + 1, e) for e in expression.split('-')]))
    if p[n] == '+':
        res = eval('+'.join([calc(p, n + 1, e) for e in expression.split('+')]))
    return str(res)

if __name__ == "__main__":
    expression = sys.stdin.readline()
    print(solution(expression=expression))