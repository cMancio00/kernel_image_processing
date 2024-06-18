#include <iostream>
#include <format>
#include "Image.h"

using namespace std;
const char *INPUT_PATH = "../images/input/4K.jpg";
const char *OUTPUT_PATH = "../images/output/4K.jpg";

int main() {
    Image image;
    cout << "Reading an Image..." << endl;
    Image::loadImage(INPUT_PATH,image);

    cout << "Saving image..." << endl;
    Image::saveImage(OUTPUT_PATH, image);



    return EXIT_SUCCESS;
}
