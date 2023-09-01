import requests

def main():
    url = "https://www.naver.com"
    response = requests.get(url)
    print(response.content)
    response.headers.values()
    print("ASDFAS")
if __name__ == "__main__":
    main()