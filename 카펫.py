import sys


def solution(brown, yellow):
    for y in range(1, yellow + 1):
        namugi = int(yellow % y)
        x = int(yellow / y)

        if namugi == 0:
            tmp = (2 + x) * 2 + (2 + y) * 2 - 4
            if tmp == brown:
                return [x + 2,y + 2]


if __name__ == "__main__":
    brown, yellow = map(int, sys.stdin.readline().split())
    print(solution(brown=brown, yellow=yellow))
