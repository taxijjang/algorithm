def to_upper_case(func):
    text = func()

    if not isinstance(text, str):
        raise TypeError("Not a string type")
    return text.upper()

def to_upper_case(func):
    def wrapper():
        text = func()
        if not isinstance(text, str):
            raise TypeError("Not a string type")
        return text.upper()
    return wrapper

def add_prefix(func):
    def wrapper():
        text = func()
        result = " ".join([text, "Larry Page!"])
        return result
    return wrapper

@to_upper_case
@add_prefix
def say():
    return "hihihihihihi"

@add_prefix
@to_upper_case
def say2():
    return "hihihihihihi"


def to_upper_case(func):
    def wrapper(*args, **kwargs):
        text = func(*args, **kwargs)
        if not isinstance(text, str):
            raise TypeError("Not a string type")
        return text.upper()
    return wrapper

@to_upper_case
def say(greet):
    return greet

if __name__ == "__main__":
    print(say("my name is taekyun"))
