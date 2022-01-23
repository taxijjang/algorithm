import sys
from collections import defaultdict, Counter


def input():
    return sys.stdin.readline().rstrip()


def main():
    n, m = map(int, input().split())
    true_know_list = list(map(int, input().split()))
    true_know_list = list(true_know_list[1:])
    party_round_list = list()
    for _ in range(m):
        member = list(map(int, input().split()))
        party_round_list.append(Counter(member[1:]))

    result = 0
    is_check = defaultdict(bool)
    while True:
        is_final = False
        for round_num, party_round in enumerate(party_round_list, start=1):
            is_change = False
            if is_check[round_num]:
                continue
            for true_know in true_know_list:
                if true_know in party_round:
                    true_know_list.extend(party_round.keys())
                    true_know_list = list(set(true_know_list))
                    is_check[round_num] = True
                    is_change = True
                    break
            if not is_change:
                result += 1
            is_final |= is_change
        if not is_final:
            break
        result = 0
    return result


if __name__ == '__main__':
    print(main())
#
#
# def set_true_know_dict(visit_man_list, true_know_dict, bragging_dict):
#     for man in visit_man_list:
#         true_know_dict[man] = True
#         del bragging_dict[man][:]
#     return true_know_dict, bragging_dict
#
#
# def set_bragging_dict(story_num, visit_man_list, bragging_dict):
#     for man in visit_man_list:
#         bragging_dict[man].append(story_num)
#     return bragging_dict
#
#
# def get_result(bragging_dict):
#     result = dict()
#     for bragging in bragging_dict.values():
#         result.update(Counter(bragging))
#     return len(result.values())
#
#
# def init_true_know_dict(n):
#     true_know_dict = dict()
#     for i in range(1, n + 1):
#         true_know_dict[i] = False
#     return true_know_dict
#
#
# def main():
#     n, m = map(int, input().split())
#
#     true_know_dict = init_true_know_dict(n)
#     true_know_list = list(map(int, input().split()))
#     bragging_dict = defaultdict(list)
#
#     for num in true_know_list[1:]:
#         true_know_dict[num] = True
#
#     for story_num, i in enumerate(range(m)):
#         visit_man_list = list(map(int, input().split()))
#         check = False
#         for man in visit_man_list[1:]:
#             check = check | true_know_dict[man]
#         if check:
#             true_know_dict, bragging_dict = set_true_know_dict(visit_man_list[1:], true_know_dict, bragging_dict)
#         else:
#             bragging_dict = set_bragging_dict(story_num, visit_man_list[1:], bragging_dict)
#     return get_result(bragging_dict)
#
#
# if __name__ == '__main__':
#     print(main())
