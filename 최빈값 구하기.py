from collections import Counter


def solution(array):
    counter = Counter(array)
    res = sorted(counter.items(), key=lambda item: item[1], reverse=True)
    if len(res) == 1:
        return res[0][0]
    if res[0][1] == res[1][1]:
        return -1
    return res[0][0]


if __name__ == "__main__":
    array = [1, 2, 3, 3, 3, 4]
    print(solution(array))
