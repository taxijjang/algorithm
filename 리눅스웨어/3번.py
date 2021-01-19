from collections import defaultdict

def solution(p):
    check = defaultdict(int)
    for card in p:
        check[card] += 1
    check = sorted(check.items(), key=(lambda x:x[1]))

    total_card_cnt = len(check)
    check_cnt = defaultdict(int)
    for key, value in check:
        check_cnt[value] += 1

    for key ,value in check_cnt.items():
        

    print(check_cnt)
    answer = 0
    return answer

if __name__=="__main__":
    # p = [3,2,1,4,5]
    p = [3,1,3,3,1,2,0,0,1,4]
    print(solution(p))