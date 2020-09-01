# import sys
# import re
# from itertools import product
# from itertools import permutations
# from itertools import combinations
#
#
# max_sum = 0
#
# def solution(expression):
#     print(expression)
#     num = re.findall('\d+', expression)
#     print(num)
#     kiho = re.findall('[*+-]', expression)
#     print(kiho)
#
#     kiho_index = list(index for index in range(len(kiho)))
#     visited = [False] * len(num)
#     print(kiho_index)
#     print(visited)
#
#     dfs(
#         num_arr=num,
#         kiho_arr=kiho_index,
#         visited=visited,
#         sum=0
#     )
#     answer = 0
#     return answer
#
#
# def dfs(num_arr, kiho_arr, visited, sum):
#     for i in range(len(kiho_arr)):
#         if visited[i] == False:
#             if visited[i + 1] == False:
#                 visited[i + 1] = True
#                 sum = calc(kiho_arr[i], num_arr[i], num_arr[i + 1])
#
#             else:
#                 sum = calc(kiho_arr[i], num_arr[i], str(sum))
#
#             visited[i] = True
#
#             dfs(
#                 num_arr=num_arr,
#                 kiho_arr=kiho_arr,
#                 visited=visited,
#                 sum=sum
#             )
#
#             visited[i] = False
#
#
# def calc(kiho, num_a, num_b):
#     num_a = int(num_a)
#     num_b = int(num_b)
#
#     if kiho == '*':
#         return num_a * num_b
#     elif kiho == "-":
#         return num_a - num_b
#     elif kiho == '+':
#         return num_a + num_b
#
#
# if __name__ == "__main__":
#     expression = sys.stdin.readline()
#     print(solution(expression=expression))

import sys

a, b = map(int, sys.stdin.readline().split())


def calc(a, b):
    c = a + b
    return c

print(a, b)

calc (a=a, b=b)
