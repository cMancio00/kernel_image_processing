#include <iostream>
#include <format>
#include "Image.h"

using namespace std;
const char *IMAGE_PATH = "../images/input/4K.jpg";

int main() {
    Image image;
    cout << "Reading an Image..." << endl;
    Image::loadImage(IMAGE_PATH,image);
    if(!image.rgb_image){
        cerr << "LOAD FAILED!" << endl;
    }else{
        cout << format("Loaded image {}x{}",image.width,image.height) << endl;
    }

    return EXIT_SUCCESS;
}
