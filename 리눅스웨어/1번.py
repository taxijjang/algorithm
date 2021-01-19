def solution(a, b, c, d, e, f):
    a_res = (a - d) // 2 if (a - d) >= 0 else (a - d)
    b_res = (b - e) // 2 if (b - e) >= 0 else (b - e)
    c_res = (c - f) // 2 if (c - f) >= 0 else (c - f)

    res = a_res + b_res + c_res
    if res >= 0:
        return True
    else:
        return False


if __name__ == "__main__":
    a, b, c, d, e, f = 4, 4, 0, 2, 1, 2
    # a, b, c, d, e, f = 3,3,3,2,2,2
    #a, b, c, d, e, f = 2, 2, 1, 1, 1, 2
    print(solution(a, b, c, d, e, f))
