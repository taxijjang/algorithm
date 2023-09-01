def f1(values):
    return sum(x ** 2 for x in values if x % 2 == 0)


def f2(values):
    return sum(x * 2 for i, x in enumerate(values) if i % 2 == 0)


def f3(values):
    return sum(x * x if x % 2 == 0 else 0 for x in values)


def f4(values):
    return sum(x * 2 for x in values[::2])


def f5(values):
    return sum(x ** 2 if x % 2 == 0 else 0 for x in values)


if __name__ == "__main__":
    print(f1(range(1, 6)))
    print(f2(range(1, 6)))
    print(f3(range(1, 6)))
    print(f4(range(1, 6)))
    print(f5(range(1, 6)))