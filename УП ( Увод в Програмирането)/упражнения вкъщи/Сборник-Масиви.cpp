//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Решения на задачи от сборник по УП
// 2020-11-23
// Страница 182
//
// Име: Даниел Иванов
// ФН:
// Специалност: Информатика
// Курс:  1
// Административна група: 
//


#include <iostream>
using namespace std;

//TASK 3
//  1<=n<=100
// chetni el. s necheten poreden nomer
// [p,q]

 const unsigned maxSize = 100;
// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<1 || n>100);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;
//     int p,q;
//     cin >> p >> q;
//     int count=0;
//     for (int i=p; i<=q; i++){
//         if(arr[i]%2==0 && i%2!=0){
//             count++;
//         }
//     }
//     cout << count;
//     return 0;
// }














//TASK 4
// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<1 || n>100);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;
//     //a)
//     for(int i=0;i<n;i++){
//         if(arr[i]>0){
//             cout << i;
//             break;
//         }
//     }

//     //b)
//     for (int i=n-1;i>0;i--){
//         if(arr[i]>0){
//             cout << i;
//             break;
//         }
//     }

//     //c)
//     int p;
//     cin >> p;
//     int count = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]>0){
//             count++;
//         }
//         if (count==p){
//             cout << i;
//             break;
//         }
//     }
//     return 0;
// }













//TASK 5
// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<1 || n>100);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;

//     for (int i=0;i<n;i++){
//         if (arr[i]<i){
//             arr[i]*=arr[i];
//         }
//         if (arr[i]==i){
//             arr[i]*=(-1);
//         }
//         if (arr[i]>i){
//             arr[i]--;
//         }
//     }
//     for (int i=0;i<n;i++){
//         cout << arr[i];
//     }


//     return 0;
// }












//TASK 6
// int main(){
//     int arr[maxSize]={1,24,6,45,8,3,5,3,3,5,8,2,4,6,3,7,2,4,8,2,4,8,3,3,6,8,3,2,2,54,8,9,7,845,64,64,5,45,45,45,45,45,45,345,23,52,35,};
//     for (int i=1; i<maxSize;i++){
//         if (arr[i]%i==0 && arr[i]!=0){
//             cout << arr[i] << " ";
//         }
//     }
//     return 0;
// }












//TASK 7
// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<1 || n>100);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;
//     //a)
//     for (int i=n-1; i>=0;i--){
//         cout << arr[i] << " ";
//     }

//     //b)
//     cout << endl;
//     for (int i=0; i<n; i+=2){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     for (int i=1; i<n; i+=2){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }
















//TASK 8
// #include <cmath>
// int sqrt(const int a){
//     int b = a-3;
//     for (int i=0;i<b;i++){
//         if(i*i == b){
//             return i;
//         }
//     }
// }

// void printarrayB(int arr[]){
//     for (int i=0;i<maxSize;i++){
//         if (arr[i]>=3){
//             cout << sqrt(arr[i]) << " ";
//         }
//         if (arr[i]<3 && arr[i]!=0){
//             cout << 1/(arr[i]) + sin(arr[i]+5) << " ";
//         }
//         if (arr[i]==0){
//             cout << 0 << " ";
//         }
//     }
// }

// int main(){
//     int a[maxSize]= {1,2,4,0,4};
//     printarrayB(a);
//     return 0;
// }

















//TASK 9
// void createArrayC(int a[],int b[]){
//     int n;
//     do { 
//         cin >> n;
//     }while (n<=0 || n>100);
//     int c[maxSize]={0,};
//     int sum;
//     for (int i=0;i<n;i++){
//         sum = 0;
//         for (int j=0;j<n;j++){
//             sum += a[j]*a[j];
//         }
//         c[i]+=b[i]*b[i]+sum;
//     }
// }











//TASK 10
// void createBi(int a[], int b[], int i, int n){
//     for (int j = 0; j<n; j+=i){
//         b[i-1] = a[j];
//     }
// }
// void createArrayB(int a[],int n){
//     int b[maxSize]={0,};
//     for (int i=1;i<n;i++){
//         createBi(a,b,i,n);
//     }
//     for(int i;i<n;i++){
//         cout << b[i];
//     }
// }
















//TASK 11

// double max(double a, double b){
//     if (a>b){
//         return a;
//     }
//     if (b<=a){
//         return b;
//     }
// }

// double min(double a, double b){
//     if (a>b){
//         return b;
//     }
//     if (b<=a){
//         return a;
//     }
// }

// void createArrayB(double x[], double y[], int n){
//     double c[maxSize]={0,};
//     for (int i=0;i<n;i++){
//         if (x[i]>y[i]){
//             c[i] = max(x[i],y[i]+2);
//         }   
//         if (x[i]<=y[i]){
//             c[i] = min(x[i]*x[i]+3,y[i]+1,10);
//         }   
//     }
// }
















//TASK 12
// int max(int a, int b){
//     if (a>b){
//         return a;
//     }
//     if (b<=a){
//         return b;
//     }
// }

// int pow(int a, int stepen){
//     for (int i=1;i<=stepen;i++){
//         a*=a;
//     }
//     return a;
// }
// int sqrt(int a){
//     for (int i=0; i<a/2;i++){
//         if (i*i == a){
//             return i;
//         }
//     }
// }

// bool imakorenipogolemiot2(int a){
//     int ac4 = 4*a*10;
//     int D = pow(a*a - a + 19 , 2) - ac4;
//     int X1 = ((a*a - a + 19) - sqrt(D))/2*a;
//     int X2 = ((a*a - a + 19) + sqrt(D))/2*a;
//     if (D<0){
//         return 0;
//     }
//     if (a==0){
//         return 0;
//     }
//     if (X1+X2 > -2){
//         return 1;
//     }
//     else {
//         return 0;
//     }
// }

// int biggestPower(int a[]){
//     int n;
//     cin >> n;
//     int biggest = 0;
//     for (int i=0;i<n;i++){
//         if(imakorenipogolemiot2(a[i])){
//             if(biggest<a[i]*a[i]){
//                 biggest = a[i]*a[i];
//             }
//         }
//         else continue;   
//     }
//     return biggest;
// }











//TASK 13              nedovurshena

// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<1 || n>100);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;
//     int arr2[maxSize]={0,};


//     for (int i=0,j=0,k=0;i<n;i++){

//         for (j=0;j<i;j++){
//             for (k=i-1;k>=0;k--){
//                 if (arr[j]==arr2[k]){
//                     break;
//                 }
//             }
//                 if (arr[j]==arr2[k]){
//                     break;
//                 }
//         }
//         if (arr[j]==arr2[k]){
//                 break;
//         }else if (arr[j]!=arr2[k]){
//             arr2[i]=arr[j];
//         }
//     }

//     for (int i=0;i<n;i++){
//         cout << arr2[i] << " ";
//     }

//     return 0;
// }











//TASK 14

// bool elementInTwoPlacesInARow(int arr[], int x, int length){
//     for (int i=0; i<length;i++){
//         if (x==arr[i]){
//             if(x==arr[i+1]){
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }


// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<2 || n>100);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;
//     cout << elementInTwoPlacesInARow(arr,5,n);


//     return 0;
// }













//TASK 15
// bool sumOfThreeElementsInARow(int arr[], int x, int length){
//     for (int i=0; i<length;i++){
//         if (x==(arr[i]+arr[i+1]+arr[i+2])){
//             return 1;
//         }
//     }
//     return 0;
// }


// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<3 || n>100);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;
//     cout << sumOfThreeElementsInARow(arr,17,n);


//     return 0;
// }












//TASK 16
// bool atLeastTwoElementsArePowerOf2(int arr[], int length){
//     int count = 0;
//     for (int i=0; i<length;i++){
//         for (int j=0;j<31;j++){
//             if (arr[i]==(1<<j)){
//             count++;
//             }
//         }
//     }
//     if (count >=2 ){
//         return 1;
//     }
//     return 0;
// }


// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<3 || n>30);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;
//     cout << atLeastTwoElementsArePowerOf2(arr,n);


//     return 0;
// }














//TASK 17
// bool atLeastKElementsArePowerOfN(int arr[], int length, int k){
//     int count = 0;
//     for (int i=0; i<length;i++){
//         for (int j=1;j*j<=i;j*=length){
//             if (arr[i]==j){
//             count++;
//             }
//         }
//     }
//     if (count >=k ){
//         return 1;
//     }
//     return 0;
// }


// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<3 || n>30);
//     int arr[maxSize];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << endl;
//     cout << atLeastKElementsArePowerOfN(arr,n,1);


//     return 0;
// }

















//TASK 18

int max(int arr[],int length){
    int max=arr[0];
    for (int i=length-1;i>=0;i--){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int min(int arr[],int length){
    int min=arr[0];
    for (int i=0;i<length;i++){
        if(min>arr[i]){
            min = arr[i];
        }
    }
    return min;
}


bool isDuplicate(int arr[],int x, int length){
    int count=0;
    for (int i=0;i<length;i++){
        if(arr[i]==x){
            count++;
        }
    }
    if (count>=2){
        return 1;
    }
    return 0;
}



int main(){
    int n;
    do {
        cin >> n;
    }while (n<1 || n>100);
    int arr[maxSize];
    int arr2[maxSize]={0,};
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << endl;
    int k=n-1;
    for (int i=n-1;i>=0;i--){
        if(!isDuplicate(arr2,(max(arr,i)),i)){
            arr2[k]=max(arr,i);
            k--;
        }else {continue;}
    }

    for (int i=0; i<n; i++){
        cout << arr2[i]<< " ";
    }


    return 0;
}