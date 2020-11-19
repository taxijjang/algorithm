A = [ 1,2,3,4]
B = [1,2,3,4]

for index, a, b in zip(range(len(A)),A,B):
    print(index, a, b)