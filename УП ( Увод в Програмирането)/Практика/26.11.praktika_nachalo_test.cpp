#include <iostream>
using namespace std;

const unsigned maxSize = 100;




//TASK 1
// void coutArrayInTheOppositeWay(int arr[],int length){
//     int arr2[maxSize];
//     int n = length-1;
//     for (int i=0;i<length;i++){
//         arr2[n] = arr[i];
//         n--;
//     }
//     for (int i=0;i<length;i++){
//         cout << arr2[i];
//     }
// }

// int main(){
//     int a[maxSize]={1,2,3,4,5,6};
//     int n = 6;
//     coutArrayInTheOppositeWay(a,n);
//     return 0;
// }





//TASK 2
bool twoEqualElementsInARow(int arr[], int length){
    for (int i=0; i<length;i++){
        for (int j=i+1; j<length; j++){
            if (arr[j]==arr[i]){
                if(arr[j]==arr[i+1]){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n;
    do {
        cin >> n;
    }while (n<2 || n>100);
    int arr[maxSize];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << endl;
    cout << twoEqualElementsInARow(arr,n);
    return 0;
}