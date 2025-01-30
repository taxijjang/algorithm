import sys

def main():
    input = sys.stdin.readline

    n = int(input())

    meetings = []
    for _ in range(n):
        start, end = map(int, input().split())
        meetings.append((start, end))

    meetings.sort(key=lambda x: (x[1], x[0]))

    result = 0
    current_end_time = 0

    for start, end in meetings:
        if start >= current_end_time:
            result += 1
            current_end_time = end

    print(result)

if __name__ == "__main__":
    main()