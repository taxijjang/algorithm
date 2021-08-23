import sys

from collections import defaultdict

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    result = list()

    for i in range(n):
        count, name = sys.stdin.readline().split()
        result.append([int(count), name, i])

    result.sort(key=lambda x: (x[0], x[2]))
    for data in result:
        print(data[0], data[1])