# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
from itertools import permutations

def solution(A,B,C,D):
    time = set(list(permutations([A,B,C,D],4)))
    
    result = 0
    for a,b,c,d in time:
        if a<=2 and b <=3 and c <=5:
            result+=1
        
        elif a<2 and c <6:
            result+=1
        
    return result