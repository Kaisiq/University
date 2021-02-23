//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Практически изпит - задачи
// 2021-02-01
//
// Име: Даниел Иванов
// ФН:45792
// Специалност:Информатика
// Курс: 1
// Административна група: 4
// Използван компилатор:GCC
//

#include <iostream>
using namespace std;



bool firstSmallerThanSecondOddPositions(int n, int m){
    for(int i=31; i>1; i-=2){
        if(((n&(1<<i))  != 0)   &&  ((m&(1<<i)) == 0)){
            return 0;
        }
        if(((n&(1<<i))  == 0)   &&  ((m&(1<<i)) != 0)){
            return 1;
        }
    }
    return 0;
}


bool firstSmallerThanSecond(int n, int m){
    for(int i=32; i>0; i-=2){
        if(((n&(1<<i))  != 0)   &&  ((m&(1<<i)) == 0)){
            return 0;
        }
        if(((n&(1<<i))  == 0)   &&  ((m&(1<<i)) != 0)){
            return 1;
        }
    }
    return firstSmallerThanSecondOddPositions(n,m);
}


bool onlyZeroesOnEvenPositions(int n){
    for(int i=0; i<32; i+=2){
        if((n & (1<<i)) != 0){
            return 0;
        }
    }
    return 1;
}


int* removeElementByIndex(int* arr, unsigned& len, int indexToRemove){
    int* resultArr = new(nothrow) int[len-1];
    if(!resultArr){
        cout << "No Mem";
        return nullptr;
    }
    for(int i=indexToRemove; i<len-1; i++){
        arr[i] = arr[i+1];
    }
    len--;
    for(int i=0;i<len;i++){
        resultArr[i] = arr[i];
    }
    return resultArr;
}



void swap(int& a, int& b){
    int c = b;
    b = a;
    a = c;
}


void sortArr(int* arr, int len){
    for(int i=0; i<len-1; i++){
        int maxindex = i;
        for(int j=i+1; j<len-1; j++){
            if(firstSmallerThanSecond(arr[i],arr[j])){
                maxindex = j;
            }
        }
        swap(arr[i], arr[maxindex]);
    }
}


void printArr(int* array, int len){
    for(int i=0; i<len; i++){
        cout << array[i] << " ";
    }
}


int main(){
    unsigned n;
    cin >> n;
    int* arr = new(nothrow) int[n];
    if(!arr){
        cout << "No mem";
        return 1;
    }
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    printArr(arr, n);
    cout << endl;
    sortArr(arr, n);
    cout << "After sort:" << endl;
    printArr(arr, n);
    cout << endl;
    cout << "Filtering:" << endl;
    for(int i=0; i<n; i++){
        if(onlyZeroesOnEvenPositions(arr[i])){
            arr = removeElementByIndex(arr,n,i);
            i--;
        }
    }
    printArr(arr, n);



    delete[] arr;

    return 0;
}