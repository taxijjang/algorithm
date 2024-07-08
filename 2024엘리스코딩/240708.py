"""
목표량
시간 제한: 1초
엘리스 토끼는 목표량을 정해 수학 문제를 열심히 풉니다. 목표량은 정수입니다.

내일 풀 수학 문제의 개수는 오늘 푼 문제 개수의 수와 숫자의 구성이 같으면서, 오늘 푼 문제 개수의 수보다 큰 수 중 가장 작은 수입니다.

예를 들어, 오늘 67문제를 풀었으면 다음 날 76문제를 풉니다.

오늘 푼 문제의 개수를 줬을 때 다음날 풀 문제의 개수를 출력하는 프로그램을 작성하세요.


지시사항
입력
첫 번째 줄에 오늘 푼 문제의 개수인 자연수 N을 입력합니다.


1≤N≤999999


정답이 반드시 있는 경우만 입력값으로 주어집니다.
출력
다음날 풀 문제의 개수를 출력합니다.
입력 예시
364
Copy
출력 예시
436
"""

import itertools

def main(num):
    nPr = list(itertools.permutations(str(num), len(str(num))))

    res = []

    for i in nPr:
        new_num = int(''.join(i))

        if new_num > num:
            res.append(new_num)

    res = sorted(res)
    nPr = res[0]

if __name__== "__main__":
    main(354)