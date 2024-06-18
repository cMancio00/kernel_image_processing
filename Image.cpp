#include "Image.h"
#include <iostream>
#include <format>

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif // STB_IMAGE_IMPLEMENTATION

#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#endif // STB_IMAGE_WRITE_IMPLEMENTATION

#ifndef STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"
#endif // STB_IMAGE_RESIZE_IMPLEMENTATION

using namespace std;

void Image::loadImage(const std::string &image_path, Image &image) {
    image.rgb_image = stbi_load(image_path.c_str(), &image.width, &image.height,
                                &image.channels, STBI_rgb);
    if (!image.rgb_image) {
        cerr << "LOAD FAILED! " << stbi_failure_reason() << endl;
    }else{
        cout << format("Loaded image {}x{}",image.width,image.height) << endl;
    }
}

void Image::saveImage(const std::string &output_path, Image image) {
    stbi_write_jpg(output_path.c_str(), image.width, image.height, image.channels,
                   image.rgb_image, 90);
    stbi_image_free(image.rgb_image);
}

Image Image::resizeImage(const Image &image, int new_width, int new_height) {
    Image resized_image;
    auto *resized_image_data = new unsigned char[new_width * new_height * 3];
    stbir_resize_uint8_srgb(image.rgb_image, image.width, image.height, image.width * 3, resized_image_data, new_width, new_height, new_width * 3,
                            static_cast<stbir_pixel_layout>(3));

    resized_image.width = new_width;
    resized_image.height = new_height;
    resized_image.channels = 3;
    resized_image.rgb_image = resized_image_data;

    return resized_image;
}

