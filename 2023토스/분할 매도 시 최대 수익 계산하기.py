def solution(prices, k):
    result = -1
    max_size = 101
    board = [[-1 for _ in range(max_size)] for _ in range(max_size)]
    maximum_index = len(prices) - k

    for index in range(maximum_index):
        if index == 3:
            print("ABC")
        total = prices[index] * k
        board[index][index] = -total
        recursive(board, prices, -total, k, index, index + 1, len(prices))

    for i in range(max_size):
        for j in range(max_size):
            result = max(result, board[i][j])
    return result


def recursive(board, prices, total, remain_sell_count, start_index, index, maximum_index):
    if remain_sell_count == 0:
        board[start_index][index] = total
        return

    for index in range(index, maximum_index):
        total += prices[index]
        recursive(board, prices, total, remain_sell_count - 1, start_index, index + 1, maximum_index)
        total += -prices[index]


if __name__ == "__main__":
    prices = [10, 7, 8, 5, 8, 7, 6, 2, 9]
    k = 3
    # prices = [15, 7, 8, 5, 6, 4, 3, 9]
    # k = 4

    # prices = [1, 2, 3]
    # k = 2
    print(solution(prices, k))
