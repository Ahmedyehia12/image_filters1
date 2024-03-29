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

void BW() {
    long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
                avg =(image[i][j][0]+image[i][j][1]+image[i][j][2])/3;
                if (avg > 127) {
                    image[i][j][0] = 255;
                    image[i][j][1]=255;
                    image[i][j][2]=255;
                } else {
                    image[i][j][0] = 0;
                    image[i][j][1]=0;
                    image[i][j][2]=0;
                }
            }
        }
    }

void flip()
{
    string op;
    cout << "Flip (h)orizontally or (v)ertically ?\n";
    cin.ignore();
    cin >> op;
    if (op == "v") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k=0; k < RGB; k++) {
                    int temp = image[i][j][k];
                    image[i][j][k] = image[i][SIZE - j][k];
                    image[i][SIZE - j][k] = temp;
                }
            }
        }
    } else if (op == "h") {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k=0; k < RGB; k++) {
                int temp = image[i][j][k];
                image[i][j][k] = image[SIZE - i][j][k];
                image[SIZE - i][j][k] = temp;
              }
           }
        }
    } else {
        cout << "not an option";
    }
}

void blurImage()
{   for(int i=0;i<SIZE;i++){
      for(int j=0;j<SIZE;j++){
        for(int k=0;k<SIZE;k++){ //creating a 5x5 matrix and calculating the average in each pixel
            image[i][j][k]=(image[i-2][j-2][k]+image[i-2][j-1][k]+image[i-2][j][k]+image[i-2][j+1][k]+image[i-2][j+2][k]+image[i-1][j-2][k]+image[i-1][j-1][k]+image[i-1][j][k]+image[i-1][j+1][k]+image[i-1][j+2][k]+image[i][j-2][k]+image[i][j-1][k]+image[i][j][k]+image[i][j+1][k]+image[i][j+2][k]+image[i+1][j-2][k]+image[i+1][j-1][k]+image[i+1][j][k]+image[i+1][j+1][k]+image[i+1][j+2][k]+image[i+2][j-2][k]+image[i+2][j-1][k]+image[i+2][j][k]+image[i+2][j+1][k]+image[i+2][j+2][k])/25;

        }
    }
}

}

void merge()
{  unsigned char image1[SIZE][SIZE][RGB];
    char imageFileName1[100];
    cout << "Enter the source image file name to merge :";
    cin >> imageFileName1;
    strcat(imageFileName1,".bmp");
    readRGBBMP(imageFileName1,image1);
    for(int i =0;i<SIZE;i++){
        for(int j =0;j<SIZE;j++){
            for(int k =0;k<RGB;k++){
                image[i][j][k]=(image[i][j][k]+image1[i][j][k])/2;
            }
        }
    }

}

void invert()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            for(int k=0;k<3;k++)
            {
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}
void rotate()
{
    unsigned char image1[SIZE][SIZE][RGB]={0};
    cout << "\n1) 90 degrees\n2) 180 degrees\n3) 270 degrees\nEnter a number---> ";
    string s;
    cin >> s;
    if(s=="1")
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                for(int k=0;k<3;k++)
                {
                    image1[j][SIZE - i - 1][k] = image[i][j][k];
                }
            }
        }
        for(int i=0;i<SIZE;i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for(int k=0;k<3;k++)
                {
                    image[i][j][k] = image1[i][j][k];
                }
            }
        }
    }
    else if(s=="2")
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                for(int k=0;k<3;k++)
                {
                    image1[SIZE - i - 1][SIZE - j - 1][k] = image[i][j][k];
                }
            }
        }
        for(int i=0;i<SIZE;i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for(int k=0;k<3;k++)
                {
                    image[i][j][k] = image1[i][j][k];
                }
            }
        }
    }
    else if (s=="3")
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                for(int k=0;k<3;k++)
                {
                    image1[SIZE - j - 1][i][k] = image[i][j][k];
                }
            }
        }
        for(int i=0;i<SIZE;i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for(int k=0;k<3;k++)
                {
                    image[i][j][k] = image1[i][j][k];
                }
            }
        }
    }
    else
    {
        cout << "Error,enter a valid number\n";
        rotate();
    }
}
void Dark_light()
{    char choice;
    cout << "(d)arken or (l)ighten:";
    cin >> choice;
    while (choice != 'd' && choice != 'l') {
        cout << "Invalid input\n";
        cout << "choose again:";
        cin >> choice;}
    switch (choice) {
        case 'd':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for(int k=0;k<RGB;k++){
                    image[i][j][k] = (image[i][j][k]+0) /2;} //0 is black and 255 is white therefore we are darkening every pixel by 50%
                }
            }
            break;
        case 'l':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for(int k =0;k<RGB;k++){
                    image[i][j][k] = (image[i][j][k] + 255) / 2;}
                }
            }
            break;
    }

}
void shrink(){
    string choose;
    cout << "shrink image to 1/2 or 1/3 or 1/4 :";
    cin >> choose;
    while(choose != "1/2"&&choose!="1/3"&&choose!= "1/4"){
        cout << "invalid input ..please try again:";
        cin >> choose;
    }if(choose == "1/2"){

        for(int i=0,count=0;i<SIZE;i++,count+=2){
            for(int j =0,count1=0;j<SIZE;j++,count1+=2){
                for(int k=0;k<RGB;k++){
                    if(i<SIZE/2 && j<SIZE/2){
                        image[i][j][k]=image[count][count1][k];
                    }
                    else{image[i][j][k]=255;}
                }
            }
        }}
    else if(choose == "1/3"){for(int i=0,count=0;i<SIZE;i++,count+=3){
            for(int j =0,count1=0;j<SIZE;j++,count1+=3){
                for(int k=0;k<RGB;k++){
                    if(i<SIZE/3 && j<SIZE/3){
                        image[i][j][k]=image[count][count1][k];
                    }
                    else{image[i][j][k]=255;}
                }
            }
        }

    }
    else if(choose == "1/4"){
        for(int i=0,count=0;i<SIZE;i++,count+=4){
            for(int j =0,count1=0;j<SIZE;j++,count1+=4){
                for(int k=0;k<RGB;k++){
                    if(i<SIZE/4 && j<SIZE/4){
                        image[i][j][k]=image[count][count1][k];
                    }
                    else{image[i][j][k]=255;}
                }
            }
        }
    }


}

void enlarge()
{
    cout << "\n1) first quarter\n2) second quarter\n3) third quarter\n4) forth quarter\nChoose a number--->";
    string s;
    cin >> s;
    if(s=="1")
    {
        unsigned char image1[SIZE/2][SIZE/2][RGB]={0};
        for(int i =0;i<SIZE/2;i++)
        {
            for(int j=0;j<SIZE/2;j++)
            {
                for(int k=0;k<3;k++) {
                    image1[i][j][k] = image[i][j][k];
                }
            }
        }
        int r=0;
        for(int i=0;i<SIZE/2;i++)
        {
            int c=0;
            for (int j = 0; j < SIZE/2; j++)
            {
                for(int k=0;k<3;k++) {
                    image[r][c][k] = image1[i][j][k];
                    image[r + 1][c][k] = image1[i][j][k];
                    image[r][c + 1][k] = image1[i][j][k];
                    image[r + 1][c + 1][k] = image1[i][j][k];
                }
                c += 2;
            }
            r+=2;
        }
    }
    else if(s=="4")
    {
        unsigned char image1[SIZE/2][SIZE/2][RGB]={0};
        int s=0;
        for(int i =128;i<SIZE;i++)
        {
            int t=0;
            for(int j=128;j<SIZE;j++)
            {
                for(int k=0;k<3;k++) {
                    image1[s][t][k] = image[i][j][k];
                }
                t++;
            }
            s++;
        }
        int r=0;
        for(int i=0;i<SIZE/2;i++)
        {
            int c = 0;
            for (int j = 0; j < SIZE/2; j++) {
                for(int k=0;k<3;k++) {
                    image[r][c][k] = image1[i][j][k];
                    image[r + 1][c][k] = image1[i][j][k];
                    image[r][c + 1][k] = image1[i][j][k];
                    image[r + 1][c + 1][k] = image1[i][j][k];
                }
                c += 2;
            }
            r += 2;
        }
    }
    else if(s=="3")
    {
        unsigned char image1[SIZE/2][SIZE/2][RGB]={0};
        int s=0;
        for(int i =128;i<SIZE;i++)
        {
            int t=0;
            for(int j=0;j<SIZE/2;j++)
            {
                for(int k=0;k<3;k++) {
                    image1[s][t][k] = image[i][j][k];
                }
                t++;
            }
            s++;
        }
        int r=0;
        for(int i=0;i<SIZE/2;i++)
        {
            int c = 0;
            for (int j = 0; j < SIZE/2; j++) {
                for(int k=0;k<3;k++) {
                    image[r][c][k] = image1[i][j][k];
                    image[r + 1][c][k] = image1[i][j][k];
                    image[r][c + 1][k] = image1[i][j][k];
                    image[r + 1][c + 1][k] = image1[i][j][k];
                }
                c += 2;
            }
            r += 2;
        }
    }
    else if(s=="2")
    {
        unsigned char image1[SIZE/2][SIZE/2][RGB]={0};
        int s=0;
        for(int i =0;i<SIZE/2;i++)
        {
            int t=0;
            for(int j=128;j<SIZE;j++)
            {
                for(int k=0;k<3;k++) {
                    image1[s][t][k] = image[i][j][k];
                }
                t++;
            }
            s++;
        }
        int r=0;
        for(int i=0;i<SIZE/2;i++)
        {
            int c = 0;
            for (int j = 0; j < SIZE/2; j++) {
                for(int k=0;k<3;k++) {
                    image[r][c][k] = image1[i][j][k];
                    image[r + 1][c][k] = image1[i][j][k];
                    image[r][c + 1][k] = image1[i][j][k];
                    image[r + 1][c + 1][k] = image1[i][j][k];
                }
                c += 2;
            }
            r += 2;
        }
    }
    else
    {
        cout << "enter a valid number";
        enlarge();
    }
}
void edge_detection()
{

    unsigned char tempimage[SIZE][SIZE][RGB];
    long x,y,d;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            int up_left =(image[i-1][j-1][0]+image[i-1][j-1][1]+image[i-1][j-1][2])/3;
            int up = (image[i-1][j][0]+image[i-1][j][1]+image[i-1][j][2])/3;
            int up_right= (image[i-1][j+1][0]+image[i-1][j+1][1]+image[i-1][j+1][2])/3;
            int down_left =(image[i+1][j-1][0]+image[i+1][j-1][1]+image[i+1][j-1][2])/3;
            int down =(image[i+1][j][0]+image[i+1][j][1]+image[i+1][j][2])/3;
            int down_right= (image[i+1][j+1][0]+image[i+1][j+1][1]+image[i+1][j+1][2])/3;
            int mid_left = (image[i][j-1][0]+image[i][j-1][1]+image[i][j-1][2])/3;
            int mid_right =(image[i][j-1][0]+image[i][j-1][1]+image[i][j-1][2])/3;

            y=up_left+up+up_right-down_left-down-down_right;

            x=up_left+mid_left+down_left-up_right-mid_right-down_right;
            d=sqrt(x*x+y*y);
            if (d>90){
                tempimage[i][j][0] = 0;
                tempimage[i][j][1] = 0;
                tempimage[i][j][2] = 0;
            }
            else {
                tempimage[i][j][0] = 255;
                tempimage[i][j][1] = 255;
                tempimage[i][j][2] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int k = 0 ; k< RGB; k++) {
                image[i][j][k] = tempimage[i][j][k];
            }
        }
    }
}


void mirror()
{
    string op;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?\n";
    cin.ignore();
    cin >> op;
    if (op == "l") {
        for (int i = 0; i < SIZE ; i++) {
            for (int j = SIZE/2; j < SIZE ; j++) {
                for(int k=0; k < RGB; k++) {
                    image[i][j][k] = image[i][SIZE - j][k];
                }

            }
        }
    }
    if (op == "r") {
        for (int i = 0; i < SIZE ; i++) {
            for (int j = 0; j < SIZE/2 ; j++) {
                for(int k=0; k < RGB; k++) {
                    image[i][j][k] = image[i][SIZE - j][k];
                }

            }
        }
    }
    if (op == "u") {
        for (int i = SIZE/2; i < SIZE ; i++) {
            for (int j = 0; j < SIZE; j++) {
                for(int k=0; k < RGB; k++) {
                    image[i][j][k] = image[SIZE - i][j][k];
                }
            }
        }
    }
    if (op == "d") {
        for (int i = 0; i < SIZE/2 ; i++) {
            for (int j = 0; j < SIZE ; j++) {
                for(int k=0; k < RGB; k++) {
                    image[i][j][k] = image[SIZE - i][j][k];
                }
            }
        }
    }
}

void shuffle()
{
    unsigned char image1[256][256][3]={0};
    int a=0,b=0,c=0,d=0,x=0,y=0,z,r;
    int arr[4];
    cout << "Enter the order of the quarters : ";
    for (int i=0;i<4;i++)
    {
        cin >> arr[i];
        if(arr[i]==1)
        {
            a=0;
            b=128;
            c=0;
            d=128;
        }
        else if(arr[i]==2)
        {
            a=0;
            b=128;
            c=128;
            d=256;
        }
        else if(arr[i]==3)
        {
            a=128;
            b=256;
            c=0;
            d=128;
        }
        else if(arr[i]==4)
        {
            a=128;
            b=256;
            c=128;
            d=256;
        }
        if(i==0)
        {
            x=0;
            z=0;
            y=0;
            r=0;
        }
        else if(i==1)
        {
            x=0;
            z=0;
            y=128;
            r=128;
        }
        else if(i==2)
        {
            x=128;
            y=0;
            z=128;
            r=0;
        }
        else if(i==3)
        {
            x=128;
            y=128;
            z=128;
            r=128;
        }
        x=z;
        for(int j=a;j<b;j++)
        {
            y=r;
            for(int k=c;k<d;k++)
            {
                for(int l=0;l<3;l++) {
                    image1[x][y][l] = image[j][k][l];
                }
                y++;
            }
            x++;
        }
    }
    char imageFileName[100];
    cout << "Enter the target image file name:";
    cin >> imageFileName;
    strcat(imageFileName,".bmp");
    writeRGBBMP(imageFileName,image1);
}
