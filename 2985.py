import sys
from collections import deque
from itertools import permutations,combinations,product
sys.setrecursionlimit(10000)

def calc(num):
    x,y,z = num
    if x+y ==z:
        print("{0}+{1}={2}".format(x,y,z))
    elif x-y==z: 
        print("{0}-{1}={2}".format(x,y,z))
    elif x*y==z:
        print("{0}*{1}={2}".format(x,y,z))
    elif x==y*z:
        print("{0}/{1}={2}".format(x,y,z))
    elif x ==y +z:
        print("{0}={1}+{2}".format(x,y,z))
    elif x == y-z: 
        print("{0}={1}-{2}".format(x,y,z))
    elif x==y*z:
        print("{0}={1}*{2}".format(x,y,z))
    elif x*z ==y:
        print("{0}={1}/{2}".format(x,y,z))

num = list(map(int,sys.stdin.readline().split()))
calc(num)