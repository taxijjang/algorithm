from collections import defaultdict, Counter


def solution(lottos, win_nums):
    lottos_counter = Counter(lottos)
    win_nums_counter = Counter(win_nums)
    coincide_num = len(lottos_counter & win_nums_counter)

    if not lottos_counter.get(0):
        return convert_count_rank(coincide_num), convert_count_rank(coincide_num)

    # elif lottos_counter.get(0)
    count_zero = lottos_counter.get(0)
    return convert_count_rank(coincide_num + count_zero), convert_count_rank(coincide_num)


def convert_count_rank(coincide_num):
    return 6 if coincide_num == 0 else (6 - coincide_num) % 6 + 1


if __name__ == '__main__':
    # lottos = [45, 4, 35, 20, 3, 9]
    # win_nums = [20, 9, 3, 45, 4, 35]
    # lottos, win_nums = [44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]
    lottos, win_nums = [0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25]
    lottos, win_nums = [1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12]
    print(solution(lottos, win_nums))
