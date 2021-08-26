import sys
import datetime

if __name__ == '__main__':
    hh, mm = map(int, sys.stdin.readline().split())
    spend_mm = int(sys.stdin.readline())

    result = datetime.datetime.strptime(f'{hh} {mm}', '%H %M') + datetime.timedelta(minutes=spend_mm)
    print(result.strftime('%-H %-M'))

