import sys

def GCD(a , b):
    if b > a:
        temp = a
        a = b
        b = temp
    while(b > 0):
        temp = b
        b = a%b
        a = temp
    
    return a

n = int(sys.stdin.readline())

garosu = [int(sys.stdin.readline()) for _ in range(n)]

garosu.sort()

garosu_gap=[]
for i in range(1,n):
    garosu_gap.append(garosu[i] - garosu[i-1])

garosu_gap.sort()

common_gcd = garosu_gap[0]

for g in garosu_gap:
    common_gcd = GCD(common_gcd,g)

res = 0

for g in garosu_gap:
    if g == common_gcd:
        continue
    else:
        res += g//common_gcd - 1

print(res)

