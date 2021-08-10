from collections import deque
from collections import defaultdict

MIRROR_COUNT = 0
DIR_CHECK = 1


def start_loc(n, m):
    for x in range(n):
        for y in range(m):
            if board[x][y] == 'C':
                return x, y


def check_direction(hx, hy, nx, ny):
    dic = dict()
    dic[0][1] = 'h'
    dic[1][0] = 'w'
    return dic[abs(hx - nx)][abs(hy - ny)]


def solution(n, m, board):
    start_x, start_y = start_loc(n, m)
    # mirror_count = [[count, dir] * n for _ in range(m)]
    mirror_count = [[{'-1, '''}] * n for _ in range(m)]

    dir = [[0, -1], [1, 0], [0, 1], [-1, 0]]
    q = deque([[start_x, start_y]])

    while (q):
        hx, hy = q.popleft()
        mirror_count[hx][hy][MIRROR_COUNT] = 0

        for dx, dy in dir:
            nx, ny = hx + dx, hy + dy
            if nx < 0 or nx >= m or ny < 0 or ny >= n or board[nx][ny] == '*' or mirror_count[nx][ny][
                MIRROR_COUNT] != -1:
                continue
            mirror_count[nx][ny][MIRROR_COUNT] += mirror_count[hx][hy][MIRROR_COUNT]
            new_direction = check_direction(hx, hy, nx, ny)
            old_direction = mirror_count[hx][hy][DIR_CHECK]

            if new_direction != old_direction:
                mirror_count[nx][ny][MIRROR_COUNT] += 1

            q.append([nx, ny])

            if board[nx][ny] == 'C':
                return mirror_count[nx][ny][MIRROR_COUNT]


if __name__ == "__main__":
    n, m = map(int, input().split())
    board = [list(input()) for _ in range(8)]

    print(solution(m, n, board))
