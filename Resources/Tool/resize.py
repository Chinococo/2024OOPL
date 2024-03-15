"""
功能描述：將任意圖片維持比例放大或縮小到寬度為 600 像素，然後轉成 bmp。

使用方式：此檔案必須與目標圖片位於相同目錄。
在終端機輸入 python resize.py <圖片名稱含副檔名> 即可。
"""

import cv2
import sys

def resize(image, expected_width):
    height, width = image.shape[:2]
    aspect_ratio = width / height
    expected_height = int(expected_width / aspect_ratio)
    resized_image = cv2.resize(image, (expected_width, expected_height))
    return resized_image

def main():
    if len(sys.argv) != 2:
        print("Usage: python script_name.py filename")
        return
    
    file_name = sys.argv[1]
    expected_width = 600
    image = cv2.imread(file_name)
    
    if image is None:
        print("Error: Couldn't read the image file.")
        return
    
    resized_image = resize(image, expected_width)
    cv2.imwrite(f"Resized_{file_name}.bmp", resized_image)

if __name__ == "__main__":
    main()
