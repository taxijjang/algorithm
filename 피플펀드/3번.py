import json, requests


def getVoteCount(cityName, estimatedCost):
    response = requests.get(
        f"https://jsonmock.hackerrank.com/api/food_outlets?city={cityName}&estimated_cost={estimatedCost}"
    )

    if response.status_code != 200:
        return -1

    try:
        data_list = json.loads(response.content).get("data")
    except json.decoder.JSONDecodeError:
        return -1

    if not data_list:
        return -1 
    result = 0
    for data in data_list:
        result += data.get("user_rating").get("votes")

    return result


if __name__ == "__main__":
    cityName = "Delaware"
    estimatedCost = "0"
    print(getVoteCount(cityName, estimatedCost))
