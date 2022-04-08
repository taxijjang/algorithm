import collections


def get_index_count_alphabet(cards):
    index_count_alphabet = collections.defaultdict(lambda: collections.defaultdict(bool))

    for index in range(len(cards)):
        for alphabet in cards[index]:
            index_count_alphabet[index][alphabet] = True
    return index_count_alphabet


def total_count_alphabet(cards):
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
    index_count = get_index_count_alphabet(cards=cards)
    total_count = total_count_alphabet(cards=cards)
    answer = list()
    for word in words:
        if not do_alphabet_number_check(word=word, total_count=total_count):
            continue
        if do_where_alphabet_is_available(word=word, index_count=index_count):
            answer.append(word)
    return answer if answer else ["-1"]


if __name__ == '__main__':
    cards = ["ABACDEFG", "NOPQRSTU", "HIJKLKMM"]
    words = ["GPQM", "GPMZ", "EFU", "MMNA"]

    cards = ["AABBCCDD", "KKKKJJJJ", "MOMOMOMO"]
    words = ["AAAKKKKKMMMMM", "ABCDKJ"]
    print(solution(cards=cards, words=words))
