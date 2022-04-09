import re
from collections import defaultdict


def get_message(x, y, direction):
    return f'Time {x}:Go straight {y}m and turn {direction}'


def init_direction():
    EAST = 'E'
    WEST = 'W'
    SOUTH = 'S'
    NORTH = 'N'

    direction = defaultdict(defaultdict)
    direction[EAST][NORTH] = 'left'
    direction[EAST][SOUTH] = 'right'
    direction[SOUTH][EAST] = 'left'
    direction[SOUTH][WEST] = 'right'
    direction[WEST][NORTH] = 'right'
    direction[WEST][SOUTH] = 'left'
    direction[NORTH][EAST] = 'right'
    direction[NORTH][WEST] = 'left'

    return direction


def get_compress_path(path):
    compress_path = ''
    path_list = list(path)
    compare_alphabet = ''
    alphabet_count = 0
    for alphabet in path_list:
        if compare_alphabet == alphabet:
            alphabet_count += 1
        elif compare_alphabet == '':
            compare_alphabet = alphabet
            alphabet_count += 1
        elif compare_alphabet != alphabet:
            compress_path += f'{alphabet_count}{compare_alphabet}'
            compare_alphabet = alphabet
            alphabet_count = 1
    compress_path += f'{alphabet_count}{compare_alphabet}'
    return compress_path


def get_rotate(compress_path):
    direction = init_direction()
    rotate = list()

    STEP = 2
    distance_list = re.findall(r'\d+', compress_path)
    rotate_list = re.findall(r'\D+', compress_path)
    for index in range(len(distance_list) - 1):
        rotate.append(direction[rotate_list[index]][rotate_list[index + 1]])
    return rotate


def get_time_and_distance(compress_path):
    time_and_distance = list()
    time = 0

    distance_list = re.findall(r'\d+', compress_path)
    rotate_list = re.findall(r'\D+', compress_path)

    for index in range(len(distance_list) - 1):
        distance = int(distance_list[index])
        if distance <= 5:
            time_and_distance.append([time, distance * 100])
        elif distance > 5:
            time_and_distance.append([distance - 5 + time, 500])
        time += distance
    return time_and_distance


def solution(path):
    compress_path = get_compress_path(path=path)
    print(compress_path)
    answer = list()
    rotate = get_rotate(compress_path=compress_path)
    print(rotate)
    time_and_distance = get_time_and_distance(compress_path=compress_path)
    for (time, distance), direction in zip(time_and_distance, rotate):
        answer.append(get_message(x=time, y=distance, direction=direction))
    return answer


if __name__ == '__main__':
    path = 'EEESEEEEEENNNN'
    path = 'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEN'
    print(solution(path=path))
