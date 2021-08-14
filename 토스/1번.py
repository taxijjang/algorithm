from collections import defaultdict, Counter


def solution(name_list):
    name_count = defaultdict(int)
    answer = []
    for name in name_list:
        new_name = name + chr(65 + name_count[name])
        answer.append(new_name)
        name_count[name] += 1
    return answer


if __name__ == '__main__':
    name_list = ["김비바", "김비바", "이비바", "김토스", "이비바", "김비바"]
    print(solution(name_list))
