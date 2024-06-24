#include <iostream>
#include <format>
#include "Image.h"
#include "kernel.h"
#include "convolution.h"

using namespace std;
const char *INPUT_PATH = "../images/input/4K.jpg";
const char *OUTPUT_PATH = "../images/output/4K.jpg";

int main() {

    Image image;
    cout << "Reading an Image..." << endl;
    Image::loadImage(INPUT_PATH,image);

    Image convolved = convolve(image,Kernel::Sharpen());

    cout << "Saving image..." << endl;
    Image::saveImage(OUTPUT_PATH, convolved);
    cout << "Done"<<endl;



    return EXIT_SUCCESS;
}
