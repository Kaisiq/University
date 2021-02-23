#include <iostream>
using namespace std;


typedef unsigned char pixel[3];



int** setFieldToZero(const pixel *const *const image, int**  resultImage, const size_t width, const size_t height, const size_t row, const size_t column, const unsigned int numberToCheck)
{
    unsigned int intensity = ((int)image[column][row][0] + (int)image[column][row][1] + (int)image[column][row][2]) / 3;

    if(intensity >= numberToCheck-1  && intensity <= numberToCheck+1){

        resultImage[column][row] = 0;

        if(row>0){
            if(resultImage[column][row-1] != 0){
                setFieldToZero(image, resultImage, width, height, row-1, column, intensity);
            }
        }
        if(row<width){
            if(resultImage[column][row+1] != 0){
                setFieldToZero(image, resultImage, width, height, (row+1), column, intensity);
            }
        }
        if(column>0){
            if(resultImage[column-1][row] != 0){
                setFieldToZero(image, resultImage, width, height, row, column-1, intensity);
            }
        }
        if(column<height){
            if(resultImage[column+1][row] != 0){
                setFieldToZero(image, resultImage, width, height, row, (column+1), intensity);
            }
        }
    }
    return resultImage;
}


int** createResultIntArea(const pixel *const *const image, const size_t width, const size_t height)
{
    int** resultImage = new(nothrow) int*[height];
    if(!resultImage){
        return nullptr;
    }
    for(int i=0; i<width; i++){
        resultImage[i] = new(nothrow) int[width];
        if(!resultImage[i]){
            return nullptr;
        }
    }
    int k=0;
    for(int i=0; i < height; i++){
        for(int j=0; j<width; j++){
            int firstnum = (int)image[i][j][0];
            int secondnum = (int)image[i][j][1];
            int thirdnum = (int)image[i][j][2];
            resultImage[i][j] = (firstnum + secondnum + thirdnum) / 3;
            k++;
        }
    }

    return resultImage;
}



void printCharArea(const pixel *const *const image, const size_t width, const size_t height)
{
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){

            if((int)image[i][j][0] < 10){
                cout << " " << (int)image[i][j][0] << " ";   
            }
            else{
                cout << (int)image[i][j][0] << " ";
            }

        }
        cout << endl;
    }
    return;
}


pixel** revertResultImageToChar(const int *const *const resultImage, const size_t width, const size_t height)
{
    pixel** resultCharImage = new(nothrow) pixel*[height];
    if(!resultCharImage){
        return nullptr;
    }
    for(int i=0; i<width; i++){
        resultCharImage[i] = new(nothrow) pixel[width];
    }
    for(int i=0; i < height; i++){
        for(int j=0; j<width; j++){
            int number = (int)resultImage[i][j];
            resultCharImage[i][j][0] = (number);
            resultCharImage[i][j][1] = (number);
            resultCharImage[i][j][2] = (number);
        }
    }
    return resultCharImage;
}




pixel** fillArea (const pixel *const *const image, size_t width, size_t height, size_t row, size_t column)
{
    int** resultImage = createResultIntArea(image, width, height); //Creating result area and copying values from image

    cout << endl;
    
    unsigned int intensityOfChosenNumber = ((int)image[0][row+column*width][0] + (int)image[0][row+column*width][1] + (int)image[0][row+column*width][2]) / 3;
    setFieldToZero(image, resultImage, width, height, row, column, intensityOfChosenNumber);

    pixel** charResult = revertResultImageToChar(resultImage, width, height);


    cout << endl;
    
    delete[] resultImage;
    return charResult;
}



int main(){

    unsigned int height, width;
    cin >> height >> width;

    pixel** image = new(nothrow) pixel*[height];
    for(int i=0; i<height; i++){
        image[i] = new(nothrow) pixel[width];
    }
    unsigned int a;
    for(int i=0; i<height; i++){
        for(int k=0; k<width; k++){
            for(int j=0; j<3; j++){
                cout << "Enter value " << j+1 << " for pixel " << i*width+k+1 << ": "; // R,G,B values for every pixel of the Matrix
                cin >> a;                       //Entering a number as (unsigned int) and converting to (char)
                image[i][k][j] = (char)a;       //so the user can enter two-digit-numbers such as 20
            }
        }
    }

    unsigned int row, column;
    cout << endl;
    cout << "Enter Coordianates: \n"; 
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> column;
    cout << endl;

    printCharArea(image,width,height);
    pixel** resultImage = fillArea(image, width, height, row, column);
    printCharArea(resultImage,width,height);

    delete[] resultImage;
    delete[] image;
    return 0;
}