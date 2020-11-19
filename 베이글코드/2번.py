import collections


def solution(N, relation, dirname):
    path = [0] * 100100
    path[0] = len(dirname[0])

    relate_dict = collections.defaultdict(list)

    for parent, children in relation:
        relate_dict[parent].append(children)

    answer = len(dirname[0])
    queue = collections.deque([1])
    visited = [False] * 100100

    while queue:
        parent = queue.popleft()
        visited[parent] = True

        for child in relate_dict[parent]:
            path[child - 1] = path[parent - 1] + 1 + len(dirname[child - 1])
            answer = max(answer, path[child - 1])

            if visited[child] == False:
                queue.append(child)
                visited[child] = True

    return answer

if __name__ == "__main__":
    N = 7
    relation = [[1, 2], [2, 5], [2, 6], [1, 3], [1, 4], [3, 7]]
    dirname = ["root", "abcd", "cs", "hello", "etc", "hello", "solution"]
    # relation = [[1, 2], [2, 3], [3, 4], [4, 5], [1, 6], [6, 7]]
    # dirname = ["root", "a", "b", "c", "d", "efghij", "k"]
    #relation = [[1, 6], [6, 2], [2, 3]]
    #dirname = ['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a']
    print(solution(N, relation, dirname))
