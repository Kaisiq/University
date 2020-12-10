#include <iostream>
using namespace std;





//TASK 1

void swap (int &a, int &b){
    int c = a;
    a = b;
    b = c;
}












//TASK 2
int at(int* arr, int i){
    return *(arr+i);
}


// int main(){
//     int* arr = new(nothrow) int[5];
//     *arr=1;
//     *(arr+1) = 2;
//     *(arr+2) = 3;
//     *(arr+3) = 4;
//     *(arr+4) = 5;
//     cout << at(arr, 5) << endl;
//     delete[] arr;
// }







//TASK 3
void swapArrays (int* &arr1, int* &arr2){
    int* temp = arr2;
    arr2 = arr1;
    arr1 = temp;
}


// int main (){
//     int* arr1 = new(nothrow) int[5];
//     if(!arr1){
//         cout << "opa";
//         return 1;
//     }
//     for (int i=0; i<5; i++){
//         arr1[i] = i;
//     }

//     int* arr2 = new(nothrow) int[5];
//     if(!arr2){
//         cout << "opa";
//         return 1;
//     }
//     for (int i=0; i<5; i++){
//         arr2[i] = i+3;
//     }


//     swapArrays(arr1, arr2);

//     for (int i=0; i<5; i++){
//         cout << arr1[i] << " ";
//     }
//     cout << endl;


//     for (int i=0; i<5; i++){
//         cout << arr1[i] << " ";
//     }



//     delete[] arr1;
//     delete[] arr2;
//     return 0;
// }













//TASK 4

bool resize (int* &arr, int size, int newSize){
    int* arr2 = new(nothrow) int[newSize];
    if (!arr2){
        cout << "no memory";
        return 0;
    }
    for (int i=0; i<size; i++){
        arr2[i] = arr[i];
    }
    swapArrays(arr,arr2);
    delete[] arr2;
    return 1;
}


// int main(){
//     int size = 5;
//     int* arr = new(nothrow) int[size];
//     if(!arr){
//         return -1;
//     }
//     arr[0] = 3;
//     arr[1] = 3;
//     arr[2] = 3;
//     arr[3] = 3;
//     arr[4] = 3;
//     if (!resize(arr,size,10)){
//         return 0;
//     }
//     for(int i=5;i<10;i++){
//         arr[i] = 10;
//     }

//     for (int i=0; i<10;i++){
//         cout << arr[i] << " ";
//     }

//     delete[] arr;
//     return 0;
// }















//TASK 5
bool pushBack(int* &arr, int& size, int x){
    int* arr2 = new(nothrow) int[size+1];
    if(!arr2){
        return 0;
    }
    for (int i=0;i<size;i++){
        arr2[i]=arr[i];
    }
    arr2[size]=x;
    swap(arr,arr2);
    delete[] arr2;
    size++;
    return 1;    
}



bool popBack(int* &arr, int& size){
    int* arr2 = new(nothrow) int[size-1];
    if(!arr2){
        return 0;
    }
    for(int i=0;i<size-1;i++){
        arr2[i] = arr[i];
    }
    delete[] arr2;
    size--;
    return 1;
}


// int main(){
//     int size = 10;
//     int* arr = new(nothrow) int[size];
//     if (!arr){
//         cout << "opa";
//         return 1;
//     }
//     for (int i=0; i<size; i++){
//         arr[i] = i;
//     }
//     cout << endl;
//     for (int i=0; i<size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     pushBack(arr,size,123);
//     for (int i=0; i<size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     popBack(arr,size);
//     for (int i=0; i<size; i++){
//         cout << arr[i] << " ";
//     }
//     delete[] arr;
//     return 0;
// }












//TASK 6
bool insertAt(int* &arr, int index, int el, int &size){
    size++;
    int* arr2 = new(nothrow) int[size];
    if(!arr2){
        return 0;
    }
    for (int i=0; i<index; i++){
        arr2[i] = arr[i];
    }

    arr2[index] = el;

    for(int i=index; i<size; i++){
        arr2[i+1] = arr[i];
    }
    swapArrays(arr2,arr);
    delete[] arr2;
    return 1;
}



bool removeAt(int* &arr, int index, int& size){
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


// int main(){
//     int size = 10;
//     int* arr = new(nothrow) int[size];
//     if(!arr){
//         return 1;
//     }
//     for(int i=0;i<size;i++){
//         arr[i] = i;
//     }
//     for(int i=0;i<size;i++){
//         cout << arr[i] << " ";
//     }
//     if (!insertAt(arr,3,123,size)){
//         cout << "greshka";
//         return 1;
//     }
//     cout << endl;
//     for(int i=0;i<size;i++){
//         cout << arr[i] << " ";
//     }
//     if(!removeAt(arr,3,size)){
//         cout << "greshka";
//         return 1;
//     }
//     cout << endl;
//     for(int i=0;i<size;i++){
//         cout << arr[i] << " ";
//     }
//     delete[] arr;
//     return 0;
// }







//TASK 7

bool isPrime(int a){
    for(int i=2;i<a;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

bool filterPrimeNumbers(int* &arr, int& size){
    int count=0;
    for (int i=0;i<size;i++){
        if(isPrime(arr[i])){
            count++;
        }
    }
    int* arr2 = new(nothrow) int[count];
    if(!arr2){
        return 0;
    }
    int j=0;
    for(int i=0; i<size; i++){
        if(isPrime(arr[i])){
            arr2[j] = arr[i];
            j++;
        }
    }

    swapArrays(arr,arr2);
    size = count;
    delete[] arr2;
    return 1;
}


// int main(){
//     int size = 7;
//     int* arr = new(nothrow) int[size];

//     arr[0] = 3;
//     arr[1] = 5;
//     arr[2] = 8;
//     arr[3] = 7;
//     arr[4] = 11;
//     arr[5] = 24;
//     arr[6] = 42;

//     for(int i=0;i<size;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     filterPrimeNumbers(arr,size);

//     for(int i=0;i<size;i++){
//         cout << arr[i] << " ";
//     }

//     delete[] arr;
//     return 0;
// }









//TASK 8