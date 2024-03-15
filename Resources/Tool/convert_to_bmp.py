"""
功能描述：將當前資料夾內所有圖片轉成 bmp。

使用方式：此檔案必須與目標圖片位於相同目錄。
在終端機輸入 python convert_to_bmp.py 即可。
"""

import os
import cv2

def convert_to_bmp(image_path):
    # Load the image
    image = cv2.imread(image_path)
    if image is None:
        print(f"Unable to read file: {image_path}")
        return
    
    # Get the filename and extension
    file_name, file_extension = os.path.splitext(image_path)
    
    # Convert to BMP format
    bmp_file = f"{file_name}.bmp"
    cv2.imwrite(bmp_file, image)
    print(f"Converted {image_path} to BMP format: {bmp_file}")

def main():
    # Get all files in the current directory
    files = os.listdir()
    
    # Filter only image files
    image_files = [file for file in files if file.lower().endswith(('.png', '.jpg', '.jpeg', '.gif', '.bmp'))]
    
    # Convert each image to BMP
    for image_file in image_files:
        convert_to_bmp(image_file)

if __name__ == "__main__":
    main()
