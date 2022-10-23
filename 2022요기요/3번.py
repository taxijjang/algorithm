def solution(S: str, C: [int]) -> int:
    duplicate_index_dict = check_duplicate_alphabet(S)
    result: int = 0

    max_length = len(S)
    for index in C:
        if len(duplicate_index_dict) == 0:
            return result

        if index == 0 or index == max_length:
            result += 1
            continue
        try:
            duplicate_index_dict.get(index - 1)
            duplicate_index_dict.pop(index - 1)
        except Exception:
            pass
        result += 1


    if len(duplicate_index_dict) != 0:
        return -1
    return 0


def check_duplicate_alphabet(S: str) -> {int, int}:
    result = dict()
    for i in range(len(S) - 1):
        if S[i] == S[i + 1]:
            result[i] = False
    return result


def solution(S: str, C: [int]) -> int:
    check_arr = []

    temp_S = []
    for index, num in S:
        temp_S.append([index, num])




if __name__ == "__main__":
    S = "aabcddcb"
    C = [3, 5, 1, 4, 7]
    print(solution(S, C))
