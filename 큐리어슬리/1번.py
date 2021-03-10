from collections import defaultdict, deque

def solution(n):
    ans = [4, 13]

    num_arr = deque()
    num_arr.append('4')
    num_arr.append('13')

    check_num = defaultdict(bool)
    check_num[4], check_num[13] = True, True

    while num_arr and len(num_arr) <10000:
        h_str = num_arr.popleft()

        for s in ['4','13']:
            left_str = s+h_str
            right_str = h_str+s

            if check_num[left_str] == False:
                num_arr.append(left_str)
                ans.append(int(left_str))
                check_num[left_str] = True

            if check_num[right_str] == False:
                num_arr.append(right_str)
                ans.append(int(right_str))
                check_num[right_str] = True
    ans.sort()
    return ans[n-1]

if __name__=="__main__":
    n = int(input())
    print(solution(n))