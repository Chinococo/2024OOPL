import cv2


def resize(image, expected_width):
    height, width = image.shape[:2]
    aspect_ratio = width / height
    expected_height = int(expected_width / aspect_ratio)
    resized_image = cv2.resize(image, (expected_width, expected_height))
    return resized_image


def main():
    file_name = "Stage1"
    file_ext = "png"
    expected_width = 600
    image = cv2.imread(f"{file_name}.{file_ext}")
    resized_image = resize(image, expected_width)
    cv2.imwrite(f"Resized_{file_name}.bmp", resized_image)


main()
