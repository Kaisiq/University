#include <iostream>
using namespace std;


typedef unsigned char pixel[3];



int** setFieldToZero(const pixel *const *const image, int**  resultImage, size_t width, size_t height, size_t row, size_t column, unsigned int numberToCheck)
{
    unsigned int intensity = ((int)image[0][row+column*width][0] + (int)image[0][row+column*width][1] + (int)image[0][row+column*width][2]) / 3;

    if(intensity >= numberToCheck-1  && intensity <= numberToCheck+1){

        resultImage[0][row+column*width] = 0;

        if(row>0){
            if(resultImage[0][row-1+(column*width)] != 0){
                setFieldToZero(image, resultImage, width, height, row-1, column, intensity);
            }
        }
        if(row<width){
            if(resultImage[0][row+1+(column*width)] != 0){
                setFieldToZero(image, resultImage, width, height, (row+1), column, intensity);
            }
        }
        if(column>0){
            if(resultImage[0][row+((column-1)*width)] != 0){
                setFieldToZero(image, resultImage, width, height, row, column-1, intensity);
            }
        }
        if(column<height){
            if(resultImage[0][row+((column+1)*width)] != 0){
                setFieldToZero(image, resultImage, width, height, row, (column+1), intensity);
            }
        }
    }
    return resultImage;
}

void printIntArea(const int *const *const image, size_t width, size_t height)
{
    int k=0;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){

            if(image[0][k] < 10){
                cout << " " << image[0][k] << " ";   
            }
            else{
                cout << image[0][k] << " ";
            }
            k++;

        }
        cout << endl;
    }
    
    return;
}

int* createResultArea(const pixel *const *const image, size_t width, size_t height)
{
    int* resultImage = new(nothrow) int[width * height];
    if(!resultImage){
        return nullptr;
    }
    int j=0;
    for(int i=0; i < width*height; i++){
        int firstnum = (int)image[0][i][0];
        int secondnum = (int)image[0][i][1];
        int thirdnum = (int)image[0][i][2];
        resultImage[j] = (firstnum + secondnum + thirdnum) / 3;
        j++;
    }

    return resultImage;
}



pixel** fillArea (const pixel *const *const image, size_t width, size_t height, size_t row, size_t column)
{
    int* resultImage = createResultArea(image, width, height); //Creating result area and copying values from image

    printIntArea(&resultImage,width,height);  //print before changes
    cout << endl;
    
    unsigned int intensityOfChosenNumber = ((int)image[0][row+column*width][0] + (int)image[0][row+column*width][1] + (int)image[0][row+column*width][2]) / 3;
    setFieldToZero(image, &resultImage, width, height, row, column, intensityOfChosenNumber);

    printIntArea(&resultImage,width,height); //print after changes
    cout << endl;


    return 0;
}



int main(){

    unsigned int height, width;
    cin >> height >> width;

    pixel* image = new(nothrow) pixel[height * width];
    int a;
    for(int i=0; i<height * width; i++){
        for(int j=0; j<3; j++){
            cout << "Enter value " << j+1 << " for pixel " << i << ": "; // R,G,B values for every pixel of the Matrix
            cin >> a;                   //Entering a number as (int) and converting to (char)
            image[i][j] = (char)a;      //so the user can enter two-digit-numbers such as 20
        }
    }

    unsigned int row, column;
    cout << "Enter Coordianates: "; 
    cin >> row >> column;
    cout << endl;

    fillArea(&image, width, height, row, column);

    delete[] image;
    return 0;
}