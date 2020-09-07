logs = ['dig1 8 1 5 1',  'dig2 3 6', 'let1 own kit dig', 'let1 art zero','let1 art can',]

letters, digits = [],[]
for log in logs:
    print(log)
    if log.split()[1].isdigit():
        print(f"digits : {log}")
        digits.append(log)
    else:
        print(f"letters : {log}")
        letters.append(log)

letters.sort(key=lambda x : (x.split()[1:], x.split()[0]))
print(letters)




s = ['5 a', '4 b', '3 c', '2 d']

s.sort()

s.sort(key=lambda x : x.split()[1])

print(s)


