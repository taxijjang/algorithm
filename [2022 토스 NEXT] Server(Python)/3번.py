def solution(data):
    answer = []
    zero_count = 0
    for num in data:
        if num:
            answer.append(num)
        else:
            zero_count += 1
    answer += [0] * zero_count
    return answer


if __name__ == "__main__":
    data = [1, 0, 2, 0, 3]
    print(solution(data))
