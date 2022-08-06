def solution(text):
    vowel = 'aeiou'
    answer = 0
    text = text.lower()
    for t in vowel:
        answer += text.count(t)
    return answer


if __name__ == "__main__":
    text = "aeiou"
    print(solution(text))
