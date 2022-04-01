#include <iostream>
#include "bmplib.cpp"
#include<fstream>
#include<cmath>
#include <cstring>
using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
//void BW();
void flip();
//void blurImage();
void saveImage();


int main() {
    loadImage();
    //BW();
    flip();
    //blurImage();
    saveImage();

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
//void blurImag(){
//
//}
//
//void BW(){
//    long avg =0;
//    for(int i = 0; i< SIZE;i++){
//        for(int j = 0; j < SIZE;j++){
//            avg += image[i][j];
//        }
//    }
//    avg/=( SIZE*SIZE);
//    for(int i = 0; i< SIZE;i++) {
//        for (int j = 0; j < SIZE; j++) {
//            if (image[i][j] > avg){
//                        image[i][j] = 255;
//                }
//            else {
//                image[i][j] = 0;
//            }
//        }
//    }
//}
void flip(){
    string op;
    cout << "Flip (h)orizontally or (v)ertically ?\n";
    cin >> op;
    if (op=="h"){
        for(int i = 0; i< SIZE;i++) {
            for (int j = 0; j < SIZE/2; j++) {
                int temp = image[i][j];
                image[i][j]=image[i][SIZE-j];
                image[i][SIZE-j] = temp;
            }
        }
    }else if(op== "v") {
        for(int i = 0; i< SIZE/2;i++) {
            for (int j = 0; j < SIZE; j++) {
                int temp = image[i][j];
                image[i][j]=image[SIZE-i][j];
                image[SIZE-i][j] = temp;
            }
        }
    }else{
        cout << "not an option";
    }


}