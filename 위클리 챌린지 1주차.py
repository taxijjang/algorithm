def solution(price, money, count):
    first_last_price_sum = price * (1 + count)
    half_first_last_price_sum = first_last_price_sum / 2
    total_price = first_last_price_sum * (count / 2) if count % 2 == 0 else first_last_price_sum * (
            count // 2) + half_first_last_price_sum

    return int(0 if total_price < money else total_price - money)


if __name__ == "__main__":
    price = 3
    money = 20
    count = 4
    print(solution(price, money, count))
