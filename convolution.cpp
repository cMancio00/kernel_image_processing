#include "convolution.h"

Image convolve(const Image &image, const Kernel &kernel) {
    Image convolved;
    convolved.width = image.width - kernel.dimension + 1;
    convolved.height = image.height - kernel.dimension + 1;
    convolved.channels = image.channels;
    convolved.rgb_image = new uint8_t[convolved.width * convolved.height * convolved.channels];

    for (int image_width = 0; image_width < convolved.width; ++image_width) {
        for (int image_height = 0; image_height < convolved.height; ++image_height) {
            for (int channels = 0; channels < convolved.channels; ++channels) {
                float sum = 0.0f;
                for (int kernel_width = 0; kernel_width < kernel.dimension; ++kernel_width) {
                    for (int kernel_height = 0; kernel_height < kernel.dimension; ++kernel_height) {
                        int x = image_width + kernel_width - kernel.dimension / 2;
                        int y = image_height + kernel_height - kernel.dimension / 2;
                        if (x >= 0 && x < image.width && y >= 0 && y < image.height) {
                            sum += image.rgb_image[(y * image.width * image.channels) + (x * image.channels) + channels] * kernel.data[kernel_width][kernel_height];
                        }
                    }
                }
                sum /= kernel.normalizing_constant;
                convolved.rgb_image[(image_height * convolved.width * convolved.channels) + (image_width * convolved.channels) + channels] = static_cast<uint8_t>(sum);
            }
        }
    }

    return convolved;
}




