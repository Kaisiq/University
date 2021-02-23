#include <iostream>
#include <cstring>
using namespace std;


//task 1

// bool isTrionBig(int* arr, int len){
//     for(int i=1;i<len-2;i+=2){
//         if(!(arr[i]<arr[i+1] && arr[i+1]>arr[i+2])){
//             return false;
//         }
//     }
//     return true;
// }

// bool isTrionSmall(int* arr, int len){
//     for(int i=1;i<len-2;i+=2){
//         if(!(arr[i]>arr[i+1] && arr[i+1]<arr[i+2])){
//             return false;
//         }
//     }
//     return true;
// }


// int main(){
//     unsigned int n;
//     do{
//         cin >> n;
//     }while(n>100);

//     int arr[100]={0,};
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }

//     bool trion = false;

//     if(arr[0]>arr[1]){
//         trion = isTrionBig(arr, n);
//     }
//     if(arr[0]<arr[1]){
//         trion = isTrionSmall(arr,n);
//     }

//     cout << trion;

//     return 0;
// }



















//task 2

// void inputMatrix(int matrix[100][100], unsigned int n, unsigned int m){
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin >> matrix[i][j];
//         }
//     }
// }


// int porodeni(int matrix[100][100], unsigned int n, unsigned int m){
//     int count = 0;
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(i>0 && i<m && j>0 && j<n){
//                 if(matrix[i][j] == matrix[i+1][j] + matrix[i-1][j] + matrix[i][j+1] + matrix[i][j-1] + matrix[i+1][j+1] + matrix[i-1][j-1] + matrix[i+1][j-1] + matrix[i-1][j+1]){
//                     count++;
//                 }
//             }
//             else if(i>0 && i<m && j==n){
//                 if(matrix[i][j] == matrix[i+1][j] + matrix[i-1][j] + matrix[i][j-1] + matrix[i-1][j-1] + matrix[i+1][j-1]){
//                     count++;
//                 }
//             }
//             else if(i>0 && i<m && j==0){
//                 if(matrix[i][j] == matrix[i+1][j] + matrix[i-1][j] + matrix[i][j+1] + matrix[i+1][j+1] + matrix[i-1][j+1]){
//                     count++;
//                 }
//             }
//             else if(i==0 && j>0 && j<n){
//                 if(matrix[i][j] == matrix[i+1][j] + matrix[i][j+1] + matrix[i][j-1] + matrix[i+1][j+1] + matrix[i+1][j-1]){
//                     count++;
//                 }
//             }
//             else if(i==m && j>0 && j<n){
//                 if(matrix[i][j] == matrix[i-1][j] + matrix[i][j+1] + matrix[i][j-1] + matrix[i-1][j-1] + matrix[i-1][j+1]){
//                     count++;
//                 }
//             }
//             else if(i==0 && j==0){
//                 if(matrix[i][j] == matrix[i+1][j] + matrix[i][j+1] + matrix[i+1][j+1]){
//                     count++;
//                 }
//             }
//             else if(i==m && j==n){
//                 if(matrix[i][j] == matrix[i-1][j] + matrix[i][j-1] + matrix[i-1][j-1]){
//                     count++;
//                 }
//             }



//         }
//     }
//     return count;

// }

// int main(){
//     unsigned int n,m;
//     do{
//         cin >> m >> n;
//     }while(m<1 || m>n || n>100);

//     int matrix[100][100];
//     inputMatrix(matrix, n, m);
    
//     cout << porodeni(matrix,n,m);




//     return 0;
// }







//task 3    ----------------          undone


void swap(char* a, char* b){
    char* c = a;
    a = b;
    b = c;
}

bool less_than(char* word1, char* word2){
    char* one = word1;
    char* two = word2;
    if(one[0] < two[0]){
        return 1;
    }
    return 0;
}

void sortWords(char** words, int wordscount){
    for(int i=0; i<wordscount;i++){
        int maxindex = i;
        for(int j=i+1; j<wordscount; j++){
            if(less_than(words[j] , words[maxindex])){
                maxindex = j;
            }
        }
        swap(words[i], words[maxindex]);
    }
}




int main(){
    unsigned int n;
    do{
        cin >> n;
    }while(n>500);

    char* str = new(nothrow) char[n];
    if(!str){
        cout << "no mem";
        return 0;
    }

    char a;
    for(int i=0;i<n;i++){
        a = cin.get();
        str[i] = a;
    }

    int countwords= 0;
    for(int i=0;i<n;i++){
        int counter = 0;
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            countwords++;
            while((str[i+counter]>='a' && str[i+counter]<='z') || (str[i+counter]>='A' && str[i+counter]<='Z')){
                counter++;
            }
            i+=counter;
        }
    }
    char** wordsArr = new(nothrow) char*[countwords];
    if(!wordsArr){
        cout << "no mem";
        delete[] str;
        return 1;
    }

    int count;
    int k=0;
    for(int i=0; i<n-count-1; i+=count+1){
        count = 0;
        while((str[i+count]>='a' && str[i+count]<= 'z') || (str[i+count]>='A' && str[i+count]<='Z')){
            count++;
        }
        if(count == 0){
            continue;
        }
        char* currentWord = new(nothrow) char[count];
        if(!currentWord){
            delete[] str;
            cout << "no mem";
            return 1;
        }
        for(int j=0; j<count; j++){
            currentWord[j] = str[i+j];
        }
        wordsArr[k] = currentWord;
        k++;
    }

    sortWords(wordsArr,countwords);
    for(int i=0; i<=countwords; i++){
        cout << wordsArr[i] << endl;
    }



    return 0;
}