#ifndef KERNEL_IMAGE_PROCESSING_IMAGE_H
#define KERNEL_IMAGE_PROCESSING_IMAGE_H

#include <cstdint>
#include <string>

struct Image{
    int width{0}, height{0}, channels{0};
    uint8_t *rgb_image{nullptr};

    static void loadImage(const std::string &image_path, Image &image);
    static Image resizeImage(const Image &image, int new_width, int new_height);
    static void saveImage(const std::string &output_path, Image image);
};

#endif //KERNEL_IMAGE_PROCESSING_IMAGE_H
