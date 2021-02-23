#include <iostream>
using namespace std;





//TASK 1

int getLength(const char* const str){
    int count = 0;
    while(str[count]){
        count++;
    }
    return count;
}

void readString(char* str, int* size, const int* const maxLength){
    cin.getline(str, *maxLength);      //*maxLength  ======  maxLength[0]
    *size = getLength(str);
}

// int main(){
//     const int maxLength = 30;
//     char str1[maxLength];
//     int result;
//     readString(str1,&result,&maxLength);
//     cout << result;
// }









//TASK 1

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}


// int main(){
//     int a=4,b=3;
//     swap(&a,&b);
//     cout << a << b;
//     return 0;
// }







//TASK 2

void bigSmall(int* a, int* b){
    if(*b>*a){
        int c = *a;
        *a = *b;
        *b = c;
    }
    return;
}



//TASK 3

void doubleArrayWithPointers(int* arr, int* size){
    for(int i=0; i<*size; i++){
        cout << *(arr+i)*2 << " ";
    }
}
// int main(){
//     int arr[5];
//     cin >> *arr;
//     cin >> *(arr+1);
//     cin >> *(arr+2);
//     cin >> *(arr+3);
//     cin >> *(arr+4);

//     int size = 5;

//     doubleArrayWithPointers(arr, &size);
//     return 0;
// }











//TASK 4

void printEvenPositionsWithPointers(char* const str){
    char* str1 = str;
    for(; *str1 && *(str1+1); str1+=2){
        cout << *str1;
    } 
}

// int main(){
//     char* str = "penisabgbrat";
//     printEvenPositionsWithPointers(str);
//     return 0;
// }









//TASK 5
bool isCorrectPositiveNumber(const char* number) {
    if(*number && (*number!='0') && (*number>='1' && (*number<='9'))){
        number++;
    }else{
        return 0;
    }
    for(; *number; number++){
        if(*number<'0' || (*number>'9')){
            return 0;
        }
    }
    return 1;
}


// int main(){
//     char* str = "";
//     cout << isCorrectNumber(str);
//     cout << endl;
//     return 0;
// }







//TASK 6

bool isCorrectNumber(const char* number) {
    if(*number && (*number>='0' && (*number<='9') || *number == '-')){
        if(*number == '0'){
            if(!(*(number+1))){
                return 0;
            }
        }
        if(*number == '-' && *(number+1) == '0'){
            return 0;
        }
        number++;
    }else{
        return 0;
    }
    for(; *number; number++){
        if(*number<'0' || (*number>'9')){
            return 0;
        }
    }
    return 1;
}

// int main(){
//     int maxlength = 500;
//     char* str[maxlength];
//     cout << isCorrectNumber(str);
//     cout << endl;
//     return 0;
// }









//TASK 7

void pointerToPointer(const int** a, const int* const b){
    *a = b;
}


// int main(){
//     int a = 123123;
//     int b = 4454545;
//     const int* ptra = &a;
//     const int* ptrb = &b;
//     cout << "old ptra:" << *ptra;
//     pointerToPointer(&ptra,ptrb);
//     cout << endl;
//     cout << "new ptra:" << *ptra;
// }   