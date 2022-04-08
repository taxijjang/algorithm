import collections


def get_index_count_alphabet(cards):
    index_count_alphabet = collections.defaultdict(lambda: collections.defaultdict(bool))

    for index in range(len(cards)):
        for alphabet in cards[index]:
            index_count_alphabet[index][alphabet] = True
    return index_count_alphabet


def get_total_count_alphabet(cards):
    return collections.Counter(''.join(cards))


def do_alphabet_number_check(word, total_count):
    word_count = collections.Counter(word)
    for key, value in word_count.items():
        if total_count[key] < value:
            return False
    return True


def do_where_alphabet_is_available(word, index_count):
    CARD_LENGTH = 3
    use_set = set()

    for alphabet in word:
        for index in range(CARD_LENGTH):
            if index_count[index][alphabet]:
                use_set.add(index)

    if len(use_set) == CARD_LENGTH:
        return True
    return False


def solution(cards, words):
    """
    1. 먼저 카드에 있는 각각의 알파벳의 갯수를 구하고 단어로 만들 수 있는지 확인 했습니다.
    2. [줄의 위치][알파벳]로 구분할 데이터를 만들어 놓은 후
    3. 줄의 위치를 반복하여 [줄의 위치(0)]['A'], [줄의 위치(1)]['A'], [줄의 위치(2)]['A']이 존재하는지 확인 하여 set에 저장
    4. data가 저장된 set의 길이를 확인 (카드의 길이는 3) 길이가 3이면 만들기 가능, 아니면 불가
    """
    index_count = get_index_count_alphabet(cards=cards)
    total_count = get_total_count_alphabet(cards=cards)
    answer = list()
    for word in words:
        if not do_alphabet_number_check(word=word, total_count=total_count):
            continue
        if do_where_alphabet_is_available(word=word, index_count=index_count):
            answer.append(word)
    return answer if answer else ["-1"]