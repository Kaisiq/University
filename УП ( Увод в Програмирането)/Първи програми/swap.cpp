#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    c = 0;
    cout << "enter first number: ";
    cin >> a;
    cout << endl << "enter second number: ";
    cin >> b;
    cout << endl;
    cout << "Swap Time!" << endl;
    c = b;
    b = a;
    a = c;
    cout << "first number is " << a << endl;
    cout << "second number is " << b << endl;
    
}