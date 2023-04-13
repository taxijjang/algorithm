import whisper


def main():
    model = whisper.load_model("base")
    result = model.transcribe("news.mp4", language="ko", fp16=False)
    print(result)


if __name__ == "__main__":
    main()
