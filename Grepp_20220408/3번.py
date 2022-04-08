import collections


def do_reservation_or_cancel(customer, K):
    CANCEL = 0
    RESERVATION = 1

    wait = collections.deque()
    assignment = collections.defaultdict(int)
    cancel_log = collections.defaultdict(bool)

    for number, (user, state) in enumerate(customer):
        if state == RESERVATION and len(assignment) < K:
            assignment[user] = True
        elif state == RESERVATION and len(assignment) >= K:
            wait.append(user)
        elif state == CANCEL:
            cancel_log[user] += 1
            if user in assignment:
                assignment.pop(user)
                cancel_log[user] -= 1
            if not wait and cancel_log[user] and state:
                cancel_log[user] -= 1
            while wait:
                if cancel_log[wait[0]]:
                    next_user = wait.popleft()
                    cancel_log[next_user] -= 1
                    continue
                if len(assignment) < K:
                    next_user = wait.popleft()
                    assignment[next_user] = True
                break
    return assignment


def solution(customer, K):
    """
    문제에서 제시한 과정을 구현하기 위해 queue(예약 대기)와 dict(배정, 취소 기록)를 이용하였습니다.
    이때 queue를 사용하여서 어려운점이 있었는데 queue안에 포함 되어 있는 상황에서 예약 취소를 진행 했을때 입니다.
    queue를 탐색하여 취소 유저를 찾을 수 있었으나, 탐색하는 시간이 O(N^2)가 소요될것으로 예상했습니다.
    그리하여 cancel_log라는 dict를 이용하여 취소 횟수를 기록하고
    queue에서 대기하고 있던 유저를 비교하여 취소된 유저인지 정상적인 유저인지 판단하도록 하였습니다.
    """
    result = [user for user in do_reservation_or_cancel(customer=customer, K=K).keys()]
    return sorted(result)