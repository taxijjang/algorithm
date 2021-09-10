import sys


def input():
    return sys.stdin.readline().rstrip()


def solution(N):
    if N % 2 == 0:
        return "CY"
    return "SK"


if __name__ == "__main__":
    print(solution(int(input())))
