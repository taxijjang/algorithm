import requests
import json


def main():
    headers = {"Authorization": "None"}
    url = "https://quriously-dev.airklass.biz/rest/contents/back-office/klass/assign-to-tenant"

    data = {
        "klassId": 500,
        "headline": "",
        "description": "",
        "categories": []
    }

    response = requests.post(url, headers=headers, data=json.dumps(data))
    print(response.status_code)


if __name__ == "__main__":
    main()
