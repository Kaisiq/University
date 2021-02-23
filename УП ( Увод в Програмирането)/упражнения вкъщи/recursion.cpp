#include <iostream>
using namespace std;


int lexicograph(char* a, char* b){
    if(*a>*b){
        return 1;
    }
    if(*a<*b){
        return -1;
    }
    if(*a==*b){
        return lexicograph(a+1, b+1);
    }
}


int main(){
    char a[6]={"shiba"};
    char b[6]={"shibe"};
    cout << lexicograph(a,b);
    return 0;
}