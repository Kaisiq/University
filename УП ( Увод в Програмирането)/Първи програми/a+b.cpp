#include <iostream>
using namespace std;

int main(){
    double a,b,c,d;
    cout << "Vuvedi a: ";
    cin >> a;
    cout << "Vivedu b: ";
    cin >> b;
    cout << "Vuvedi c: ";
    cin >> c;
    cout << "vuvedi d: ";
    cin >> d;
    cout << "a+b= " << a+b << endl;
    cout << "b*d= " << b*d << endl;
    cout << "(a+b)*d= " << (a+b)*d << endl;
    if ((a+b)*d < 0){
        cout << "win" << endl;
    }    
    if (d!=0){
        cout << "a/d= " << a/d << endl;
    }else {
        cout << "d=0 zatova ne delih a/d" << endl;
    }
    if (a!=0) {
        cout << "(c+d)/a= " << (c+d)/a << endl;
    } else{
        cout << "a=0 zatova ne izvurshih (c+d)/a";
    }
    return 0;

    
}