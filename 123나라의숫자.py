import sys

def solution(n: int):
    answer = ""
    while(n != 0):
        namugi = int(n % 3)
        n = int(n / 3)
        if namugi == 0:
            answer = "4" + answer
            n -= 1

        elif namugi == 1 :
            answer = "1" + answer

        elif namugi == 2:
            answer = "2" + answer

    return answer


if __name__ == "__main__":
    num = int(sys.stdin.readline())
    print(solution(num))