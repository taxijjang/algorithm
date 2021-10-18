def solution(sizes):
    left_max, right_max = 0, 0
    for left, right in sizes:
        left_max = max(max(left,right), left_max)
        right_max = max(min(left,right), right_max)
    return left_max * right_max


if __name__=='__main__':
    sizes = [[60, 50], [30, 70], [60, 30], [80, 40]]
    sizes = [[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]
    sizes = [[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]
    print(solution(sizes))
