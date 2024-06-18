#ifndef KERNEL_IMAGE_PROCESSING_IMAGE_H
#define KERNEL_IMAGE_PROCESSING_IMAGE_H

#include <cstdint>
#include <string>

struct Image{
    int width{0}, height{0}, channels{0};
    uint8_t *rgb_image{nullptr};

    static void loadImage(const std::string &image_path, Image &image);
    void resizeImage(int new_width, int new_height, Image &image);
    static void saveImage(const std::string &output_path, Image image);
};

#endif //KERNEL_IMAGE_PROCESSING_IMAGE_H
