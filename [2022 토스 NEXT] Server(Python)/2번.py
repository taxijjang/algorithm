import math


def solution(param):
    sqrt_param = math.sqrt(param)
    return int(sqrt_param + 1) ** 2 if sqrt_param.is_integer() else -1


if __name__ == "__main__":
    param = 144
    print(solution(param))
