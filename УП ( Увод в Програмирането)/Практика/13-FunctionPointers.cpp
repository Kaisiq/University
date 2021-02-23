#include <iostream>
using namespace std;





//task 1

// typedef bool(*fptr)(int);
// bool isEven(int n){
//     return !(n%2);
// }

// void filterArr(int* arr, int len, fptr predicate){
//     for(int i=0; i<len; i++){
//         if(predicate(arr[i])){
//             cout << arr[i] << " ";
//         }
//     }
//     return;
// }





//task 2

// typedef int(*fptr)(int);

// int square(int a)
// {
//     return a*a;
// }

// void map(fptr function, int* arr, int len){
//     for(int i=0;i<len;i++){
//         cout << function(arr[i]) << " ";
//     }
// }







//task 3

// typedef int(*fptr)(int,int);

// int sum(int a, int b)
// {
//     return a+b;
// }

// int reduce(fptr function, int acc, int* arr, int len){
//     for(int i=0;i<len;i++){
//         acc = function(acc,arr[i]);
//     }
//     return acc;
// }




//task 4
typedef int(*fptr)(int);

int square(int a)
{
    return a*a;
}

bool checkForRepetitiveNumbers(int a, int b, fptr function){
    for(int i=a;i<b;i++){
        for(int j=a; j<b;j++){
            if(i == function(j)){
                return 1;
            }
        }
    }
    return 0;
}






//task 5
void selectionSort(int* arr, int len){
    int minindex;
    for(int i=0;i<len-1;i++){
        minindex=i;
        for(int j=i+1;j<len;j++){
            if(arr[minindex]>arr[j]){
                minindex = j;
            }
        }
        swapElements(minindex,j);
    }
}







int main(){
    // int array[]={10, 23, 57, 42, 71};
    // filterArr(array, 5, isEven);

    // int arr[] = { 1, 2, 3, 4, 5 };
    // unsigned count = 5;
    // map(square, arr, count);

    // int arr[] = { 1, 2, 3, 4, 5 };
    // unsigned count = 5;
    // int acc = 0;
    // cout << reduce(sum, acc, arr, count);

    int start=12;
    int end=145;
    cout << checkForRepetitiveNumbers(start,end,square);


    return 0;
}