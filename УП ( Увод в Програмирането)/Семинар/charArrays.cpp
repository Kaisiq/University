#include <iostream>
using namespace std;



const unsigned MaxSize = 128;

void readStr (char arr[], int length){
    for(int i=0;i<length-1;i++){
        cin>> arr[i];
    }
}

void printStr (char arr[], int length){
    cout << arr;
}




//TASK 0
// int numberOfCharA(const char* str, int length){
//     int count = 0;
//     for (int i=0;i<length;i++){
//         if (str[i] == 'a'){
//             count++;
//         }
//     }
//     return count;
// }

// int main(){
//     char str[MaxSize]={"dfjgdfiujgasjsdifjasfoj"};
//     cout << numberOfCharA(str, MaxSize);
//     return 0;
// }









//TASK 1
// int numberOfDigits(const char* str, int length){
//     int count = 0;
//     for (int i=0;i<length;i++){
//         if ((str[i]>='0') && (str[i]<='9')){
//             count++;
//         }
//     }
//     return count;
// }

// int main(){
//     char str[MaxSize]={"dfjg1d5fiujgasjsd34ifjas7foj"};
//     cout << numberOfDigits(str, MaxSize);
//     return 0;
// }









//TASK 1.1
// char digitToChar(const int n){
//     char sym = n + '0';
//     return sym;
// }
// int main(){
//     int a;
//     cin >> a;
//     char b = digitToChar(a);
//     cout << b;
//     return 0;
// }






//TASK 1.2
// char lastDigitToChar(const int n){
//     char sym = (n%10) + '0';
//     return sym;
// }
// int main(){
//     int a;
//     cin >> a;
//     char b = lastDigitToChar(a);
//     cout << b;
//     return 0;
// }









//TASK 1.3
// char firstDigitToChar(const int n){
//     int b=n;
//     while(b>=10){
//         b/=10;
//     }
//     char sym = (b) + '0';
//     return sym;
// }
// int main(){
//     int a;
//     cin >> a;
//     char b = firstDigitToChar(a);
//     cout << b;
//     return 0;
// }












//TASK 1.4 char*           - nikakva ideq
// void numberToChar(const int n, char* result){
//     int counter = 0;
//     int b=n;    //n duplicate
//     while (b>0){
//         counter++;
//         b/=10;
//     }
//     b = n;
//     int i=counter;
//     while (i>0){
//         result[i]=b%10;
//         i--;
//         b/10;
//     }
//     return ;
// }
// int main(){
//     char a[MaxSize];
//     numberToChar(17,a);
//     cout << a;
//     return 0;
// }













//TASK 2
// bool areAllUpcase(char* str, int length){
//     bool areAllUp = true;
//     for(int i=0;i<length;i++){
//         if((str[i]<'A' && str[i]!='\0') || (str[i]>'Z' && str[i]!='\0')){
//             areAllUp=0;
//             return areAllUp;
//         }
//     }
//     return areAllUp;
// }
// int main(){
//     char a[MaxSize]={"ASDASFD"};
//     cout << areAllUpcase(a,MaxSize);
//     return 0;
// }














//TASK 2.1
// int main(){
//     int n;
//     cin >> n;
//     char a[MaxSize] = {0,};
//     for (int i=0;i<n;i++){
//         cin >> a[i];
//     }
//     for (int i=0;i<n;i++){
//         cout << (int)a[i] << " ";
//     }
//     return 0;
// }








//TASK 2.2    ??????????????????????????
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }
// void reverse(char* str){
//     char a=0;
//     int j=length(str);
//     for(int i=0;i<length(str);i++){
//         a=str[i];
//         str[i] = str[j-i];
//         str[j-i] = a;
//     }
// }

// int main(){
//     char str[MaxSize];
//     int n;
//     cin >> n;
//     for (int i=0;i<n;i++){
//         cin >> str[i];
//     }
//     reverse(str);
//     for (int i=0;i<n;i++){
//         cout << str[i];
//     }
//     return 0;
// }






//TASK 3
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }
// bool isValidNaturalNumber(char* str){
//     if (str[0]==0){
//         return 0;
//     }
//     if (str[0]<'1'||str[0]>'9'){
//         return 0;
//     }
//     if (!(str[0]<'1' || str[0]>'9')){
//         for (int i=1; i<length(str); i++){
//             if(str[i]<'0' || str[i]>'9'){
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }
// int main(){
//     char a[50]={"10000007"};
//     cout << isValidNaturalNumber(a);
//     return 0;
// }









//TASK 3a
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }
// bool isValidNaturalNumber(char* str){
//     if (str[0]==0){
//         return 0;
//     }
//     if ((str[0]<'1'||str[0]>'9')&&(str[0]<'A' || str[0]>'F')){
//         return 0;
//     }
//     if (!((str[0]<'1'||str[0]>'9')&&(str[0]<'A' || str[0]>'F'))){
//         for (int i=1; i<length(str); i++){
//             if((str[i]<'0' || str[i]>'9')  && (str[i]<'A' || str[i]>'F')) {
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }
// int main(){
//     char a[50]={"0ABD"};
//     cout << isValidNaturalNumber(a);
//     return 0;
// }









// TASK 4    
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }

// bool isValidInt(char* str){
//     if ((str[0]<'0'||str[0]>'9') && str[0]!='-'){
//         return 0;
//     }
//     if (!((str[0]<'0' || str[0]>'9') && (str[0]!='-'))){
//         for (int i=1; i<length(str); i++){
//             if(str[i]<'0' || str[i]>'9'){
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }
// int main(){
//     char a[50]={"0"};
//     cout << isValidInt(a);
//     return 0;
// }







//TASK 4A
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }

// bool isValidInt(char* str){
//     if ((str[0]<'0'||str[0]>'9') && str[0]!='-' &&(str[0]<'A' || str[0]>'D')){
//         return 0;
//     }
//     if (!((str[0]<'0' || str[0]>'9') && (str[0]!='-') &&(str[0]<'A' || str[0]>'D'))){
//         for (int i=1; i<length(str); i++){
//             if((str[i]<'0' || str[i]>'9') && (str[i]<'A' || str[i]>'D')){
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }
// int main(){
//     char a[50]={"12D4ACD6"};
//     cout << isValidInt(a);
//     return 0;
// }














//TASK 5
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }

// bool same(const char* a, const char* b){
//     int i=0;
//     while (a[i]==b[i] && a[i] && b[i]){
//         i++;
//     }
//     return a[i]==b[i];
// }

// bool hasSymbol(const char symbol, char* str){
//     for(int i=0;i<length(str);i++){
//         if(str[i]==symbol){
//             return 1;
//         }
//     }
//     return 0;
// }
// int numberOf(const char symbol, char* str){
//     int count=0;
//     for(int i=0;i<length(str);i++){
//         if(str[i]==symbol){
//             count++;
//         }
//     }
//     return count;
// }









//TASK 6
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }
// void printCaeser(char* str, int x){
//     for (int i=0;i<length(str);i++){
//         cout << (char)(str[i]+x);
//     }
// }
// int main(){
//     char a[50]="DaHuDoHu";
//     printCaeser(a,1);
//     return 0;
// }










//TASK 7
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }
// void printFence(char* str){
//     for (int i=0; i<length(str); i+=2){
//         cout << str[i] << " ";
//     }
//     for (int i=1; i<length(str); i+=2){
//         cout << str[i] << " ";
//     }
// }
// int main(){
//     char a[50]="DaHuDoHu";
//     printFence(a);
//     return 0;
// }








//TASK 8
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }
// bool isValid16(char* str){
//     if (str[0]==0){
//         return 0;
//     }
//     if ((str[0]<'1'||str[0]>'9')&&(str[0]<'A' || str[0]>'F')){
//         return 0;
//     }
//     if (!((str[0]<'1'||str[0]>'9')&&(str[0]<'A' || str[0]>'F'))){
//         for (int i=1; i<length(str); i++){
//             if((str[i]<'0' || str[i]>'9')  && (str[i]<'A' || str[i]>'F')) {
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }
// int convertFrom16To10(char* str){
//     int j=1;
//     int sum=0;
//     if (isValid16(str)){
//         for (int i=(length(str)-1);i>=0;i--){
//             int a=str[i];
//             if(str[i]=='A'){
//                 a=10;
//             }
//             if(str[i]=='B'){
//                 a=11;
//             }
//             if(str[i]=='C'){
//                 a=12;
//             }
//             if(str[i]=='D'){
//                 a=13;
//             }
//             if(str[i]=='E'){
//                 a=14;
//             }
//             if(str[i]=='F'){
//                 a=15;
//             }
//             if(str[i]=='1'){
//                 a=1;
//             }
//             if(str[i]=='2'){
//                 a=2;
//             }
//             if(str[i]=='3'){
//                 a=3;
//             }
//             if(str[i]=='4'){
//                 a=4;
//             }
//             if(str[i]=='5'){
//                 a=5;
//             }
//             if(str[i]=='6'){
//                 a=6;
//             }
//             if(str[i]=='7'){
//                 a=7;
//             }
//             if(str[i]=='8'){
//                 a=8;
//             }
//             if(str[i]=='9'){
//                 a=9;
//             }
//             sum += a*j;
//             j*=16;
//         }
//         return sum;
//     }
//     else return -1;
// }
// int main(){
//     char a[MaxSize]={"A1D2"};
//     cout << convertFrom16To10(a);
//     return 0;
// }









//TASK 9
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }
// bool hasSymbol(const char symbol, char* str){
//     for(int i=0;i<length(str);i++){
//         if(str[i]==symbol){
//             return 1;
//         }
//     }
//     return 0;
// }
// bool areSimpleAnagrams(char* a, char* b){
//     if(length(a)!=length(b)){
//         return 0;
//     }
//     for (int i=0;i<length(a);i++){
//             if(!(hasSymbol((a[i]),b))){
//                 return 0;
//         }
//     }
//     return 1;
// }






//TASK 9а
// int length(char* str){
//     int count=0;
//     for (int i=0; str[i]!='\0' ; i++){   
//         count++;
//     }
//     return count;
// }
// int numberOf(const char symbol, char* str){
//     int count=0;
//     for(int i=0;i<length(str);i++){
//         if(str[i]==symbol){
//             count++;
//         }
//     }
//     return count;
// }
// bool areSimpleAnagrams(char* a, char* b){
//     if(length(a)!=length(b)){
//         return 0;
//     }
//     for (int i=0;i<length(a);i++){
//             if(!(numberOf(a[i],b) == numberOf(a[i],a))){
//                 return 0;
//         }
//     }
//     return 1;
// }













//TASK 10
int length(char* str){
    int count=0;
    for (int i=0; str[i]!='\0' ; i++){   
        count++;
    }
    return count;
}
int main(){
    char duma[MaxSize];
    cin >> duma;
    int n;
    cin >> n;
    char str[MaxSize];
    n*=8;
    for (int i=0;i<n;i++){
        cin >> str[i];
    }
    int count=0;
    for (int i=0;i<length(str);i++){
        for(int j=0;j<length(duma);j++){
            if (count == length(duma)){
                break;
            }
            if (str[i]==duma[j]){
                count++;
                break;
            }else {
                count = 0;
                break;
            }
        }
    }
    if (count == length(duma)){
        cout << "da";
    }
    else {
        cout << "ne";
    }

    return 0;
}