#include <iostream>
#include <cstring>
using namespace std;


//task 1

double* copy_of(const double* arr, const int size){
    double* result = new(nothrow) double[size];
    if(!result){
        cout << "error";
        return 0;
    }
    for(int i=0; i<size; i++){
        result[i] = arr[i];
    }
    return result;
}

void printArray(const double* arr, const int size){
    for(int i=0; i<size; i++){
        cout << arr[i];
    }
}


//task 2
char* copy_of(const char* str){
    int size = strlen(str);
    char* result = new(nothrow) char[size];
    int i=0;
    while(*(str+i)){
        result[i] = str[i];
        i++;
    }
    return result;
}

void printString(const char* str){
    int size = strlen(str);
    for(int i=0; i<size; i++){
        cout << str[i];
    }
}




//task 3

char* my_find_capitals(const char* str){
    int count = 0;
    for(int i=0; str[i]; i++){
        if(str[i]>='A' &&  str[i]<='Z'){
            count++;
        }
    }
    char* result = new(nothrow) char[count];
    if(!result){
        cout << "error";
        return nullptr;
    }
    int k=0;
    for(int i=0; str[i]; i++){
        if(str[i]>='A' &&  str[i]<='Z'){
            result[k] = str[i];
            k++;
        }
    }
    return result;
}



//task 4
char* myconcat(const char* a, const char* b){
    int sizea = strlen(a);
    int sizeb = strlen(b);
    char* result = new(nothrow) char[sizea+sizeb+1];
    if(!result){
        cout << "No memory";
        return 0;
    }
    strcat(result,a);
    strcat(result,b);
    return result;
}



//task 5
char* myconcat_v2(const char* a, const char* b){
    int size = strlen(a) + strlen(b) + 1;
    char* result = new(nothrow) char[size];
    if(!result){
        cout << "No memory";
        return 0;
    }
    result[0] = a[0];
    result[1] = b[0];
    int indexA=0;
    int indexB=0;
    int i=0;
    bool useA = true;
    while((a[indexA]) || (b[indexB])){
        if(useA){
            if(a[indexA]){
                result[i++] = a[indexA++];
            }
        }
        if(!useA){
            if(b[indexB]){
                result[i++] = b[indexB++];
            }
        }
        useA = !useA;
    }
    result[i] = '\0';
    return result;
}



//task 6
char* backwardsString(const char* a){
    int size = strlen(a);
    char* result = new(nothrow) char[size];
    int k=size-1;
    for(int i=0; i<size; i++){
        result[i] = a[k];
        k--;
    }
    return result;
}



//task 7
void readmatrix(char m[10][10], const int n){
    for(int col=0; col<n; col++){
        for(int row=0; row<n; row++){
            cin >> m[col][row];
        }
    }
}


bool contains(const char** m, const char* word, int arrayLen, int wordLen){
    
}

bool containsInDiag(const char** m, const char* word, int arrayLen, int wordLen){
    
}




int main(){

    //task 1
    // double array[] = {1,2,3,4,5,6};
    // double* result = copy_of(array,6);
    // printArray(result, 6);
    // delete[] result;


    //task 2
    // char* str = {"penisabg"};
    // char* result = copy_of(str);
    // printString(str);
    // delete[] result;

    //task 3
    // char* str = {"pBenSisabgA"};
    // char* result = my_find_capitals(str);
    // printString(result);
    // delete[] result;


    //task 4,5
    // char* str = {"123"};
    // char* str2 = {"asd"};
    // char* result = myconcat_v2(str,str2);
    // printString(result);
    // delete[] result;

    //task 6
    // char* str = {"12345asdfg"};
    // char* result = backwardsString(str);
    // printString(result);
    // delete[] result;



    //task 7
    int n;
    cin >> n;
    const int maxSize = 10;
    char arr[maxSize][maxSize];
    readmatrix(arr,n);
    char word[maxSize];
    cin.getline(word,maxSize);
    if(strlen(word) > n){
        cout << "too long word";
        return -1;
    }
    int wordLen = strlen(word);


    return 0;
}