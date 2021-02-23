#include <iostream>
#include <cstring>
using namespace std;



//task 1



// void removeElementByindex(unsigned* col, int index, int& n){
//     for(int i=index; i<n-1; i++){
//         col[i] = col[i+1];
//     }
//     n--;
// }

// bool arrHasElement(unsigned* col, unsigned element, int& n){
//     for(int i=0; i<n; i++){
//         if(element == col[i]){
//             removeElementByindex(col, i, n);
//         }
//     }
//     return 1;
// }


// bool checkForElements(unsigned* col, unsigned* colToCheck, int& n){
//     for(int i=0; i<n; i++){
//         if(arrHasElement(colToCheck, col[i], n)){
//             removeElementByindex(colToCheck, i, n);
//         }
//     }
//     if(n){
//         return 0;
//     }
//     return 1;
// }

// bool colHasSameElements(unsigned* matrixcol, unsigned*col, int m, int& n){
//     if(checkForElements(col, matrixcol, n)){
//         return 0;
//     }
//     return 1;
// }


// int main(){
//     int n,m;
//     do{
//         cin >> m >> n;
//     }
//     while(m>n || n>500 || m<0);

//     unsigned int** matrix = new(nothrow) unsigned*[m];
//     for(int i=0;i<m;i++){
//         matrix[i] = new(nothrow) unsigned[n];
//     }
//     if(!matrix){
//         cout << "no mem";
//         return 1;
//     }

//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin >> matrix[i][j];
//         }
//     }

//     for(int i=0;i<m;i++){
//         unsigned int* col = new(nothrow) unsigned int[m];
//         if(!col){
//             delete[] matrix;
//             cout << "no mem";
//             return 1;
//         }
//         for(int j=0;j<n;j++){
//             for(int k=0; k<m; k++){
//                 col[j] = matrix[k][j];
//             }
//         }
//         // unsigned int* matrixCol = new(nothrow) unsigned int[m];
//         for(int j=i+1; j<m; j++){
//             // for(int k=0;k<n;k++){
//             //     matrixCol[k] = matrix[j][k];
//             // }
//             if(colHasSameElements(*matrix+j,col,m,n)){
//                 cout << i << " " << j << endl;
//             }
//         }
//         delete[] col;
//     }


//     return 0;
// }













//task 2

// int length(int n){
//     int counter=0;
//     if (n==0){
//         return 1;
//     }
//     while(n!=0){
//         n/=10;
//         counter++;
//     }
//     return counter;
// }


// bool canYouCreateSecondFromFirstNumberHelper(int a, int b){
//     if(a==0 && b==0){
//         return 1;
//     }
//     if(b==0 && a!=b){
//         return 0;
//     }
//     int currentDigitA = a%10;
//     int currentDigitB = b%10;
//     if(currentDigitA==currentDigitB){
//         return canYouCreateSecondFromFirstNumberHelper(a/10,b/10);
//     }
//     if(currentDigitA!=currentDigitB){
//         return canYouCreateSecondFromFirstNumberHelper(a,b/10);
//     }
// }


// bool canYouCreateSecondFromFirstNumber(int a, int b){
//     int lengthA = length(a);
//     int lengthB = length(b);
//     if(lengthA>lengthB){
//         return canYouCreateSecondFromFirstNumberHelper(b,a);
//     }
//     if(lengthA<lengthB){
//         return canYouCreateSecondFromFirstNumberHelper(a,b);
//     }
//     if(lengthA==lengthB){
//         if (a==b){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
// }


// int main(){
//     int a,b;
//     cin >> a >> b;

//     cout << canYouCreateSecondFromFirstNumber(a,b);

//     return 0;
// }










//task 3
int powOfTen(int n){
    if(n==0){
        return 1;
    }
    return 10*powOfTen(n-1);
}


int lenForNewStr(const char* text){
    int len = strlen(text);
    int count = 0;
    int countForNewStr=0;
    for(int i=0; i<len; i++){
        char current = text[i];
        count++;
        if(i>0){
            if(current!=text[i-1]){
                if(count<=4){
                    countForNewStr+=count;
                }
                else{
                    countForNewStr+=4+(count/10);
                }
                count=0;
            }
        }
    }
    return countForNewStr;
}

char* rleEncode(const char* text){
    int len = strlen(text);
    int count = 0;
    int countForNewStr=0;
    for(int i=0; i<len; i++){
        char current = text[i];
        count++;
        if(i>0){
            if(current!=text[i-1]){
                if(count<=4){
                    countForNewStr+=count;
                }
                else{
                    countForNewStr+=4+(count/10);
                }
                count=0;
            }
        }
    }

    char* result = new(nothrow) char[countForNewStr+1];
    if(!result){
        cout << "no mem";
        return nullptr;
    }
    count = 0;
    for(int i=0; i<countForNewStr+1; i++){
        char current = text[i];
        count++;
        if(i>0){
            if(current!=text[i-1]){
                if(count<=4){
                    for(int j=0; j<count; j++){
                        result[i-j] = current;
                    }
                }
                else{
                    result[i-(3+count/10)] = '(';
                    result[i] = ')';
                    for(int j=1; j<2+count/10; j++){
                        result[i-j] = count/powOfTen(j);
                    }
                    result[i-(2+count/10)] = current;
                }
                count=0;
            }
        }
        else{
            if(current!=text[i+1]){
                result[0] = text[0];
                count = 0;
            }
        }
    }

    return result;
}


int main(){
    char str[256];
    cin.getline(str,256);
    int lenForResult = lenForNewStr(str);
    char* result = new(nothrow) char[lenForResult];
    if(!result){
        return 1;
    }
    for(int i=0; i<lenForResult; i++){
        result[i] = rleEncode(str)[i];
    }
    int len = strlen(result);
    for(int i=0; i<len; i++){
        cout << result[i];
    }
    delete[] result;
    return 0;
}
