import re


def parse1():
    try:
        with open("access.log", "r") as f:
            for line in f:
                yield line.split()[1]
    except Exception:
        print("File not found")

def parse2():
    try:
        with open("access.log", "r") as f:
            for line in f:
                yield from re.findall(r'\d{2}:\d{2}:\d{2}', line)[:1]
    except Exception:
        print("File not found")

def parse3():
    try:
        with open("access.log", "r") as f:
            for line in f:
                yield re.findall(r"\d:\d:\d", line)[0]
    except Exception:
        print("File not found")

def parse4():
    try:
        with open("access.log", "r") as f:
            yield from f.split(" ")[1]
    except Exception:
        print("File not found")

def parse5():
    try:
        with open("access.log", "r") as f:
            for line in f:
                yield re.findall(r"\d+.\d+.\d+", line)[0]
    except Exception:
        print("File not found")

if __name__=="__main__":
    print(list(parse1()))
    print(list(parse2()))
    print(list(parse3()))
    print(list(parse4()))
    print(list(parse5()))
