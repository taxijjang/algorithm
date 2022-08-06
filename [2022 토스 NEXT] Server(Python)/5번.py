def solution(text):
    text_list = text.split(" ")
    answer = list()

    for word in text_list:
        if not len(word) >= 3:
            answer.append(word)
            continue
        answer.append(word[::-1])
    return ' '.join(answer)


if __name__ == "__main__":
    text = "안녕하세요 저는 김박산다라퐁구리입니다"
    text = "안녕하세요 저는 김박산다라퐁구리입니다"
    text = "하이이"
    print(solution(text))
