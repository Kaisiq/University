//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 2
// 2021-01-17
//
// Начален час: 10:00
// Име: Даниел Даниел Иванов
// ФН: 45792
// Специалност: Информатика
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>
using namespace std;



void print(int* arr, int len, int i=0){
    if(len==0){
        return;
    }
    if(i==len){
        return;
    }
    cout << arr[i] << " ";
    return print(arr,len,i+1);
}


bool isSorted(int* arr, int len, int i=0){
    if(i==len-1){
        return 1;
    }
    if(arr[i+1] >= arr[i]){
        return isSorted(arr,len,i+1);
    }
    else{
        return 0;
    }
}

void insertElementOnIndex(int* arr, int& len, int index, int number, int i){
    if(i == index){
        arr[index] = number;
        return; 
    }
    else{
        arr[i] = arr[i-1];
        insertElementOnIndex(arr, len, index, number, i-1);
    }
}

void insertInSorted(int* arr, int& len, int number, int i=0){
    if(i==len){
        arr[i] = number;
        return;
    }
    if(number<arr[0]){
        insertElementOnIndex(arr, len, 0, number, len+1);
        return;
    }
    if(number>=arr[i] && number<=arr[i+1]){
        insertElementOnIndex(arr,len,i+1,number,len+1);
        return;
    }
    insertInSorted(arr, len, number, i+1);
}


int main(){
    unsigned int N;

    do{
        cin >> N;
    }
    while(N>=1000);

    int arr[1000] = {0,};

    int a;
    int i;

    for(i=0; i<N; i++){
        cin >> a;
        insertInSorted(arr,i,a);
    }

    cout << isSorted(arr, i) << endl;
    
    print(arr,i);

    return 0;
}