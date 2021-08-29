import sys

N = 10010
INF = 12312312313

def prime_list():
    sieve = [False, False] + [True] * N

    m = int(N ** 0.5)
    for i in range(2, m + 1):
        if sieve[i] == True:
            for j in range(i + i, N, i):
                sieve[j] = False

    return sieve


def solution(n, m):
    prime = prime_list()

    prime_sum, prime_small = 0, INF
    for i in range(n, m + 1):
        if prime[i]:
            prime_sum += i
            if prime_small == INF:
                prime_small = i
    if not prime_sum and prime_small == INF:
        print(-1)
        return
    print(prime_sum, prime_small)


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    solution(n, m)
