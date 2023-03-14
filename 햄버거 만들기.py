def solution(ingredient):
    check = "1231"
    ingredient_str = ''
    result = 0

    for i in ingredient:
        ingredient_str += str(i)
        if ingredient_str[-4:] == check:
            result += 1
            ingredient_str = ingredient_str[:-4]
    return result


if __name__ == "__main__":
    ingredient = [2, 1, 1, 2, 3, 1, 2, 3, 1]
    ingredient2 = [1, 3, 2, 1, 2, 1, 3, 1, 2]
    ingredient3 = [1, 1, 2, 1, 2, 3, 1, 3, 1, 2, 3, 1]
    print(solution(ingredient3))
