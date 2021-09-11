import math


def is_prime_number(x):
    if x == 1:
        return False
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True


def convert(n, k):
    answer = ''
    if n // k < 1:
        return str(n)
    while n // k >= 1:
        remain = n % k
        n = n // k
        answer = str(remain) + answer
        if n < k:
            answer = str(n) + answer
    return answer


def solution(n, k):
    c = convert(n, k)
    convert_number = '0' + c + '0'
    if len(convert_number) == 3:
        if is_prime_number(int(c)):
            return 1
        return 0
    left_index, right_index = 0, 1
    answer = 0

    while right_index < len(convert_number):
        if convert_number[right_index] != '0':
            right_index += 1
            continue
        if convert_number[left_index] != '0':
            left_index += 1
            continue

        if convert_number[left_index] == '0' and convert_number[right_index] == '0':
            if left_index + 1 == right_index:
                left_index += 1
                right_index += 1
                continue
            if not is_prime_number(int(convert_number[left_index:right_index])):
                left_index = right_index
                right_index += 1
                continue
            answer += 1
            left_index = right_index
            right_index += 1
    return answer


if __name__ == '__main__':
    n = 437674
    k = 3
    # n = 110011
    # k = 10
    # n = 3
    # k = 3
    # n = 1000000
    # k = 2
    print(solution(n, k))
