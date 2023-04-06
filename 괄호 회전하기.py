from collections import deque


def solution(word: str):
    result = 0
    size = len(word)
    for start in range(size):
        stack = deque()
        for index in range(size):
            index = (index + start) % size
            if len(stack) == 0:
                stack.append(word[index])
                continue

            top = stack.pop()
            if not check(top, word[index]):
                stack.append(top)
                stack.append(word[index])

        if not stack:
            result += 1
    return result


def check(top, input):
    if top == "[" and input == "]":
        return True
    elif top == "{" and input == "}":
        return True
    elif top == "(" and input == ")":
        return True
    return False


if __name__ == "__main__":
    a1 = "[](){}"
    a2 = "}]()[{"
    a3 = "[)(]"
    a4 = "}}}"
    print(solution(a2))
    print(solution(a3))
    print(solution(a4))
