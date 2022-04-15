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
unsigned char image[SIZE][SIZE];

void loadImage();
void BW();
void flip();
void blurImage();
void saveImage();
void merge();
void invert();
void rotate();
void Dark_light();

bool check = true;

int main() {
    cout << "Ahlan ya user ya habibi\n";
    cout << "welcome to image filtering program!\n";
    while (check) {
        cout << "1-Black and White\n" << "2-Blur\n" << "3-flip\n" << "4-invert\n" << "5-merge\n"<<"6-Rotate\n"<<"7-Darken and lighten\n"<<"8-end\n";
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
    int Temp;

    for (int i=0 ; i<SIZE ; i+=2){
        for (int j=0 ; j<SIZE ; j+=2){
            Temp =((image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j+2]+image[i+2][j]+image[i+2][i+2]+image[i+1][j+2]+image[i+2][j+1])/9);
            image[i][j]=Temp;
            image[i+1][j]=Temp;
            image[i][j+1]=Temp;
            image[i+1][j+1]=Temp;
            image[i][j+2]=Temp;
            image[i+2][j]=Temp;
            image[i+2][i+2]=Temp;
            image[i+1][j+2]=Temp;
            image[i+2][j+1]=Temp;

        }
    }


}

void merge(){
    unsigned char image1[SIZE][SIZE];
    char imageFileName1[100];
    cout << "Enter the source image file name to merge :";
    cin >> imageFileName1;
    strcat(imageFileName1,".bmp");
    readGSBMP(imageFileName1,image1);
    for(int i =0;i<SIZE;i++){
        for(int j =0;j<SIZE;j++){
            image[i][j]=(image[i][j]+image1[i][j])/2;
        }
    }

}

void invert()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}
void rotate()
{
    unsigned char image1[SIZE][SIZE]={0};
    cout << "\n1) 90 degrees\n2) 180 degrees\n3) 270 degrees\nEnter a number---> ";
    string s;
    cin >> s;
    if(s=="1")
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                image1[j][SIZE-i-1]=image[i][j];
            }
        }
        for(int i=0;i<SIZE;i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=image1[i][j];
            }
        }
    }
    else if(s=="2")
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                image1[SIZE-i-1][SIZE-j-1]=image[i][j];
            }
        }
        for(int i=0;i<SIZE;i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=image1[i][j];
            }
        }
    }
    else if (s=="3")
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                image1[SIZE-j-1][i]=image[i][j];
            }
        }
        for(int i=0;i<SIZE;i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j]=image1[i][j];
            }
        }
    }
    else
    {
        cout << "Error,enter a valid number\n";
        rotate();
    }
}
void Dark_light(){
    char choice;
    cout << "(d)arken or (l)ighten:";
    cin >> choice;
    while(choice != 'd' && choice != 'l'){
        cout << "Invalid input\n";
        cout << "choose again:";
        cin >> choice;
    }

    switch(choice){
        case 'd':
            for(int i =0;i<SIZE;i++){
                for(int j =0;j<SIZE;j++){
                    image[i][j] = (image[i][j])/2; //0 is black and 255 is white therefore we are darkening every pixel by 50%
                }
            }
            break;
        case 'l':
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    if(image[i][j]<255/2){
                        image[i][j] += 75;

                    }
                }
            }
            break;
    }
}
