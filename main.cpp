#include <iostream>
#include<fstream>
#include<cmath>
#include <cstring>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
void BW();
void flip();
void blurImage();
void saveImage();
void LD();


int main() {
    cout << "Ahlan ya user ya habibi\n";
    cout << "welcome to image filtering program!\n";
    cout << "1-Black and White\n"<<"2-Blur\n"<<"3-flip\n"<<"4-darken and lighten\n";
    cout << "choose:";
    int choose;
    cin >> choose;
    switch(choose){
        case 1: loadImage();
        BW();
        saveImage();
        break;
        case 2: loadImage();
        blurImage();
        saveImage();
            break;

        case 3:loadImage();
        flip();
        saveImage();
            break;

        case 4:
            loadImage();
            LD();
            saveImage();
            break;


    }






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


void BW(){
    long avg =0;
    for(int i = 0; i< SIZE;i++){
        for(int j = 0; j < SIZE;j++){
            avg += image[i][j];
        }
    }
    avg/=( SIZE*SIZE);
    for(int i = 0; i< SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > avg){
                        image[i][j] = 255;
                }
            else {
                image[i][j] = 0;
            }
        }
    }
}
void flip() {
    string op;
    cout << "Flip (h)orizontally or (v)ertically ?\n";
    cin.ignore();
    cin >> op;
    if (op == "h") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                int temp = image[i][j];
                image[i][j] = image[i][SIZE - j];
                image[i][SIZE - j] = temp;
            }
        }
    } else if (op == "v") {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                int temp = image[i][j];
                image[i][j] = image[SIZE - i][j];
                image[SIZE - i][j] = temp;
            }
        }
    } else {
        cout << "not an option";
    }
}
void blurImage(){

    for(int i = 0;i<SIZE;i++){
        for(int j = 0;j<SIZE;j++){
            image[i][j]= (image[i-1][j-1]+image[i][j-1]+image[i+1][j-1]+image[i-1][j]+image[i][j]+image[i+1][j]+image[i-1][j+1]+image[i][j+1]+image[i+1][j+1])/9;

        }
    }

}
void LD(){char choice; long avg=0;
    cout << "(d)arken or (l)ighten:";
    cin >> choice;
    if(choice == 'd'){
    for(int i = 0; i< SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            avg += image[i][j];
        }
    }
    avg/=(SIZE*SIZE);
    for(int i = 0; i< SIZE;i++){
        for(int j = 0; j < SIZE;j++){
            if(image[i][j] > avg){image[i][j] = image[i][j]-avg;}
            else{image[i][j] = 0;}

        }

        }
    }
    else if(choice == 'h'){
        for(int i = 0; i< SIZE;i++) {
            for (int j = 0; j < SIZE; j++) {
                avg += image[i][j];
            }
        }
        avg/=(SIZE*SIZE);
        for(int i = 0; i< SIZE;i++) {
            for (int j = 0; j < SIZE; j++) {
                if(image[i][j] > avg){image[i][j] = 255;}
                else{image[i][j] = image[i][j] + avg;}
            }
        }

    }

}
