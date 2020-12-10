#include <iostream>
using namespace std;

const unsigned int maxSize = 99;
const unsigned int minSize = 1;


//TASK 1
// void readarray(int arr[][maxSize],int n, int m){
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             cin >> arr[i][j];
//         }
//     }
// }

// void printarray(int arr[][maxSize],int n, int m){
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main(){
//     int n;
//     int m;
//     cin >> n;
//     cin >> m;
//     int arr[minSize][maxSize];
//     readarray(arr,n,m);
//     printarray(arr,n,m);

//     return 0;   
// }












//TASK 2
// void readarray(int arr[maxSize][maxSize],int n, int m){
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             cin >> arr[i][j];
//         }
//     }
// }

// int getSmallestElement(int arr[maxSize][maxSize], int n, int m){
//     int min = arr[0][0];
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             if (arr[i][j]<min){
//                 min = arr[i][j];
//             }
//         }
//     }   
//     return min;
// }

// int main(){
//     int n;
//     int m;
//     do {
//         cin >> n;
//     }while (n<minSize || n>maxSize);
//     do {
//         cin >> m;
//     }while (m<minSize || m>maxSize);
//     int arr[maxSize][maxSize];
//     readarray(arr,n,m);
    
//     cout << getSmallestElement(arr,n,m);

//     return 0;   
// }


















//TASK 3
// void readarray(int arr[maxSize][maxSize],int n, int m){
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             cin >> arr[i][j];
//         }
//     }
// }

// void multiplyArray(int arr[maxSize][maxSize], int n, int m, int a){
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             arr[i][j] *= a;
//         }
//     }   
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }   
// }

// int main(){
//     int a;
//     cin >> a;
//     int n;
//     int m;
//     do {
//         cin >> n;
//     }while (n<minSize || n>maxSize);
//     do {
//         cin >> m;
//     }while (m<minSize || m>maxSize);
//     int arr[maxSize][maxSize];
//     readarray(arr,n,m);
    
//     multiplyArray(arr,n,m,a);

//     return 0;   
// }


















//TASK 4
// void readarray(int arr[maxSize][maxSize],int n, int m){
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             cin >> arr[i][j];
//         }
//     }
// }

// void addTwoArrays(int arr[maxSize][maxSize],int arr2[maxSize][maxSize], int n, int m){
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             arr[i][j] += arr2[i][j];
//         }
//     }   
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }   
// }

// int main(){
//     int n;
//     int m;
//     do {
//         cin >> n;
//     }while (n<minSize || n>maxSize);
//     do {
//         cin >> m;
//     }while (m<minSize || m>maxSize);
//     int arr[maxSize][maxSize];
//     readarray(arr,n,m);

//     int arr2[maxSize][maxSize];
//     readarray(arr2,n,m);
    
//     addTwoArrays(arr,arr2,n,m);

//     return 0;   
// }













//TASK 5
// void readarray(int arr[maxSize][maxSize],int n, int m){
//     for (int i=0; i<n; i++){
//         for (int j=0;j<m;j++){
//             cin >> arr[i][j];
//         }
//     }
// }

// void printOnlyAngles(int arr[maxSize][maxSize], int row, int col){  
//     for (int i=0; i<row; i++){
//         for (int j=0;j<col;j++){
//             if (((i!=0 || i!=row-1) && (j==0 || j==col-1))){
//                 cout << arr[i][j] << " ";
//             }
//             else if (((i==0 || i==row-1) && (j!=0 || j!=col-1))){
//                 cout << arr[i][j] << " ";
//             }
//             else if (((i==0 || i==row-1) && (j==0 || j==col-1))){
//                 cout << arr[i][j] << " ";
//             }
//             else {
//                 cout << "  ";
//             }
//         }
//         cout << endl;
//     }   
// }

// int main(){
//     int n;
//     int m;
//     do {
//         cin >> n;
//     }while (n<minSize || n>maxSize);
//     do {
//         cin >> m;
//     }while (m<minSize || m>maxSize);
//     int arr[maxSize][maxSize];
//     readarray(arr,n,m);
//     cout << endl;
    
//     printOnlyAngles(arr,n,m);

//     return 0;   
// }