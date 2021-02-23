#include <iostream>
using namespace std;




void swapArrays (int* &arr1, int* &arr2){
    int* temp = arr2;
    arr2 = arr1;
    arr1 = temp;
}




bool removeAt(int* &arr, int index, unsigned int& size){
    int* arr2 = new(nothrow) int[size-1];
    if(!arr2){
        return 0;
    }
    for(int i=0;i<index;i++){
        arr2[i] = arr[i];
    }
    size--;
    for(int i=index;i<size;i++){
        arr2[i] = arr[i+1];
    }
    swapArrays(arr,arr2);

    delete[] arr2;
    return 1;
}




void filter (int* &pArr, unsigned int& size, unsigned int biggestNumber){
    int* arr2 = new(nothrow) int[size-1];
    if(!arr2){
        cout << "error";
        return;
    }
    for (int i=0; i<size; i++){
        if(pArr[i] > biggestNumber){

            if (!(removeAt(pArr,i,size))){
                cout << "error";
                return;
            }
            if(size<=0){ 
                break;
            }
            i--;
        }
    }


}



int main(){
    unsigned int size = 30;
    int* pArr = new(nothrow) int[size];
    if(!pArr){
        return 1;
    }
    int max = 13;
    for(int i=0; i<size; i++){
        *(pArr+i) = i;
    }
    for(int i=0; i<size; i++){
        cout << pArr[i] << " ";
    }
    cout << endl << endl;
    filter(pArr,size,max);
    for(int i=0; i<size; i++){
        cout << pArr[i] << " ";
    }

    return 0;
}