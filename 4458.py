import sys
n = int(sys.stdin.readline())

for i in range(n):
    s = sys.stdin.readline()
    s = s[0].upper() + s[1:-1]
    print(s)
