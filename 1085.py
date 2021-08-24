import sys

if __name__ == "__main__":
    x, y, w, h = map(int, sys.stdin.readline().split())
    print(min(abs(x-w), abs(x-0), abs(y-h), abs(y-0)))