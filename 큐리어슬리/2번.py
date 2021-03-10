d = [[-1, 0], [0, 1], [1, 0], [0, -1]]
visited = [[0 for _ in range(4)] for _ in range(4)]
ans = 0

def search(board, hx, hy, cnt):
    global d, visited, ans
    visited[hx][hy] = 1

    for dx, dy in d:
        nx, ny = hx + dx, hy + dy

        if nx < 0 or nx >= 4 or ny < 0 or ny >= 4 or visited[nx][ny] == 1:
            continue

        if board[hx][hy] != board[nx][ny]:
            continue

        search(board, nx, ny, cnt + 1)

    ans = max(ans, cnt)
    visited[hx][hy] = 0

def solution(board):
    global ans
    for hx in range(4):
        for hy in range(4):
            search(board, hx, hy, 1)
    return ans if ans != 1 else -1


if __name__ == "__main__":
    board1 = [[3, 2, 3, 2], [2, 1, 1, 2], [1, 1, 2, 1], [4, 1, 1, 1]]
    board2 = [[4, 2, 3, 2], [2, 1, 2, 4], [1, 2, 3, 1], [4, 1, 4, 3]]
    print(solution(board2))
