from collections import defaultdict
def solution(arr):
    check_day = 1000000
    day_check = defaultdict(int)

    for day,customer in enumerate(arr):
        day += 1
        print(day, customer, day_check[customer])
        if day_check[customer]:
            print("hi")
            check_day = min(check_day, day - day_check[customer])
        day_check[customer] = day

    if check_day == 1000000:
        return -1
    else:
        return check_day

if __name__=="__main__":
    arr = [2,2]

    print(solution(arr))