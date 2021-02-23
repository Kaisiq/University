#include <iostream>
using namespace std;


typedef bool(*fptr)(int);

bool isEven(int n){
    return n%2==0;
}

bool isOdd(int n){
    return n%2;
}

bool isDevidedBy7(int n){
    return n%7==0;
}

bool isZero(int n){
    return n==0;
}

int* filter(const int arr[], int& size, fptr predicate){
    int* result = new(nothrow) int[size];
    int resultCount = 0;
    for(int i=0; i<size; i++){
        if(predicate(arr[i])){
            result[resultCount] = arr[i];
            resultCount++;
        }
    }

    size = resultCount;
    return result;
}

void printArr(int* arr, int size){
    if(size==0){
        cout << "Array has no elements.";
        return;
    }
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}


// int main(){
//     int arr[]={1,2,3,5,1,3,4,1,3,6,357,45,8,34,7};
//     int n = 15;
//     int* result = filter(arr, n, isEven);
//     printArr(result,n);
// }












//task 2

typedef int(*intfptr)(int);
typedef int(*intfptr2)(int,int);

int doubleN(int n){
    return n*2;
}

int nextNum(int n){
    return n+1;
}

int multiplyByFirst(int n, int first){
    return first*n;
}

int* edit(const int arr[], int& size, intfptr2 function){
    int* result = new(nothrow) int[size];
    for(int i=0; i<size; i++){
        result[i] = function(arr[i], arr[0]);
    }

    return result;
}

int main(){
    int arr[]={4,1,235,2,735,235,3,5,13};
    int size = 9;
    int* result = edit(arr, size, multiplyByFirst);
    printArr(result,size);
}