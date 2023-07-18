from collections import Counter


def solution(s: str, N: int):
    result = -1
    #
    # if len(s) == 0:
    #     return result
    #
    # if len(s) == 1:
    #     if int(s) == 1 and N == 1:
    #         return 1
    #     return -1
    #
    # if len(s) == 2:
    #     if N == 1:
    #         return 1 if Counter(s).get("1") else -1
    #
    #     if (s == "12" or s == "21") and N == 2:
    #         return int(''.join(s))
    #     return -1

    for index in range(len(s)):
        flag = True
        temp = s[index: index + N]
        temp_count = Counter(temp)

        for num in range(1, N + 1):
            if not temp_count[str(num)]:
                flag = False
                break

        result = max(int(''.join(temp)), result) if flag else result

    return int(result)


if __name__ == "__main__":
    N1 = 2
    s1 = "1451232125"

    N2 = 3
    s2 = "313253123"

    N3 = 4
    s3 = "12412415"

    N4 = 1
    s4 = ""
    print(solution(s1, N1))
    print(solution(s2, N2))
    print(solution(s3, N3))
    print(solution(s4, N4))
