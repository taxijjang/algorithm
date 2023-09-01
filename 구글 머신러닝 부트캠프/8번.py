def fill1(temperatures):
    try:
        total, count = 0, 0
        for t in temperatures:
            if t is not None:
                total += t
                count += 1
        avg = total / count
        for t in temperatures:
            if t is None:
                t = avg
    except Exception:
        print("1Error")


def fill2(temperatures):
    try:
        avg = sum(temperatures) / len(temperatures)
        for i in range(len(temperatures)):
            if temperatures[i] is None:
                temperatures[i] = avg
    except Exception:
        print("2Error")


def fill3(temperatures):
    try:
        good = [t for t in temperatures if t]
        avg = sum(good) / len(good)
        for i, t in enumerate(temperatures):
            temperatures[i] = t or avg
    except Exception:
        print("3Error")


def fill4(temperatures):
    try:
        good = [t for t in temperatures if t is not None]
        avg = sum(good) / len(good)
        temperatures = [t or avg for t in temperatures]
    except Exception:
        print("4Error")


def fill5(temperatures):
    try:
        good = [t for t in temperatures if t is not None]
        avg = sum(good) / len(good)
        temperatures[:] = [t if t is not None else avg for t in temperatures]
    except Exception:
        print("5Error")


if __name__ == "__main__":
    list1 = [72, 101, 110, 114, 121, None, 32, 87, 111, 114, 108, 100, None, 33]
    fill1(list1)
    print(list1)

    list2 = [72, 101, 110, 114, 121, None, 32, 87, 111, 114, 108, 100, None, 33]
    fill2(list2)
    print(list2)

    list3 = [72, 101, 110, 114, 121, None, 32, 87, 111, 114, 108, 100, None, 33]
    fill3(list3)
    print(list3)

    list4 = [72, 101, 110, 114, 121, None, 32, 87, 111, 114, 108, 100, None, 33]
    fill4(list4)
    print(list4)

    list5 = [72, 101, 110, 114, 121, None, 32, 87, 111, 114, 108, 100, None, 33]
    fill5(list5)
    print(list5)
