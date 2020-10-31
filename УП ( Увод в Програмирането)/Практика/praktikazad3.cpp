#include <iostream>
using namespace std;

int main(){
    int den;
    do{
        cin >> den;
    }while (den<0 || den>7);
    switch (den){
        case 2:
            cout << "4"; break;
        case 3:
            cout << "7"; break;
        case 4:
            cout << "8"; break;
        case 5:
            cout << "7"; break;
        default: 
            cout << "0";



    }
    
    return 0;
}