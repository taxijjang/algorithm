import re

def each_sum(num):
    str_num = str(num)

def solution(card_numbers):
    pattern1, pattern2 = re.compile('\d{4}-\d{4}-\d{4}-\d{4}'), re.compile('\d{16}')

    answer = []

    for card_number in card_numbers:
        if (pattern1.match(card_number) and len(card_number) == 19) or \
                (pattern2.match(card_number) and len(card_number) == 16):

            if len(card_number) > 16:
                card_number = card_number.split('-')
                card_number = ''.join(card_number)

            even_sum, odd_sum = 0, 0
            for index, num in enumerate(card_number):
                if index % 2 == 0:
                    even_sum += sum(map(int, str(int(num) * 2)))
                else:
                    odd_sum += int(num)

            if (even_sum + odd_sum) % 10 == 0:
                answer.append(1)
            else:
                answer.append(0)
        else:
            answer.append(0)

    return answer


if __name__ == "__main__":
    # card_numbers = ["3285-3764-9934-2453", "3285376499342453", "3285-3764-99342453", "328537649934245", "3285376499342459", "3285-3764-9934-2452"]
    card_numbers = ["3285-3764-9934-2453"]
    print(solution(card_numbers))
