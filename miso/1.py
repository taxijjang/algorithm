def solution(A):
    castle = 0

    left, right = 0, 0
    size = len(A)
    while True:
        if size == right:
            castle += 1
            return castle

        if A[left] == A[right]:
            right += 1
            continue

        if A[left] < A[right]:
            # 계곡인 조건
            if left - 1 < 0 or A[left - 1] > A[left]:
                castle += 1
                left = right
                continue
            # 계곡인 조건이 아니라서 계속 탐색
            elif A[left - 1] < A[left]:
                left = right
                continue

        if A[left] > A[right]:
            # 언덕인 조건
            if left - 1 < 0 or A[left - 1] < A[left]:
                castle += 1
                left = right
                continue
            # 언덕인 조건이 아니라서 계속 탐색
            elif A[left - 1] > A[left]:
                left = right
                continue

import random

if __name__ == "__main__":
    A = [2, 2, 3, 4, 3, 3, 2, 2, 1, 1, 2, 5]
    A = [1, 2, 3]
    A = [3, 2, 1]
    A = [2, 1, 2]
    A = [1,1,1,1,1,1,1,1,1,1,1]

    A = random.sample(range(-1000000000, 1000000000), 100000)
    print(solution(A))
