import collections


def solution(data):
    left, right = data

    left_scroe = calc_score(left)
    right_score = calc_score(right)

    if left_scroe > right_score:
        return "첫 번쩨"
    elif left_scroe < right_score:
        return "두 번째"
    else:
        return "무승부"


def calc_score(word):
    word_counter = collections.Counter(word)

    score_board = {
        "!": 2,
        "?": 3,
    }
    result = 0
    for key, value in score_board.items():
        result += word_counter[key] * value
    return result


if __name__ == "__main__":
    data = ["!!", "!!"]
    print(solution(data))
