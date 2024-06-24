#ifndef KERNEL_IMAGE_PROCESSING_KERNEL_H
#define KERNEL_IMAGE_PROCESSING_KERNEL_H

#include <cstring>

struct Kernel{
    unsigned short dimension{3};
    float normalizing_constant{1};
    short data[3][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    static Kernel Sharpen();
    static Kernel BoxBlur();
    static Kernel GaussianBlur();
};

Kernel Kernel::Sharpen() {
    Kernel sharpen;
    short data_init[3][3] = {
            {0, -1, 0},
            {-1, 5, -1},
            {0, -1, 0}
    };
    std::memcpy(sharpen.data, data_init, sizeof(sharpen.data));
    return sharpen;
}

Kernel Kernel::BoxBlur() {
    Kernel blur;
    blur.normalizing_constant = 1.0/9.0;
    short data_init[3][3] = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
    };
    std::memcpy(blur.data, data_init, sizeof(blur.data));
    return blur;
}

Kernel Kernel::GaussianBlur() {
    Kernel blur;
    blur.normalizing_constant = 1.0/16.0;
    short data_init[3][3] = {
            {1, 2, 1},
            {2, 4, 2},
            {1, 2, 1}
    };
    std::memcpy(blur.data, data_init, sizeof(blur.data));
    return blur;
}

#endif //KERNEL_IMAGE_PROCESSING_KERNEL_H
