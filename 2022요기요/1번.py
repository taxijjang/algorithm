import heapq


def solution(stack1, stack2, stack3):
    stack4 = []
    stack4.extend([(-num, "1") for index, num in enumerate(stack1)])
    stack4.extend([(-num, "2") for index, num in enumerate(stack2)])
    stack4.extend([(-num, "3") for index, num in enumerate(stack3)])

    pq = []

    for data in stack4:
        heapq.heappush(pq, data)

    result = ""
    while (pq):
        num, stack_index = heapq.heappop(pq)
        result += stack_index

    return result


if __name__ == "__main__":
    stack1 = [2, 7]
    stack2 = [4, 5]
    stack3 = [1]
    print(solution(stack1, stack2, stack3))
