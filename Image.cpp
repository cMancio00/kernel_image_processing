#include "Image.h"
#include <iostream>
#include <format>

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif // STB_IMAGE_IMPLEMENTATION

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

}

void Image::resizeImage(int new_width, int new_height, Image &image) {

}