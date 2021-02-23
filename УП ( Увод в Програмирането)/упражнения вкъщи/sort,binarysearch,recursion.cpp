#include <iostream>
using namespace std;




void swapByElements(int* arr, int i, int j){
    int c=arr[i];
    arr[i]=arr[j];
    arr[j]=c;
    return;
}

void sortArray(int* arr, int length){
    int minindex;
    for(int i=0;i<length-1;i++){
        int j=i+1;
        minindex=i;
        for(j; j<length; j++){
            if(arr[minindex] > arr[j]){
                minindex = j;
            }
        }
        swapByElements(arr,i,minindex);
    }
}

void removeElementByIndex(int* arr, int index, int& length){
    for(int i=index; i<length-1; i++){
        arr[i] = arr[i+1];
    }
    length--;
}



int binarySearch(int* arr,int& length, int end, int x, int start=0){
    if(start>=end){
        return -1;
    }
    int mid = (start+end-1)/2;
    if(arr[mid] == x){
        removeElementByIndex(arr,mid,length);
        return mid;
    }
    if(arr[mid]>x){
        return binarySearch(arr,length,mid-1,x,0);
    }
    if(arr[mid]<x){
        return binarySearch(arr,length,end,x,mid+1);
    }
}




int main(){
    int array[]={1,1,3432,5,1,2,45,23,5,235,2,4,7,37,4,7,34,32,57,2,7,8,2,47};
    int arrayLength=24;
    sortArray(array,arrayLength);



    for(int i=0;i<arrayLength;i++){
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "removed element at position: " << binarySearch(array,arrayLength,arrayLength,1) << endl;
    for(int i=0;i<arrayLength;i++){
        cout << array[i] << " ";
    }


    return 0;
}