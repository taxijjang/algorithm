import sys
from collections import Counter


def input():
    return sys.stdin.readline().rstrip()


def main():
    total = 1
    for _ in range(3):
        total *= int(input())
    counter_num = Counter(str(total))
    for i in range(0, 10):
        if counter_num.get(str(i)):
            print(counter_num.get(str(i)))
        else:
            print(0)


if __name__ == '__main__':
    main()
