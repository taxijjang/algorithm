import collections


def solution(N):
    n_counter = collections.Counter(str(N))
    nums = sorted(n_counter, reverse=True)
    result = ''
    for num in nums:
        result = ''.join([result, num * n_counter.get(num)])
    return result


if __name__ == "__main__":
    N = 213
    print(solution(N))
