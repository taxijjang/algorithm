import requests
import datetime
import json

BASE_URL = "https://quriously-dev.airklass.biz/rest/commerce"
HEADERS = {
    "Authorization": "Qube-token eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdGFnZSI6ImRldiIsInVzZXJfaWQiOjI0MywiZGlzcGxheU5hbWUiOiLtg53si5zsp7EiLCJlbWFpbF92ZXJpZnkiOnRydWUsInRlbmFudElkIjoicXVyaW91c2x5IiwicGVybWlzc2lvbkRhdGEiOiIiLCJ0b2tlbl90eXBlIjoiYWNjZXNzIiwiZXhwIjoxNjkxMjYwMTIxLCJqdGkiOiJlNmQ4ZjAyMS02YzcwLTQ0MGMtYjJlYS04YjMzZmY5YmEzMzQiLCJhY2NvdW50S2V5IjoiNDRkZWMzNzQtNzY5Mi00MGU0LWFkOTUtMWRlMWUxYjk2ZmFkIiwic3RhdHVzIjoiQUNUSVZFIn0.Zy0rsp_DOwBIhhvoIANaOUjLx0dKDvI2hh8N47vfT4w"}


def main():
    # 테넌트에 배정된 클래스 이여야 합니다.
    클래스아이디 = 417

    # 수강 기간은 일단 일 단위로 기재하셔야 합니다.
    수강기간 = 330
    정가, 할인가 = 1000000, 800099

    # 시작시간은 무조건 필수! 한국 시간으로 기재하셔야 합니다.
    # 종료 시간이 필요하면 시작 시간과 동일한 형태로 진행하면 됩니다.
    # ex) 시작시간, 종료시간 = 시간_변환(년=2023, 월=7, 일=12, 시=12, 분=0), None
    # ex) 시작시간, 종료시간 = 시간변환(년=2023, 월=7, 일=12, 시=12, 분=0), 시간변환(년=2023, 월=8, 일=12, 시=12, 분=0)
    시작시간, 종료시간 = 시간변환(년=2023, 월=7, 일=12, 시=12, 분=0), None

    상품생성프로세스(클래스아이디, 수강기간, 정가, 할인가, 시작시간, 종료시간)


def 상품생성프로세스(클래스아이디, 수강기간, 정가, 할인가, 시작시간, 종료시간):
    상품키 = 상품_생성(클래스아이디)
    print(상품키)

    옵션아이템키 = 상품_아이템_생성(상품키, 수강기간)
    print(옵션아이템키)

    상품유형키 = 상품_유형_생성(상품키, 옵션아이템키)
    print(상품유형키)

    상품_유형_가격_생성(상품키, 상품유형키, 정가, 할인가, 시작시간, 종료시간)

    비공개상태 = "UNLISTED"
    공개상태 = "LISTED"
    상품의_상태_변경(상품키, 상품유형키, 공개상태)


def 상품_생성(클래스아이디):
    path = "/product/klass-ticket"
    url = BASE_URL + path

    data = {"klassId": 클래스아이디}

    response = requests.post(url, headers=HEADERS, data=json.dumps(data))
    print(response.status_code)
    if response.status_code == 200:
        return response.text
    elif response.status_code == 400:
        response_data = response.json()
        return response_data.get("data").get("productKey")

    raise Exception("상품_생성_실패")


def 상품_아이템_생성(상품키: str, 기간: int):
    path = f"/product/{상품키}/option-group/_PERIOD/option-item"
    url = BASE_URL + path

    data = {"label": f"{기간}일", "value": f"{기간}d"}

    response = requests.post(url, headers=HEADERS, data=json.dumps(data))
    response_data = response.json()

    return response_data.get("id")


def 상품_유형_생성(상품키: str, 옵션아이템키: str, 플랫폼: str = "web"):
    path = f"/product/{상품키}/variant"
    url = BASE_URL + path

    data = {"platform": 플랫폼, "optionIdMap": {"_PERIOD": 옵션아이템키}}

    response = requests.post(url, headers=HEADERS, data=json.dumps(data))
    if response.status_code != 200:
        raise Exception("상품_유형_생성_실패")
    return response.text


def 상품_유형_가격_생성(상품키: str, 상품유형키: str, 정가: int, 할인가: int, 시작시간: str, 종료시간: str):
    path = f"/product/{상품키}/variant/{상품유형키}/product-price"
    url = BASE_URL + path

    data = {
        "listPrice": 정가,
        "salePrice": 할인가,
        "start": 시작시간,
        "end": 종료시간
    }

    response = requests.post(url, headers=HEADERS, data=json.dumps(data))
    if response.status_code != 201:
        raise Exception("상품_유형_가격_생성_실패")


def 상품의_상태_변경(상품키: str, 상품유형키: str, 상태: str):
    path = f"/product/{상품키}/variant/{상품유형키}/status"
    url = BASE_URL + path

    data = {"nextStatus": 상태}
    response = requests.patch(url, headers=HEADERS, data=json.dumps(data))
    if response.status_code != 200:
        raise Exception("상품의_상태_변경_실패")


def 시간변환(년: int, 월: int, 일: int, 시: int, 분):
    input_time = datetime.datetime(년, 월, 일, 시, 분)
    return input_time.strftime("%Y-%m-%dT%H:%M:%S%z+09:00")


if __name__ == "__main__":
    main()
