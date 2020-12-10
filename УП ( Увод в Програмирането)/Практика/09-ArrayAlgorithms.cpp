#include <iostream>
using namespace std;





//TASK 0

// int magic_function(int arr[], int golemina , size_t element) {

//     int left  = golemina / element + 1;
//     int right = golemina - 1;

//     int mid_ind, mid_val;

//     while (left >= right) {

//         mid_val = right + (left - right) / 2;
//         mid_ind = arr[mid_val];

//         if  (mid_val == golemina) {
//             return mid_ind;
//         }
//         else if (mid_val < golemina)
//         {
//             right = mid_ind;
//             continue;
//         }
//         else
//             std::cout<< "Proverqvam masiva";
//             if (mid_val > golemina) {
//                 left = mid_ind - 1;
//                 break;
//             }
//     }

//     return -1;
// }

// int main() {

//     int arr[] = { 1, 2, 3, 4, 5 };

//     if (magic_function(arr, sizeof(arr), 11))
//     {
//         std::cout << "Magic happened for 11!";
//     }
//     else
//         std::cout << "11 is not that magical at all!";

// }








//TASK 1
bool isSortedFromBiggestToSmallest (int arr[], int length){
    for (int i=0; i<length; i++){
        int leftelement = arr[i];
        int rightelement = arr[i+1];
        if (leftelement < rightelement){
            return 0;
        }
    }
    return 1;
}








//TASK 2
void insertElementInSortedArrayFromSmallToBig(int arr[], int& length, int x){
    length++;
    int i=0;
    for (i=0; i<length; i++){
        if(arr[i]<x){
            continue;
        }
        else {
            break;
        }
    }
    for (int j=length-1; j>i;j--){
        arr[j+1] = arr[j];
    }
    arr[i] = x;
}


// int main(){
//     int arr[100]={1,2,3,5,24,24,25,26,43,55,};
//     int length = 10;
//     int x = 14;
//     insertElementInSortedArrayFromSmallToBig(arr,length,x);
//     for (int i=0;i<length;i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }














//ТАСК 3

void deleteElementFromSortedArrayFromSmallToBig(int arr[], int& length, int x){
    int i=0;
    for (i=0; i<length; i++){
        if(arr[i]!=x){
            continue;
        }
        else {
            break;
        }
    }
    for (int j=i+1; j<length;j++){
        arr[j-1] = arr[j];
    }
    length--;
}


// int main(){
//     int arr[100]={0,};
//     int length;
//     int x;
//     cin >> length;
//     for(int i=0;i<length;i++){
//         cin >> arr[i];
//     }
//     cin >> x;
//     deleteElementFromSortedArrayFromSmallToBig(arr,length,x);
//     for (int i=0;i<length;i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }





















//TASK 4
bool isSymetric(int arr[], int length){
    int i=0;
    int n=length-1;
    for (i=0; i<length/2; i++){
        if(arr[i]!=arr[n]){
            return 0;
        }
        else {
            n--;
        }
    }
    return 1;

}


// int main(){
//     int arr[100]={0,};
//     int length;
//     cin >> length;
//     for(int i=0;i<length;i++){
//         cin >> arr[i];
//     }
//     cout << isSymetric(arr,length);
//     return 0;
// }















//TASK 5




int createArray2(int arr[],int length,int arr2[]){
    int j=0;
    for(int i=0;i<length;i++){
        if (arr[i]%2==0){
            arr2[j]=arr[i];
            j++;
        }
    }
    return j;
}


void switchArrayElements(int& current, int& previous){
    int a = current;
    current = previous;
    previous = a;
}


void sortArray2(int arr[],int length2){
    for (int i=1;i<length2;i++){
        int current = i;
        int previous = i-1;
        while(previous>=0 && arr[current]<arr[previous])
        {
            switchArrayElements(arr[current],arr[previous]);
            current--;
            previous--;
        }
    }
}



// int main(){
//     int arr[100]={0,};
//     int length;
//     cin >> length;
//     for(int i=0;i<length;i++){
//         cin >> arr[i];
//     }
//     int arr2[100]={0,};
//     int length2 = createArray2(arr,length,arr2);
//     sortArray2(arr2,length2);
//     for (int i=0;i<length2;i++){
//         cout << arr2[i] << " ";
//     }

//     return 0;
// }





















//TASK 6
