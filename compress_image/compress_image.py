from PIL import Image
import os
from boto3 import client

def compress_image(input_image_path, output_image_path, target_size=1024):
    image = Image.open(input_image_path)
    width, height = image.size

    # 이미지 품질을 점차 감소시켜 원하는 크기에 도달할 때까지 반복
    quality = 85
    while True:
        image.save(output_image_path, optimize=True, quality=quality)
        file_size = os.path.getsize(output_image_path) / 1024  # KB 단위

        if file_size <= target_size:
            break

        # 이미지 품질을 감소시키며 크기를 줄임
        print(quality)
        quality -= 3

    print(f"Compressed size (KB): {file_size}")


if __name__ == "__main__":
# 입력 이미지와 출력 이미지 경로 설정
    input_image = "/Users/taxijjang/personal-git-dir/algorithm/compress_image/6.1m.png"
    output_image = "compressed_image.jpg"

    # 이미지 압축 실행
    compress_image(input_image, output_image)

