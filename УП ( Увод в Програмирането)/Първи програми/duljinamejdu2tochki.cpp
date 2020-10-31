#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double a,b,c,d,e,f,vektor;
    cin >> a >> b;
    cout << endl;
    cin >> c >> d;
    e = a - c;
    f = b - d;
    vektor = sqrt(e*e+f*f);
    cout << vektor;
    return 0;

}