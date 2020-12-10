#include <iostream>
using namespace std;


//TASK 1
// void readelements(int arr[], int n){
//     for (int i=0;i<n;i++){
//         cin >> arr[i];
//     }
// }
// void printelements(int arr[], int n){
//     for (int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
// }


// int main(){
//     int n;
//     cin >> n;
//     const int a = n;
//     int arr[a];
//     readelements(arr,a);
//     printelements(arr,a);

//     return 0;
// }














//TASK 2
// void readelements(int arr[], int n){
//     for (int i=0;i<n;i++){
//         cin >> arr[i];
//     }
// }
// int sum(int arr[], int n){
//     int sum=0;
//     for (int i=0;i<n;i++){
//         sum+=arr[i];
//     }
//     return sum;
// }

// int multiplication(int arr[], int n){
//     int multiplication=1;
//     for (int i=0;i<n;i++){
//         multiplication*=arr[i];
//     }
//     return multiplication;
// }


// int main(){
//     int n;
//     cin >> n;
//     const int a = n;
//     int arr[a];
//     readelements(arr,a);
//     cout << sum(arr,a) << endl;
//     cout << multiplication(arr,a);

//     return 0;
// }















//TASK 3
// void readelements(int arr[], int n){
//     for (int i=0;i<n;i++){
//         cin >> arr[i];
//     }
// }

// int minelement (int arr[], int n){
//     int index=0;
//     int smallest=arr[0];
//     for (int i=0;i<n;i++){
//         if(arr[i]<smallest){
//             smallest = arr[i];
//             index = i;
//         }
//     }
//     return index;
// }

// int maxelement (int arr[], int n){
//     int index=0;
//     int biggest=arr[0];
//     for (int i=0;i<n;i++){
//         if(arr[i]>biggest){
//             biggest = arr[i];
//             index = i;
//         }
//     }
//     return index;
// }

// int main(){
//     int n;
//     cin >> n;
//     const int a = n;
//     int arr[a];
//     readelements(arr,a);
//     cout << "index of minimal element is: " << minelement(arr,a) << endl;
//     cout << "minimal element is: " << arr[minelement(arr,a)] << endl;
//     cout << "index of maximal element is: " << maxelement(arr,a) << endl;
//     cout << "maximal element is: " << arr[maxelement(arr,a)] << endl;
//     return 0;
// }














//TASK 4
// void readelements(int arr[], int n){
//     for (int i=0;i<n;i++){
//         cin >> arr[i];
//     }
// }

// bool isPrime(int a){
//     for(int i=2; i<a;i++){
//         if(a%i==0){
//             return 0;
//         }
//     }
//     return 1;
// }
// void printifprime(int arr[],int n){
//     for (int i=0;i<n;i++){
//         if(isPrime(arr[i])){
//             cout << arr[i] << " ";
//         }
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     const int a = n;
//     int arr[a];
//     readelements(arr,a);
//     printifprime(arr,a);

//     return 0;
// }














//TASK 5     
// void readelements(int arr[], int n){
//     for (int i=0;i<n;i++){
//         cin >> arr[i];
//     }
// }

// bool isOdd(int a){
//     if (a%2==0){
//         return 0;
//     }
//     else {
//         return 1;
//     }
// }
// void miltiplyAllOddNumbersIndexes(int arr[],int n){
//     int multiplication = 1;
//     for (int i=0;i<n;i++){
//         if(isOdd(arr[i])){
//             multiplication *= i;
//         }
//     }
//     cout << multiplication;
// }

// int main(){
//     int n;
//     cin >> n;
//     const int a = n;
//     int arr[a];
//     readelements(arr,a);
//     miltiplyAllOddNumbersIndexes(arr,n);

//     return 0;
// }