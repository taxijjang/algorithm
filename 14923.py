import sys
from collections import deque

INF = 123124123231
VISITED_CHECK = 0
DESTORY_BLOCK = 1
COUNT = 2

dir = [[-1, 0], [0, 1], [1, 0], [0, -1]]


def solution(*args):
    n, m, start_x, start_y, ex, ey, board = args
    check_board = [[[False, False, -1] for _ in range(m + 1)] for _ in range(n + 1)]

    dq = deque([[start_x, start_y]])
    check_board[start_x][start_y] = [True, board[start_x][start_y], 0]
    while dq:
        hx, hy = dq.popleft()
        check_board[hx][hy][VISITED_CHECK] = True
        for dx, dy in dir:
            nx, ny = hx + dx, hy + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if check_board[nx][ny][VISITED_CHECK]:
                if not check_board[nx][ny][DESTORY_BLOCK] > check_board[hx][hy][DESTORY_BLOCK]:
                    continue
            if board[nx][ny] == 1 and check_board[hx][hy][DESTORY_BLOCK]:
                continue
            check_board[nx][ny][VISITED_CHECK] = True
            check_board[nx][ny][DESTORY_BLOCK] = check_board[hx][hy][DESTORY_BLOCK]
            check_board[nx][ny][COUNT] = check_board[hx][hy][COUNT] + 1
            if board[nx][ny] == 1:
                check_board[nx][ny][DESTORY_BLOCK] = True
            dq.append([nx, ny])
            if nx == ex and ny == ey:
                return check_board[nx][ny][COUNT]
    return check_board[ex][ey][COUNT]


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    hx, hy = map(int, sys.stdin.readline().split())
    ex, ey = map(int, sys.stdin.readline().split())
    board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    print(solution(n, m, hx - 1, hy - 1, ex - 1, ey - 1, board))
