def add(x, y):
    return x + y

def outer(x):
    def inner(y):
        return x + y
    return inner



if __name__ == "__main__":
    print(outer(2)(4))
    print(outer(4)(2))