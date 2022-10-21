def getMaximumMex(arr, x):
    arr = sorted(arr)
    set_arr = set(arr)
    print(arr, set_arr)

    result = [False] * 10**5
    print(result)

    result_index = 0
    while True:
        for num in set_arr:
            if num



if __name__ == '__main__':
    arr = [1,3,4]
    x = 2
    print(getMaximumMex(arr, x))
