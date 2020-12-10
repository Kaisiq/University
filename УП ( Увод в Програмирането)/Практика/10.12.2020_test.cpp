#include <iostream>
using namespace std;


void swap (int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void readMatrix (int arr[][100], int n, int m){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}

void printMatrix (int arr[][100], int n, int m){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void selectionsort(int arr[][100],int n, int col){
    for (int j=0; j<n-1; j++){
        int min = j;  
        for (int k = j+1; k < n; k++){
            if (arr[col][k] < arr[col][min]) {
                min = k;  
            }
        }
        swap(&arr[col][min],&arr[col][j]);
    }
}

int main(){
    int m,n;
    cin >> m >> n;
    int arr[100][100];

    readMatrix(arr,n,m);

    for (int i=0;i<m;i++){
        selectionsort(arr,n,i);
    }

    cout << endl;

    printMatrix(arr,n,m);

    return 0;
}

