visited = [[False] * 110 for _ in range(110)]
check = [0] * 3

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def dfs(h_x, h_y, check_num, v):
    visited[h_x][h_y] = True

    for i in range(4):
        n_x, n_y = h_x + dx[i], h_y + dy[i]

        if n_x < 0 or n_x >= len(v) or n_y < 0 or n_y >= len(v):
            continue

        if v[n_x][n_y] != check_num or visited[n_x][n_y] == True:
            continue

        visited[n_x][n_y] = True
        dfs(n_x, n_y, check_num, v)


def solution(v):
    ## dfs를 이용하여 구역 체크

    v_size = len(v)
    for i in range(v_size):
        for j in range(v_size):
            if visited[i][j] == False:
                check[v[i][j]] += 1
                dfs(i, j, v[i][j], v)

    return check


if __name__ == "__main__":
    v = [[0,0,1],[2,2,1],[0,0,0]]
    print(solution(v))
