// FCI - Structured programming -2022 - Assignment 3
// Author 1: Ahmed yehia abdel-moaty  ID:20210049   Group:A     S:3,4
// Author 2 :Asmaa ismail Heikal      ID:20210067   Group:A     S:1,2
// Author 3: Shahd abdel moamen       ID:20211053   Group:A     S:1,2
// TA : Nesma , youssra

#include <iostream>
#include<fstream>
#include<cmath>
#include <cstring>
#include "bmplib.cpp"
#include<string>

using namespace std;
unsigned char image[SIZE][SIZE][RGB];

void loadImage();
void BW();
void flip();
void blurImage();
void saveImage();
void merge();
void invert();
void rotate();
void Dark_light();
void shrink();
void enlarge();
void shuffle();
void edge_detection();
void mirror();


bool check = true;

int main() {
    cout << "Ahlan ya user ya habibi\n";
    cout << "welcome to image filtering program!\n";
    while (check) {
        cout << "1-Black and White\n" << "2-Blur\n" << "3-flip\n" << "4-invert\n" << "5-merge\n"<<"6-Rotate\n"<<"7-Darken and lighten\n"<<"8-shrink\n9-enlarge\n10-edge detection\n11-mirror\n12-shuffle\n"<<"0-end\n";
        cout << "choose a filter for the image:";
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                loadImage();
                BW();
                saveImage();
                break;
            case 2:
                loadImage();
                blurImage();
                saveImage();
                break;

            case 3:
                loadImage();
                flip();
                saveImage();
                break;

            case 4:
                loadImage();
                invert();
                saveImage();
                break;
            case 5:
                loadImage();
                merge();
                saveImage();
                break;
            case 6:
                loadImage();
                rotate();
                saveImage();
                break;
            case 7:
                loadImage();
                Dark_light();
                saveImage();
                break;
            case 8:
                loadImage();
                shrink();
                saveImage();
                break;
            case 9:
                loadImage();
                enlarge();
                saveImage();
                break;
            case 10:
                loadImage();
                edge_detection();
                saveImage();
                break;
            case 11:
                loadImage();
                mirror();
                saveImage();
                break;
            case 12:
                loadImage();
                cin.ignore();
                shuffle();
                break;
            case 0:
                cout << "Thank you!";
                check = false;
                break;
        }
    }
}

void loadImage(){
    char imageFileName[100];
    cout << "Enter the source image file name:";
    cin>>imageFileName;
    strcat(imageFileName,".bmp");
    readRGBBMP(imageFileName,image);
}

void saveImage(){
    char imageFileName[100];
    cout << "Enter the target image file name:";
    cin >> imageFileName;
    strcat(imageFileName,".bmp");
    writeRGBBMP(imageFileName,image);
}

void BW()
{

}
void flip()
{

}
void blurImage()
{

}

void merge()
{

}

void invert()
{

}
void rotate()
{

}
void Dark_light()
{

}
void shrink()
{

}

void enlarge()
{

}
void edge_detection()
{

}

void mirror()
{

}

void shuffle()
{

}