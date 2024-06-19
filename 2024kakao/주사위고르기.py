from itertools import combinations, product
from collections import Counter, defaultdict, OrderedDict
from typing import List

"""
1. 일단 주사위의 총 갯수 조회
2. A, B 주사위를 나눔
3. 선택한 주사위에서 숫자를 선택
4. 선택한 숫자를 더함
5. 더한 숫자를 비교
"""

dice_index = [i for i in range(6)]
dice_index_combi = list(combinations(dice_index, 6))

result = dict()


def solution(dice):
    total_dice_count = len(dice)
    get_count = len(dice) // 2

    total_dice_index = [i for i in range(len(dice))]
    total_dice_combi = list(combinations(total_dice_index, get_count))

    select_dice, win_count = [], 0
    for a_dice in total_dice_combi:
        a_dice = list(a_dice)
        b_dice = get_b_dice(a_dice, total_dice_count)
        a_dice, win_draw_lose = select_number_at_dice(dice, a_dice, b_dice)

        if select_dice == []:
            select_dice = a_dice
            win_count = win_draw_lose.get("win", 0)
        else:
            if win_count < win_draw_lose.get("win", 0):
                select_dice = a_dice
                win_count = win_draw_lose.get("win", 0)

    select_dice = [i+1 for i in select_dice]
    return select_dice


def get_b_dice(a_dice, total_dice_count):
    return [i for i in range(total_dice_count) if i not in a_dice]


def select_number_at_dice(dice_list, a_dice, b_dice):
    a = []
    for a_dice_index in a_dice:
        a.append(dice_list[a_dice_index])
    a_product_list = list(product(*a))
    a_result = [sum(a) for a in a_product_list]
    a_result.sort(reverse=True)

    b = []
    for b_dice_index in b_dice:
        b.append(dice_list[b_dice_index])
    b_product_list = list(product(*b))
    b_result = [sum(b) for b in b_product_list]
    b_result.sort(reverse=True)

    win_draw_lose = compare_count(Counter(a_result), Counter(b_result))

    return a_dice, win_draw_lose

def compare_count2(a_result: List[int], b_result: List[int]):
    win_draw_lose = defaultdict(int)
    for a in a_result:
        for b in b_result:
            if a > b:
                win_draw_lose["win"] += 1
            else:
                break
    return win_draw_lose

def compare_count(a: Counter, b: Counter):
    a = OrderedDict(a)
    b = OrderedDict(b)
    win_draw_lose = defaultdict(int)
    for a_key, a_value in a.items():
        for b_key, b_value in b.items():
            if a_key > b_key:
                win_draw_lose["win"] += b_value * a_value
    return win_draw_lose

if __name__ == "__main__":
    dice1 = [[1, 2, 3, 4, 5, 6], [3, 3, 3, 3, 4, 4], [1, 3, 3, 4, 4, 4], [1, 1, 4, 4, 5, 5]]
    result1 = [1, 4]

    dice2 = [[1, 2, 3, 4, 5, 6], [2, 2, 4, 4, 6, 6]]
    result2 = [2]

    dice3 = [[40, 41, 42, 43, 44, 45], [43, 43, 42, 42, 41, 41], [1, 1, 80, 80, 80, 80], [70, 70, 1, 1, 70, 70]]
    result3 = [1, 3]

    dice4 = [[40, 41, 42, 43, 44, 45], [43, 43, 42, 42, 41, 41], [1, 1, 80, 80, 80, 80], [70, 70, 1, 1, 70, 70],
             [40, 41, 42, 43, 44, 45], [43, 43, 42, 42, 41, 41], [1, 1, 80, 80, 80, 80], [70, 70, 1, 1, 70, 70],
             [40, 41, 42, 43, 44, 45], [43, 43, 42, 42, 41, 41]]
    result4 = [1, 3]

    print(solution(dice3))
