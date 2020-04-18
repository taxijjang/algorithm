p = input()
s = input()

def solution(p,s):
    size = len(p)
    answer = 0
    for index in range(0,size):
        pp = (int)(p[index])
        ss = (int)(s[index])

        gap = abs(pp - ss)
        if gap <=5 :    
            answer +=gap
        else:
            answer = answer + (10 - gap)

        print(pp, ss)
  
    return answer

print(solution(p,s))