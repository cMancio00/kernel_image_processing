#ifndef KERNEL_IMAGE_PROCESSING_KERNEL_H
#define KERNEL_IMAGE_PROCESSING_KERNEL_H

#include <cstring>

struct Kernel{
    unsigned short dimension{3};
    float normalizing_constant{1.0f};
    short data[3][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    static Kernel Sharpen();
    static Kernel BoxBlur();
    static Kernel GaussianBlur();
    static Kernel Identity();
};


#endif //KERNEL_IMAGE_PROCESSING_KERNEL_H
