import sys
from collections import deque
from itertools import chain
m , n = map(int,sys.stdin.readline().split())

board = [list(map(int,sys.stdin.readline().split()))for _ in range(n)]

visited = [[0]* m for _ in range(n)]

dq = deque()

for i, line in enumerate(board):
    for j, box in enumerate(line):
        if box == 1:
            dq.append([i,j])
            visited[i][j] = 1
        elif box == -1:
            visited[i][j] = -1

res = 0
while dq:
    h_x,h_y = dq.popleft()
    res = max(res,visited[h_x][h_y])
    for x,y in (-1,0),(0,1),(1,0),(0,-1):
        n_x, n_y = h_x + x, h_y + y

        if n_x <0 or n_x >= n or n_y <0 or n_y >=m or visited[n_x][n_y] != 0:
            continue

        visited[n_x][n_y] = visited[h_x][h_y] + 1
        dq.append([n_x,n_y])

if 0 in chain(*visited):
    print(-1)
else:
    print(res-1)

