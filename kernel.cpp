#include "kernel.h"

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