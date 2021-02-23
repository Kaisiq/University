#include <iostream>
using namespace std;




void PrintNumbers(unsigned int n, unsigned int i=1){ 
    if(n>=16384){
        cout << "Too big number";
        return;
    }
    if(i>n){
        return;
    }

    unsigned int ncopy = n;

    for(int j=0; j<i; j++){
        cout << ncopy << " ";
        ncopy--;
    }

    cout << endl;
    PrintNumbers(n, i+1);
}



int main(){
    PrintNumbers(12);
    return 0;
}