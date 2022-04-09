from collections import Counter, defaultdict


def solution(call):
    call_lower = call.lower()
    alphabet_count = Counter(call_lower).most_common()
    max_alphabet = defaultdict(bool)
    max_count = alphabet_count[0][1]
    answer = ''

    for (alphabet, count) in alphabet_count:
        if max_count == count:
            max_alphabet[alphabet] = True

    for index, alphabet in enumerate(list(call_lower)):
        if max_alphabet[alphabet]:
            continue
        answer += call[index]
    return answer


if __name__ == '__main__':
    call = 'abcabcdefabc'
    call = 'ABCabcA'
    call = 'AAAAAAAAAAAAAbBCCccaadferdf'
    print(solution(call=call))
