from queue import PriorityQueue


def main(N, coffee_times):
    pq = PriorityQueue(maxsize=N)
    now_time = 0
    result = []
    for index, coffee_time in enumerate(coffee_times):
        if pq.full():
            h_end_time, h_index, h_now_time = pq.get()
            result.append(h_index)
            while not pq.empty():
                n_end_time, n_index, n_now_time = pq.get()
                if h_end_time == n_end_time:
                    result.append(n_index)
                elif h_end_time < n_end_time:
                    pq.put([n_end_time, n_index, n_now_time])
                    break
            now_time = h_end_time
        if not pq.full():
            end_time = now_time + coffee_time
            pq.put([end_time, index + 1, now_time])
    while not pq.empty():
        result.append(pq.get()[1])
    return result


if __name__ == "__main__":
    N, coffee_times = 100, [4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4,
                            2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2,
                            2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2, 5, 3, 4, 2, 2,
                            5, 3, 4, 2, 2, 5, 3]
    # N, coffee_times = 1, [100, 1, 50, 1, 1]
    print(main(N, coffee_times))
