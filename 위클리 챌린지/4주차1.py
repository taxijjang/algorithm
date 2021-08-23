from collections import defaultdict


def make_language_score_data(table):
    language_scores = defaultdict(dict)
    rank_score = [i for i in range(5, 0, -1)]
    for table_data in table:
        table_list = (''.join(table_data)).split(' ')
        job = table_list.pop(0)
        data = dict(zip(table_list, rank_score))
        language_scores[job] = data

    return language_scores


def calc_score(language_scores, input_datas):
    result_company = defaultdict(set)
    for company, language_data in language_scores.items():
        score_sum = 0
        for l, s in input_datas.items():
            try:
                score_sum += language_data[l] * s
            except KeyError:
                score_sum += 0 * s
        result_company[score_sum].add(company)
    result_company = sorted(result_company.items(), key=lambda x: x[0], reverse=True)
    _, companies = next(iter(result_company))
    return sorted(list(companies)).pop(0)


def solution(table, languages, preference):
    languages_scores = make_language_score_data(table)
    return calc_score(languages_scores, dict(zip(languages, preference)))


if __name__ == "__main__":
    # table = ["SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
    #          "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
    #          "GAME C++ C# JAVASCRIPT C JAVA"]
    # languages = ["PYTHON", "C++", "SQL"]
    # preference = [7, 5, 5]
    table = ["SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
             "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
             "GAME C++ C# JAVASCRIPT C JAVA"]
    languages = ["JAVA", "JAVASCRIPT"]
    preference = [7, 5]
    print(solution(table, languages, preference))
