#include "convolution.h"

Image convolve(const Image &image, const Kernel &kernel) {
    Image convolved;
    convolved.width = image.width - kernel.dimension + 1;
    convolved.height = image.height - kernel.dimension + 1;
    convolved.channels = image.channels;
    convolved.rgb_image = new uint8_t[convolved.width * convolved.height * convolved.channels];

    for(int width = 0; width < convolved.width; ++width){
        for(int height = 0; height < convolved.height; ++height){
            for(int channel = 0; channel < convolved.channels; ++channel){
                float sum = 0.0f;
                for(int kernelWidth = 0; kernelWidth < kernel.dimension; ++kernelWidth){
                    for(int kernelHeight = 0; kernelHeight < kernel.dimension; ++kernelHeight){
                        int pixelWidth = width + kernelWidth - kernel.dimension / 2;
                        int pixelHeight = height + kernelHeight - kernel.dimension / 2;
                        if(pixelWidth >= 0 && pixelWidth < image.width && pixelHeight >= 0 && pixelHeight < image.height){
                            sum += image.rgb_image[(pixelHeight * image.width * image.channels) + (pixelWidth * image.channels) + channel] * kernel.data[kernelWidth][kernelHeight];
                        }
                    }
                }
                sum /= kernel.normalizing_constant;
                convolved.rgb_image[(height * convolved.width * convolved.channels) + (width * convolved.channels) + channel] = static_cast<uint8_t>(sum);
            }
        }
    }

    return convolved;
}
