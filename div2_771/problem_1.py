import sys


def input():
    return sys.stdin.readline().rstrip()


def main():
    n = int(input())

    for _ in range(n):
        m = input()
        number_list = list(map(int, input().split()))
        combi_list = combi(number_list)
        print(' '.join(map(str, combi_list)))


def combi(number_list):
    max_num = 510
    reverse_index = None
    for index, i in enumerate(number_list):
        if max_num > i:
            reverse_index = index
    revers = number_list[:reverse_index+1]
    number_list[:reverse_index+1] = revers[::-1]
    return number_list


if __name__ == '__main__':
    main()
