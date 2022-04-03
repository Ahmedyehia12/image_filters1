#include <iostream>
#include<fstream>
#include<cmath>
#include <cstring>
#include <string>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
void BW();
void flip();
void blurImage();
void saveImage();
void LD();
void merge();
void invert();
void rotate();
bool check = true;

int main() {
    cout << "Ahlan ya user ya habibi\n";
    cout << "welcome to image filtering program!\n\n";
    while (check) {
        loadImage();
        cout << "\nWhat do you want to do now?\n  1-Black and White\n  2-Blur\n  3-Flip\n  4-Darken and lighten\n  5-Merge\n  6-Invert\n  7-Rotate\n  0-end\n";
        cout << "Enter the number of the filter needed--->";
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                BW();
                break;
            case 2:
                blurImage();
                break;
            case 3:
                flip();
                break;
            case 4:
                LD();
                break;
            case 5:
                merge();
                break;
            case 6:
                invert();
                break;
            case 7:
                rotate();
                break;
            case 0:
                cout << "Thank you!";
                check = false;
                break;
        }
        cin.ignore();
        saveImage();
        cout << "DONE\n\nTo Quit ---> Enter Q\nTo Continue ---> Enter 1\n---> ";
        string c;
        getline(cin,c);
        if (c =="Q") break;
        else if (c =="1") continue;
    }
    return 0;
}

void loadImage(){
    string imageFileName;
    cout << "Enter the source image file name without extension: ";
    getline(cin,imageFileName);
    imageFileName += ".bmp";
    char* ptr= &imageFileName[0];
    int n=readGSBMP(ptr,image);
    if (n==1) loadImage();
    else readGSBMP(ptr,image);
}

void saveImage(){
    string imageFileName;
    cout << "Enter the target image file name without extension: ";
    getline(cin,imageFileName);
    imageFileName += ".bmp";
    char* ptr= &imageFileName[0];
    writeGSBMP(ptr,image);
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

    for(int i = 0;i<SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = (image[i - 1][j - 1] + image[i][j - 1] + image[i + 1][j - 1] + image[i - 1][j] + image[i][j] +
                           image[i + 1][j] + image[i - 1][j + 1] + image[i][j + 1] + image[i + 1][j + 1]) / 9;
        }
    }
}
void LD(){char choice; long avg=0;
    cout << "(d)arken or (l)ighten:";
    cin >> choice;
    if(choice == 'd'){
        long avg =0;
        for(int i = 0; i< SIZE;i++){
            for(int j = 0; j < SIZE;j++){
                avg += image[i][j];
            }
        }
        avg/=( SIZE*SIZE);

    for(int i = 0; i< SIZE;i++){
        for(int j = 0; j < SIZE;j++){
           if(image[i][j]>avg) {image[i][j] = image[i][j]-avg;}
            else{image[i][j] = 0;}

        }

        }
    }
    else if(choice == 'l'){
        long avg =0;
        for(int i = 0; i< SIZE;i++){
            for(int j = 0; j < SIZE;j++){
                avg += image[i][j];
            }
        }
        avg/=( SIZE*SIZE);
        for(int i = 0; i< SIZE;i++) {
            for (int j = 0; j < SIZE; j++) {
              if(image[i][j]<avg) {image[i][j]+=avg;}
              else{image[i][j] = 255;}



            }
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