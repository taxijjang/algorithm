from collections import defaultdict, deque


def solution(enters, leaves):
    loom, user_contact = defaultdict(bool), defaultdict(set)
    leave_pointer = 0
    for enter in enters:
        loom[enter] = True

        while loom[leaves[leave_pointer]]:
            for key, value in loom.items():
                if loom[key] and (key != leaves[leave_pointer]):
                    user_contact[leaves[leave_pointer]].add(key)
                    user_contact[key].add(leaves[leave_pointer])
            loom[leaves[leave_pointer]] = False
            leave_pointer += 1
            if leave_pointer >= len(leaves):
                leave_pointer -= 1

    return [len(user_contact[user_id]) for user_id in range(1, len(enters) + 1)]


if __name__ == '__main__':
    # enters, leaves = [1, 3, 2], [1, 2, 3]
    # enters, leaves = [1, 4, 2, 3], [2, 1, 3, 4]
    # enters, leaves = [3, 2, 1], [2, 1, 3]
    # enters, leaves= [3, 2, 1], [1, 3, 2]
    enters, leaves = [1, 4, 2, 3], [2, 1, 4, 3]

    print(solution(enters, leaves))
