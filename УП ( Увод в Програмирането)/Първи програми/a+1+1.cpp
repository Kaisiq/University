#include <iostream>
using namespace std;

int main(){
    int a;
    int b = 0;
    cout << "enter a number: ";
    cin >> a;
    cout << endl;
    cout << "Your number: " << a << endl;
    for (int i=a ; i<100 ; i++){
        a++;
        b++;
        cout << "Your number + " << b << " = " << a << endl;
    }
    return 0;
}