from collections import defaultdict


def get_college(variables):
    college = defaultdict(str)
    for left, right in variables:
        college[left] = right
    return college


def check_college(college):
    index = 0

    while True:
        has_change = False
        for key, value in college.items():
            if value.isalpha():
                continue
            elif not value.isalpha():
                if college[key] == college[value[1:-1]]:
                    continue
                college[key] = college[value[1:-1]]
                has_change = True
        if not has_change:
            break
    return college


def solution(tstring, variables):
    new_tstring = tstring.replace('{', '(').replace('}', ')')
    last_college = check_college(get_college(variables))


    # duplicate_check = defaultdict(True)
    # while True:
    #     left, right = variables[index]
    #     index = (index + 1) % len(variables)
    #
    #     tstring = tstring.replace(f'({left})', right)
    #     print(tstring)
    answer = ''
    return answer


if __name__ == "__main__":
    # tstring = 'this is {template} {template} is {state}'
    # variables = [["template", "string"], ["state", "change"]]

    tstring = '{a} {b} {c} {d} {i}'
    variables = [['b', '{c}'], ['a', '{b}'], ['e', '{f}'], ['h', 'i'], ['d', '{e}'], ['f', '{d}'], ['c', 'd']]

    tstring = 'this is {template} {template} is {state}'
    variables = [['template', '{state}'], ['state', '{template}']]
    print(solution(tstring=tstring, variables=variables))
