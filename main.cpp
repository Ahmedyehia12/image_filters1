#include <iostream>
#include "bmplib.cpp"
#include<fstream>
#include<cmath>
#include <cstring>
using namespace std;
unsigned char image[SIZE][SIZE];
void loadImage();
void blurImage();
void saveImage();


int main() {
    cout << "Ahlan ya user ya habibi\n";
    cout << "Welcome to image filtering program!\n";
    loadImage();
    saveImage();
    blurImage();
    return 0;
}
void loadImage(){
    char imageFileName[100];
    cout << "Enter the source image file name:";
    cin >> imageFileName;
    strcat(imageFileName,".bmp");
    readGSBMP(imageFileName,image);
}
void saveImage(){
    char imageFileName[100];
    cout << "Enter the target image file name:";
    cin >> imageFileName;
    strcat(imageFileName,".bmp");
    writeGSBMP(imageFileName,image);
}
void blurImag(){

}


