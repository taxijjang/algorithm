import sys

n = int(sys.stdin.readline())

res = 0
for i in range(n):
    word = sys.stdin.readline().rstrip('\n')

    if len(word)%2 == 1:
        continue

    while True:
        check = False
        if 'AA' in word:
            word =word.replace('AA','')
            check = True
        
        if 'BB' in word:
            word = word.replace('BB','')
            check =True

        if check == False:
            break

        if word == '':
            res+=1
            break

print(res)