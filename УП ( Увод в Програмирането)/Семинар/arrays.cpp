#include <iostream>
#include <string.h>
using namespace std;



// <type> <name> [<number_of_elements>];



void printArray(const int arr[], const unsigned lenght){
    for (int i=0; i<lenght; i++){
        cout << arr[i] << endl;
    }
}
void readArray(int arr[], const unsigned lenght){
    for (int i=0; i<lenght; i++){
        cin >> arr[i];
    }
}
int read(){
    int k;
    cin >>k;
    return k;
}






//TASK 1
// const int MAX = 128;
// int read(){
//     int k;
//     cin >>k;
//     return k;
// }

// int main(){
//     const int n = read();
//     if (n>100){
//         cout << "invalid input";
//         return 1;
//     }
//     int arr[MAX];
//     readArray(arr, n);
//     printArray(arr, n);
//     return 0;
// }










//TASK 2

// int minimalElement(const int arr[], const int lenght){
//     int minimal = arr[0];
//     for (int i=0; i<lenght; i++){
//         if(arr[i]<minimal){
//             minimal = arr[i];
//         }
//     }
//     return minimal;
// }



// const int MAX = 128;
// int read(){
//     int k;
//     cin >>k;
//     return k;
// }

// int main(){
//     const int n = read();
//     if (n>100){
//         cout << "invalid input";
//         return 1;
//     }
//     int arr[MAX];
//     readArray(arr, n);
//     cout << minimalElement(arr, n);

//     return 0;
// }













//TASK 3
// int maxElement(const int arr[], const int lenght){
//     int max = arr[0];
//     for (int i=0; i<lenght; i++){
//         if(arr[i]>max){
//             max = arr[i];
//         }
//     }
//     return max;
// }



// const int MAX = 128;

// int main(){
//     const int n = read();
//     if (n>100){
//         cout << "invalid input";
//         return 1;
//     }
//     int arr[MAX];
//     readArray(arr, n);
//     cout << maxElement(arr, n);

//     return 0;
// }





















//TASK 4
// int average(const int arr[], const int lenght){
//     int sum = arr[0];
//     int del = 1;
//     for (int i=1; i<lenght; i++){
//         sum += arr[i];
//         del++;
//     }
//     return (sum/del);
// }



// const int MAX = 128;

// int main(){
//     const int n = read();
//     if (n>100){
//         cout << "invalid input";
//         return 1;
//     }
//     int arr[MAX];
//     readArray(arr, n);


//     cout << average(arr, n);

//     return 0;
// }










//TASK 5
// void evenNumbers(const int arr[], int lenght){
//     for (int i=0; i<lenght; i++){
//         if ((arr[i]%2)==0){
//             cout << arr[i] << " ";
//         }
//     }
// }



// const int MAX = 128;
// int main(){
//     const int n = read();
//     if (n>100 || n<0){
//         cout << "Invalid input";
//         return 1;
//     }
//     int arr[MAX];
//     readArray(arr, n);
//     evenNumbers(arr, n);
//     return 0;
// }









//TASK 6
// void evenNumbers(const int arr[], int lenght){
//     for (int i=(lenght-1); i>=0; i--){
//         if ((arr[i]%2)!=0){
//             cout << arr[i] << " ";
//         }
//     }
// }



// const int MAX = 128;
// int main(){
//     const int n = read();
//     if (n>100 || n<0){
//         cout << "Invalid input";
//         return 1;
//     }
//     int arr[MAX];
//     readArray(arr, n);
//     evenNumbers(arr, n);
//     return 0;
// }











//TASK 7
// const int MAX = 128;

// bool issymetrical(const int arr[], int lenght){
//     int symetricArr[MAX];
//     for (int i=0; i<lenght; i++){
//         symetricArr[i] = arr[(lenght-1)-i];
//     }
//     for (int i=0; i<lenght; i++){
//         if(symetricArr[i]!=arr[i]){
//             return 0;
//         }
//     }
//     return 1;
// }

// int main(){
//     const int n = read();
//     if (n>100 || n<0){
//         cout << "Invalid input";
//         return 1;
//     }
//     int arr[MAX];
//     readArray(arr, n);

//     if (issymetrical(arr, n)){
//         cout << "simetrichna e";
//     }else{
//         cout << "ne e simetrichna";
//     }


//     return 0;
// }











//TASK 7a     nedovurshena

// void shuffle ()


// const int MAX = 128;
// int main(){
//     const int n = read();
//     if (n>100 || n<0){
//         cout << "Invalid input";
//         return 1;
//     }
//     int arr[MAX];
//     readArray(arr, n);

   


//     return 0;
// }


























//5.12.2020
const int maxSize = 100;



//TASK 0

// int main(){
//     int n;
//     cin >> n;
//     int arr[maxSize][maxSize]={0,};
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin >> arr[i][j];
//         }
//     }

//     int arr2[maxSize]={0,};
//     int sum;
//     for(int i=0;i<n;i++){
//         sum = 0;
//         for (int j=0;j<n;j++){
//             sum += arr[j][i];
//         }
//         arr2[i] = sum;
//     }

//     for(int i=0;i<n;i++){
//         cout << arr2[i] << " ";
//     }
//     return 0;
// }









//TASK 1

// int main(){
//     int n;
//     cin >> n;
//     int arr[maxSize][maxSize]={0,};
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin >> arr[i][j];
//         }
//     }


//     bool arr2[maxSize][maxSize]={0,};
//     for(int i=0;i<n;i++){
//         for (int j=0;j<n;j++){
//             if (arr[i][j]%3==0){
//                 arr2[i][j] = 1;
//             }
//             else {
//                 arr2[i][j] = 0;
//             }
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout << arr2[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }










//TASK 2

void readMatrix(int arr[][10],int length){
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            cin >> arr[i][j];
        }
    }
}

void printMatrix(int arr[][10],int length){
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}



void multiply (int arr[][maxSize], int arr2[][maxSize], int size, int arrresult[][maxSize]){
    for(int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            for(int k=0; k<size; k++){
                arrresult[i][j] += arr[i][k] * arr2[k][j];
            }
        }
    }
}

// int main(){
//     int n;
//     cin >> n;
//     int arr[maxSize][maxSize]={0,};
//     readMatrix(arr,n);

//     int arr2[maxSize][maxSize]={0,};
//     readMatrix(arr2,n);

//     int arrResult[maxSize][maxSize];

//     multiply (arr,arr2,n,arrResult);



//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout << arrResult[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }














// TASK 3


void transformMatrixToArr(int matrix[][10], int arr[], int size){
    int n = size*size;
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0; j<size;j++){
            arr[k] = matrix[i][j];
            k++;
        }
    }
}


// int main(){
//     int n;
//     cin >> n;
//     int matrix[maxSize][maxSize]={0,};
//     readMatrix(matrix,n);
//     int arr[maxSize];
//     transformMatrixToArr(matrix,arr,n);
//     for(int i=0;i<n*n;i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


int sqrt(int a){
    for (int i=1;i<a;i++){
        if(i*i==a){
            return i;
        }
    }
}

void transformArrToMatrix(int arr[],int matrix[][10],int size){
    int n = sqrt(size);
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            matrix[i][j] = arr[k];
            k++;
        }
    }
}

int minindex(int arr[], int size, int k){
    int minindex = k;
    for (int i=0;i<size;i++){
        if (arr[minindex] > arr[i]){
            minindex = i;
        }
    }
    return minindex;
}

void swap(int& a, int&b){
    int c = a;
    a = b;
    b = c;
}


void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(arr[min_idx], arr[i]);  
    }  
}  





//TASK 4


// int main(){
//     int n;
//     cin >> n;
//     int matrix[10][10]={0,};
//     readMatrix(matrix,n);
//     int arr[100];
//     transformMatrixToArr(matrix,arr,n);
    
//     selectionSort(arr,n*n);

//     transformArrToMatrix(arr,matrix,n*n);

//     printMatrix (matrix,n);

//     return 0;
// }


















//TASK 5

int length(char* i)
{
    int k=0;
    int count=0;
    while (i[k]!='\0'){
        k++;
        count++;
    }
    return count;
}



// int main(){
//     char words[8][20];
//     for (int i=0;i<8;i++){
//         cin >> words[i];
//     }
    
//     for (int i=0;i<8;i++){
//         if(length (words[i])==6){
//             cout << words[i] << endl;
//         }
//     }
//     return 0;
// }









//TASK 6
// int main(){
//     char words[8][20];
//     for (int i=0;i<8;i++){
//         cin >> words[i];
//     }
    
//     for (int i=0;i<8;i++){
//         int minlength = i;
//         for (int k=i+1;k<8;k++){
//             if(length(words[minlength])>length(words[k])){
//                 minlength = k;
//             }
//         }
//         swap (words[i],words[minlength]);

//     }
//     for (int i=0;i<8;i++){
//         cout << words[i] << " ";
//     }

//     return 0;
// }















//TASK 7
// int main(){
//     char words[8][20];
//     for (int i=0;i<8;i++){
//         cin >> words[i];
//     }
    
//     for (int i=0;i<8;i++){
//         int minlex = i;
//         for (int k=i+1;k<8;k++){
//             if(strcmp (words[minlex],words[k])>0){
//                 minlex = k;
//             }
//         }
//         swap (words[i],words[minlex]);

//     }
//     for (int i=0;i<8;i++){
//         cout << words[i] << " ";
//     }

//     return 0;
// }





















//TASK 8
int countOfASymbol(char str[][10], int n, int m, char symbol){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (str[i][j] == symbol){
                count++;
            }
        }
    }
    return count;
}


// int main(){
//     int n,m;
//     cin >> n >> m;
//     char symbol;
//     cin >> symbol;
//     char str[10][10];
//     for(int i=0;i<n;i++){
//         for (int j=0;j<m;j++){
//             cin >> str[i][j];
//         }
//     }
//     cout << endl << countOfASymbol(str,n,m,symbol);
//     return 0;
// }














//TASK 9 -   nedovurshena   help
int main(){
    char chars[10][8];
    for (int i=0;i<5;i++){
        for(int j=0;j<8;j++){
            cin >> chars[i][j];
        }
    }
    char word[10];
    cin >> word;

    int count=0;
    for(int i=0;i<10;i++){
        if(chars[i] == word){
            count++;
        }
    }
    cout << count;
    return 0;
}