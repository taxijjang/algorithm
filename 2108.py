import math
import sys

from collections import Counter

def cnt(numbers):
    c = Counter(numbers)
    order = c.most_common()
    max_c = int(order[0][1])

    a = []

    i = 0
    for num in order:
        if int(num[1]) == int(max_c):
            a.append(num[0])
            i+=1

    a = sorted(a)
    if i == 1:
        return a[0]
    else:
        return a[1]

n = int(input())

arr = []
for _ in range(n):
    arr.append(int(sys.stdin.readline()))
    
print(round(sum(arr)/n))

a_c = sorted(arr)
print(a_c[int(n/2)])

c= cnt(arr)
print(c)
print(abs(a_c[0] - a_c[n-1]))
