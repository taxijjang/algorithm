def f(x, l=[]):
    for i in range(x):
        l.append(i)
    print(l)

if __name__=="__main__":
    f(2)
    f(3,[1,2,3])
    f(2)