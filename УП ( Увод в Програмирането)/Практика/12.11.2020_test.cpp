#include <iostream>
using namespace std;

int main(){
    unsigned int m,n;
    cin >> m >> n;
    for (m; m<n; m++){
        for (int a=m; a<=n; a++){
            for (int b=m; b<=n; b++){
                for (int c=m; c<=n; c++){
                    if ((a+b)>c && (a+c>b) && (b+c)>a){
                        cout << '(' << a << ',' << b << ',' << c << ')' << endl;
                    }
                }
            }
        }
    }
}