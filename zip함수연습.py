import itertools

a = [['a' ,'b'], ['c' , 'd'], ['e','f']]
b = [1, 2, 3, 4]


c = list(zip(a,b))
#print(c)

d = list(itertools.product(*a))
#print(d)


a = 'abc'
b = 'xyz'

c = list((zip(a,b)))

print("".join(*c))