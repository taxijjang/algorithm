from itertools import permutations


def main(v):
    combis = list(permutations(v, len(v)))
    result = 0
    for combi in combis:
        combi_sum = 0
        for index in range(len(v) - 1):
            combi_sum += abs(combi[index] - combi[index + 1])
        result = max(result, combi_sum)
    return result


if __name__ == "__main__":
    v = [20, 8, 10, 1, 4, 15]
    print(main(v))
