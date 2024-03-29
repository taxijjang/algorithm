import collections


def init_calendar(weeks_index):
    month_per_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    weeks = [0, 0, 0, 0, 0, 1, 1]

    calendar = collections.defaultdict(collections.defaultdict)

    for month in range(len(month_per_days)):
        for day in range(1, month_per_days[month] + 1):
            calendar[month][day] = weeks[weeks_index]
            weeks_index = (weeks_index + 1) % len(weeks)
    return calendar


def solution(day, k):
    """
    간단하게 1년을 모두 채워 놓고 접근 했습니다.
    """
    calendar = init_calendar(weeks_index=day)

    answer = [calendar[month][k] for month in range(12)]
    return answer