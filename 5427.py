import sys
from collections import deque
sys.setrecursionlimit(10000)

def BFS():
    m,n = map(int,sys.stdin.readline().split())

    board = []
    visited = [[False] * m for _ in range(n)]
    q = deque()

    SANG = 0
    FIRE = 1
    for i in range(n):
        board.append(list(sys.stdin.readline().rstrip()))
        for j in range(m):
            if board[i][j] == '*':
                q.appendleft([i,j,0,FIRE])

            elif board[i][j] == '@':
                q.append([i,j,0,SANG])

    while q:
        hx,hy,hdis,what = q.popleft()
        visited[hx][hy] = True

        for dx,dy in (-1,0),(0,1),(1,0),(0,-1):
            nx,ny,ndis = hx + dx , hy + dy, hdis + 1

            if nx <0 or nx >=n or ny <0 or ny>=m:
                if what == FIRE:
                    board[hx][hy] = '#'
                    continue
                
                elif what == SANG:
                    print(ndis)
                    return

            if visited[nx][ny] == True or board[nx][ny] == '#':
                continue

            visited[nx][ny] = True
            q.append([nx,ny,ndis,what])

    print("IMPOSSIBLE")
t = int(sys.stdin.readline())

for _ in range(t):
    BFS()