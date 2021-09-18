def solution(weights, head2head):
    result = []
    for id, (w, h) in enumerate(zip(weights, head2head), start=1):
        win_count, over_win_count, no_match = 0, 0, 0
        for target_id, win_lose_data in enumerate(h, start=1):
            if id == target_id or win_lose_data == 'N':
                no_match += 1
                continue
            if win_lose_data == "W":
                win_count += 1
                if w < weights[target_id - 1]:
                    over_win_count += 1

        try:
            win_rate = win_count / (len(weights) - no_match)
        except ZeroDivisionError:
            win_rate = 0
        result.append([win_rate, over_win_count, w, id])

    result = sorted(result, key=lambda x: (-x[0], -x[1], -x[2], x[3]))
    result = list(zip(*result))[3]
    return result


if __name__ == '__main__':
    weights, head2head = [50, 82, 75, 120], ["NLWL", "WNLL", "LWNW", "WWLN"]
    # weights, head2head = [145, 92, 86], ["NLW", "WNL", "LWN"]
    # weights, head2head=[60, 70, 60],["NNN", "NNN", "NNN"]
    print(solution(weights, head2head))
