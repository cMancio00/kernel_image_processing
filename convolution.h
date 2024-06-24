#ifndef KERNEL_IMAGE_PROCESSING_CONVOLUTION_H
#define KERNEL_IMAGE_PROCESSING_CONVOLUTION_H

#include "Image.h"
#include "kernel.h"

Image convolve(const Image &image, const Kernel &kernel);

#endif //KERNEL_IMAGE_PROCESSING_CONVOLUTION_H
