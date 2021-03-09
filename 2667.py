import collections
import sys

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

ans = []
n = int(input())
board = [[int(s) for s in sys.stdin.readline().strip()] for _ in range(n)]


def BFS(i, j):
    global dx, dy, board, n, ans
    q = collections.deque()
    q.append([i, j])
    cnt = 0
    while q:
        cnt += 1
        hx, hy = q.popleft()
        board[hx][hy] = 0
        for i in range(4):
            nx, ny = hx + dx[i], hy + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if board[nx][ny] == 0:
                continue

            q.append([nx, ny])
            board[nx][ny] = 0

    ans.append(cnt)


for i in range(n):
    for j in range(n):
        if board[i][j] != 0:
            BFS(i, j)

print(len(ans))
for i in sorted(ans):
    print(i)
