from datetime import timedelta
from datetime import date


class DateRangeIterable:
    """자체 이터레이터 메서드를 가지고 있는 이터러블"""

    # def __init__(self, start_date, end_date):
    #     self.start_date = start_date
    #     self.end_date = end_date
    #     self._present_day = start_date

    # 일반적인 이터러블
    # def __iter__(self):
    #     return self

    # def __next__(self):
    #     if self._present_day >= self.end_date:
    #         raise StopIteration
    #     today = self._present_day
    #     self._present_day += timedelta(days=1)
    #     return today

    # 컨테이너 이터러블 - 일반적으로 그냥 이터러블 보다는 컨테이너 이터러블을 이욯하는게 좋다.
    # 그냥 이터러블은 종료가 되었을때 반복해서 다시 사용하는것이 불가능?하다
    def __init__(self, start_date, end_date):
        self.start_date = start_date
        self.end_date = end_date

    def __iter__(self):
        current_day = self.start_date
        while current_day < self.end_date:
            yield current_day
            current_day += timedelta(days=1)

if __name__ == "__main__":
    for day in DateRangeIterable(date(2019,1, 1), date(2020, 10, 13)):
        print(day)

    print(DateRangeIterable(date(2019,1, 1), date(2020, 10, 13)))


