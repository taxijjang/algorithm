s = input().split(":")
e = input().split(":")

st = int(s[0])*3600 + int(s[1])*60 + int(s[2])
et = int(e[0])*3600 + int(e[1])*60 + int(e[2])

if st > et :
    et += 24*60*60

res = et - st
hour = int(res/3600)
res = int(res% 3600)
mint = int(res/60)
res=int(res%60)
sec = res
print('{}:{}:{}'.format(str(hour).zfill(2),str(mint).zfill(2),str(sec).zfill(2)))
