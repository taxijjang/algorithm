from PIL import Image
import os
import sys

def resize_image(input_image_path, change_path, qualty=70):
    original_im = Image.open(input_image_path)

    original_im.save(os.path.join(change_path), quality=qualty)
    pass


if __name__=="__main__":
    original_path = "/Users/taxijjang/personal-git-dir/algorithm/image_resize/35m.jpeg"
    change_path = "/Users/taxijjang/personal-git-dir/algorithm/image_resize/what_size.jpeg"
    resize_image(original_path, change_path)