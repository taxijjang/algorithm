from collections import deque


def solution(B):
    start_x, start_y = get_start(B)
    end_x, end_y = len(B) - 1, len(B[0]) - 1
    new_board, visited_board = init_board(B)
    new_board = set_board(B, new_board)

    d = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    q = deque()
    q.appendleft([start_x, start_y])
    while q:
        h_x, h_y = q.popleft()
        visited_board[h_x][h_y] = 1
        for dx, dy in d:
            n_x, n_y = h_x + dx, h_y + dy
            if n_x < 0 or n_x > end_x or n_y < 0 or n_y > end_y:
                continue
            if visited_board[n_x][n_y] == 1:
                continue
            if new_board[n_x][n_y] == "X" or new_board[n_x][n_y] == "Z":
                continue
            if n_x == end_x and n_y == end_y:
                return True
            q.append([n_x, n_y])
    return False


def get_start(B):
    max_x, max_y = len(B), len(B[0])
    for x in range(max_x):
        for y in range(max_y):
            if B[x][y] == 'A':
                return x, y


def init_board(B):
    x, y = len(B), len(B[0])
    new_board = ['.' * y for _ in range(x)]
    visited_board = [[False] * y for _ in range(x)]
    return new_board, visited_board


def set_board(B, new_board):
    max_x, max_y = len(B), len(B[0])
    guard = {
        "^": [-1, 0],
        ">": [0, 1],
        "v": [1, 0],
        "<": [0, -1],
    }

    for x in range(max_x):
        for y in range(max_y):
            if B[x][y] == 'X':
                new_board_list = list(new_board[x])
                new_board_list[y] = 'X'
                new_board[x] = ''.join(new_board_list)
                continue
            if B[x][y] == 'A':
                new_board_list = list(new_board[x])
                new_board_list[y] = 'A'
                new_board[x] = ''.join(new_board_list)
                continue
            if guard.get(B[x][y]):
                next_x, next_y = x, y
                while True:
                    try:
                        if B[next_x][next_y] == "A" or B[next_x][next_y] == "X":
                            break
                    except Exception:
                        print("ABC")
                    new_board_list = list(new_board[next_x])
                    new_board_list[next_y] = 'Z'
                    new_board[next_x] = ''.join(new_board_list)
                    next_x += guard.get(B[x][y])[0]
                    next_y += guard.get(B[x][y])[1]
                    if next_x < 0 or next_y < 0 or next_x >= max_x or next_y >= max_y:
                        break
                    if guard.get(B[next_x][next_y]):
                        break
    return new_board


if __name__ == "__main__":
    B = ['X.....>', '..v..X.', '.>..X..', 'A......']
    B1 = ['...Xv', 'AX..^', '.XX..']
    B2 = ['...', '>.A']
    B3 = ['A.v', '...']
    B4 = ['>..', 'A..']
    B5 = ['AXXX', 'X...']
    print(solution(B5))
