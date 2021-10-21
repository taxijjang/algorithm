board = [[0] * 51 for _ in range(51)]
visited = [[0] * 51 for _ in range(51)]
dir = [[-1, 0], [0, 1], [1, 0], [0, -1]]
max_len = 0


def make_rectangle(rectangle):
    for index, r in enumerate(rectangle, start=1):
        l_x, l_y, r_x, r_y = r
        for x in range(l_x, r_x + 1):
            for y in range(l_y, r_y + 1):
                board[x][y] = 1
    return board


def check_out_line():
    for x in range(51):
        for y in range(51):
            if y != 0 and board[x][y-1] == 0 and board[x][y]:
                board[x][y] = 2
            elif y == 0 and board[x][y]:
                board[x][y] = 2

        for y in range(50, -1, -1):
            if y != 50 and board[x][y + 1] == 0 and board[x][y]:
                board[x][y] = 2
            elif y == 50 and board[x][y]:
                board[x][y] = 2

    for y in range(51):
        for x in range(51):
            if x != 0 and board[x - 1][y] == 0 and board[x][y]:
                board[x][y] = 2
            elif x == 0 and board[x][y]:
                board[x][y] = 2

        for x in range(50, -1, -1):
            if x != 50 and board[x + 1][y] == 0 and board[x][y]:
                board[x][y] = 2
            elif x == 50 and board[x][y]:
                board[x][y] = 2


def dfs(h_x, h_y, rec_num):
    global max_len
    if not board[h_x][h_y]:
        return

    tmp = []
    for d_x, d_y in dir:
        n_x, n_y = h_x + d_x, h_y + d_y

        if n_x < 0 or n_y < 0 or n_x >= 50 or n_y >= 50:
            continue
        if board[n_x][n_y] == -1 or not board[n_x][n_y]:
            continue
        if visited[n_x][n_y]:
            continue

        if rec_num == board[n_x][n_y]:
            tmp = []
            max_len = max(max_len, visited[h_x][h_y] + 1)
            visited[n_x][n_y] = visited[h_x][h_y] + 1
            dfs(n_x, n_y, rec_num)
            return
        # rec_num != board[n_x][n_y]
        else:
            tmp.append([n_x, n_y, board[n_x][n_y]])

    if tmp:
        tmp = sorted(tmp, key=lambda x: x[2])
        n_x, n_y, next_rec_num = tmp.pop()
        max_len = max(max_len, visited[h_x][h_y] + 1)
        visited[n_x][n_y] = visited[h_x][h_y] + 1
        dfs(n_x, n_y, next_rec_num)


def solution(rectangle, characterX, characterY, itemX, itemY):
    make_rectangle(rectangle)
    check_out_line()
    visited[characterX][characterY] = 1
    dfs(characterX, characterY, board[itemX][itemY])
    return min(visited[itemX][itemY] - 1, max_len - visited[itemX][itemY] + 1)


if __name__ == '__main__':
    rectangle = [[1, 1, 7, 4], [3, 2, 5, 5], [4, 3, 6, 9], [2, 6, 8, 8]]
    characterX = 1
    characterY = 3
    itemX = 7
    itemY = 8
    rectangle = [[1, 1, 8, 4], [2, 2, 4, 9], [3, 6, 9, 8], [6, 3, 7, 7]]
    characterX = 9
    characterY = 7
    itemX = 6
    itemY = 1

    print(solution(rectangle, characterX, characterY, itemX, itemY))
