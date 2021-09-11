from collections import defaultdict


def solution(id_list, report, k):
    users = defaultdict(set)
    mails = defaultdict(set)
    check_cnt = defaultdict(int)
    overlap_check = defaultdict(dict)
    for data in report:
        user, target_user = data.split(' ')
        users[user].add(target_user)
        mails[target_user].add(user+target_user)
        try:
            overlap_check[user][target_user]
        except KeyError:
            overlap_check[user][target_user] = True
            check_cnt[target_user] += 1

    answer = []
    for id in id_list:
        cnt = 0
        for value in users[id]:
            if check_cnt[value] >= k:
                cnt += 1
        answer.append(cnt)

    return answer


if __name__ == "__main__":
    id_list = ["muzi", "frodo", "apeach", "neo"]
    repost = ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"]
    k = 2
    #
    # id_list = ["con", "ryan"]
    # repost = ["ryan con", "ryan con", "ryan con", "ryan con"]
    # k =3
    print(solution(id_list, repost, k))
