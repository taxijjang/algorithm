import sys
from itertools import combinations
from itertools import chain
from collections import Counter
from collections import deque

d = [[-1, 0], [0, 1], [1, 0], [0, -1]]

INF = 123123123123


def input():
    return sys.stdin.readline().rstrip()


def get_virus_visited_loc(n, m, board):
    res = []
    for i in range(n):
        for j in range(n):
            if board[i][j] == 2:
                res.append([i, j, 0])

    virus_loc_combi = list(combinations(res, m))
    return virus_loc_combi


def get_check_count(visited):
    res_count = set(chain(*visited))
    res_count = sorted(res_count)
    if res_count[0] == -1:
        return -1
    if res_count.pop() == INF:
        return res_count.pop()


def get_visited(n, board):
    visited = [[-1 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                visited[i][j] = INF
    return visited

def main():
    n, m = map(int, input().split())
    board = [[int(x) for x in input().split()] for y in range(n)]
    virus_loc_combi = get_virus_visited_loc(n, m, board)
    res_count = []
    for virus_loc in virus_loc_combi:
        visited = get_visited(n, board)
        q = deque(virus_loc)
        while (q):
            hx, hy, ht = q.popleft()
            visited[hx][hy] = ht

            for dx, dy in d:
                nx, ny = hx + dx, hy + dy
                if nx < 0 or ny < 0 or nx >= n or ny >= n:
                    continue
                if board[nx][ny] == 1:
                    continue
                if visited[nx][ny] != -1:
                    continue
                nt = ht + 1
                visited[nx][ny] = nt
                q.append([nx, ny, nt])
        res_count.append(get_check_count(visited))
    res_count = sorted(set(res_count))
    if res_count[0] == -1:
        try:
            if res_count[1] != -1:
                return res_count[1]
        except IndexError:
            return -1
    return min(res_count)


if __name__ == "__main__":
    print(main())
