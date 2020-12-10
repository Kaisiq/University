#include <iostream>
using namespace std;

const unsigned int maxSize = 99;
const unsigned int minSize = 1;


void readarray(int arr[maxSize][maxSize],int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
}

int main(){
    int n;
    int m;
    do {
        cin >> n;
    }while (n<minSize || n>maxSize);
    do {
        cin >> m;
    }while (m<minSize || m>maxSize);
    int arr[maxSize][maxSize];
    readarray(arr,n,m);
    cout << endl;
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}