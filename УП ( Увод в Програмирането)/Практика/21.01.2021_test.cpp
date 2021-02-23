#include <iostream>
using namespace std;



typedef int(*fptr)(int);



int nextElem(int n) {
    return n * 2 + 1;
}


int* generateSequence(unsigned n, unsigned first, fptr nextElem, int* arr = nullptr, int i=0){
    if(i==n){
        return arr;
    }
    if(!arr){
        arr = new(nothrow) int[n];
        if(!arr){
            return nullptr;
        }
    }
    arr[i] = first;
    return generateSequence(n, nextElem(first), nextElem, arr, i+1);
}



int main(){
    unsigned int n, first;
    cin >> n >> first;
    int* arr = generateSequence(n, first, nextElem);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}