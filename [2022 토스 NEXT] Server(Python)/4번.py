import collections


def solution(data):
    if not 가로_확인(data):
        return False
    if not 세로_확인(data):
        return False
    if not 사각형_확인(data):
        return False
    return True


def 가로_확인(data) -> bool:
    size = len(data)
    for x in range(size):
        num_counter = collections.Counter(data[x])
        if len(num_counter) != 9:
            return False
    return True


def 세로_확인(data):
    size = len(data)
    for y in range(size):
        num_counter = collections.Counter(list(zip(*data))[y])
        if len(num_counter) != 9:
            return False
    return True


def 사각형_확인(data):
    size = len(data)
    for x in range(0, size, 3):
        for y in range(0, size, 3):
            result_list = []
            for detail_x in range(3):
                for detail_y in range(3):
                    result_list.append(data[detail_x][detail_y])
            num_counter = collections.Counter(result_list)
            if len(num_counter) != 9:
                return False
    return True


if __name__ == "__main__":
    data = [[5, 3, 4, 6, 7, 8, 9, 1, 2], [6, 7, 2, 1, 9, 5, 3, 4, 8], [1, 9, 8, 3, 4, 2, 5, 6, 7],
            [8, 5, 9, 7, 6, 1, 4, 2, 3], [4, 2, 6, 8, 5, 3, 7, 9, 1], [7, 1, 3, 9, 2, 4, 8, 5, 6],
            [9, 6, 1, 5, 3, 7, 2, 8, 4], [2, 8, 7, 4, 1, 9, 6, 3, 5], [3, 4, 5, 2, 8, 6, 1, 7, 9]]
    data2 = [[5, 3, 4, 6, 7, 8, 9, 1, 2], [6, 7, 2, 1, 9, 0, 3, 4, 9], [1, 0, 0, 3, 4, 2, 5, 6, 0],
             [8, 5, 9, 7, 6, 1, 0, 2, 0], [4, 2, 6, 8, 5, 3, 7, 9, 1], [7, 1, 3, 9, 2, 4, 8, 5, 6],
             [9, 0, 1, 5, 3, 7, 2, 1, 4], [2, 8, 7, 4, 1, 9, 6, 3, 5], [3, 0, 0, 4, 8, 1, 1, 7, 9]]
    print(solution(data2))
