#include <iostream>
#include <cstring>
using namespace std;


//task 1

bool is_alpha(char a){
    return (a>='a' && a<='z')  ||  (a>='A' && a<='Z');
}






//task 2
bool is_digit(char a){
    return a>='0' && a<='9';
}


// int main(){
//     char a = '-';
//     cout << is_digit(a);
//     return 0;
// }






//task 3
void to_upper(char* a){
    int toUpperDiff = 'A' - 'a';
    for (int i=0; a[i]; i++){
        if(a[i]>='a' && a[i]<='z'){
            a[i] = a[i] + toUpperDiff;
        }
    }
}

// int main(){
//     char a[11] = "aASDsd234f";
//     to_upper(a);
//     cout << a;
//     return 0;
// }





//task 4
void change_sp_symbol(char* a, char c1, char c2){
    int length = strlen(a);
    for(int i=0; i<length; i++){
        if(a[i] == c1){
            a[i] = c2;
        }
    }
}

// int main(){
//     char s[] = "a*b*c*d";
//     char c1 = '*';
//     char c2 = '1';
//     change_sp_symbol(s, c1, c2);
//     int length = strlen(s);
//     for (int i=0; i<length; i++){
//         cout << s[i];
//     }
//     return 0;
// }





//task 5

void my_atoi (char* a){
    int result = 0;
    int length = strlen(a);
    int k=strlen(a)-1;
    for(int i=0; i<length; i++){
        int multiply = 1;
        for(int j=0; j<k; j++){
            multiply *= 10;
        }
        result += (a[i] - '0')*multiply; 
        k--;
    }
    cout << result;
}

// int main(){
//     char str[] = "1234";
//     my_atoi(str);
//     return 0;
// }








//task 6
void is_palindrome(char* a){
    int length = strlen(a);
    for(int i=0; i<(length/2)-1; i++){
        int j=length-1;
        if(a[i] != a[j]){
            cout << "no";
            return;
        }
        j++;
    }
    cout << "yes";

}

// int main(){
//     char str[] = "bacab";
//     is_palindrome(str);
//     return 0;
// }






//task 7

















//task 8

char* dynamic_concat(char* str1, char* str2){
    int length = strlen(str1)+ strlen(str2);
    char* result = new(nothrow) char[length+1];
    if(!result){
        return nullptr; 
    }
    strcat(result,str1);
    strcat(result,str2);
    return result;
}


// int main(){
//     char str[4] = "asd";
//     char str2[7] = "123123";
//     char* concat = dynamic_concat(str,str2);
//     if(!concat){
//         cout << "error";
//         return 1;
//     }
//     cout << concat;
//     delete[] concat;
//     return 0;
// }




//<---------------------------------------advanced tasks-------------------------------------------------__>

//task 1
// const char* dictionary[] = {"cats", "dogs"};

// int main(){
//     char str[256];
//     int count=0;
//     cin >> str;
//     if(strncmp(str,dictionary[1],strlen(dictionary[1]))){
//         count++;
//     }
//     if(strncmp(str,dictionary[0],strlen(dictionary[0]))){
//         count++;
//     }

//     cout << count;

//     return 0;
// }








//task 2

void removeElementByIndex(char** arr, int index, int len){
    for(int i=index; i<len-1; i++){
        arr[i] = arr[i+1];
    }
    arr[len-1] = 0;
}


int main(){
    char* str = new(nothrow) char[256];

    cin.getline(str,256);
    const unsigned int len = strlen(str);
    int countWords = 0;

    for(int i=0; i<len;i++){
        if(str[i] == ' '){
            countWords++;
        }
    }
    const int words = countWords;

    char** wordsArr = new(nothrow) char*[words];
    int count=0;
    int k=0;
    int element=0;

    while(k<=len){
        count = 0;
        while(str[count+k]!=' '){
            count++;
        }
        char* currentWord = new(nothrow) char[count];
        for(int j=0; j<count; j++){
            currentWord[j] = str[k+j];
        }
        wordsArr[element] = currentWord; 
        delete[] currentWord;
        k+=count+1;
        element++;
    }

    for(int i=0; i<countWords; i++){
        int random = rand()%(countWords-i);
        if(countWords-i == 2){
            cout << wordsArr[1] << " ";
        }
        else if(countWords-i == 1){
            cout << wordsArr[0] << " ";
        }
        else{
            cout << wordsArr[random] << " ";
            removeElementByIndex(wordsArr,random,element+1);
        }
    }

    return 0;
}