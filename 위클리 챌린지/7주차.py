from collections import defaultdict, deque


def solution(enters, leaves):
    loom = defaultdict(bool)
    user_contact = defaultdict(set)
    index = 0
    for enter in enters:
        loom[enter] = True

        while loom[leaves[index]]:
            for key, value in loom.items():
                if loom[key] and (key != leaves[index]):
                    user_contact[leaves[index]].add(key)
                    user_contact[key].add(leaves[index])
            loom[leaves[index]] = False
            index += 1
            if index >= len(leaves):
                index -= 1

    user_contact = sorted(user_contact, key=lambda x: user_contact.keys())
    print(user_contact)
    answer = []
    return answer


if __name__ == '__main__':
    # enters, leaves = [1, 3, 2], [1, 2, 3]
    enters, leaves = [1, 4, 2, 3], [2, 1, 3, 4]
    # enters, leaves = [3, 2, 1], [2, 1, 3]
    # enters, leaves= [3, 2, 1], [1, 3, 2]
    # enters, leaves = [1, 4, 2, 3], [2, 1, 4, 3]

    print(solution(enters, leaves))
