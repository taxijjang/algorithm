from itertools import permutations
from itertools import combinations


def solution(n, board):
    combi_num = list(permutations([num for num in range(n)], 2))
    combi_location = list(combinations(combi_num, 3))
    print(combi_location)

    teacher_location = find_teacher(n, board)
    
    return None


def watch():
    pass


def find_teacher(n, board):
    location = []
    for x in range(n):
        for y in range(y):
            if board[x][y] == "T":
                location.append([x, y])
    return location


if __name__ == "__main__":
    n = int(input())
    board = [input().split() for _ in range(n)]
    print(solution(n, board))
