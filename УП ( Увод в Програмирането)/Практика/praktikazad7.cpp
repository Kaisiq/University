#include <iostream>
using namespace std;

int main(){
    long long n,b;
    cin >> n;
    b=n;
    for (int i=31; i>=0; i--){
        n=b;
        n = n>>i;
        if(n%2 == 0){
        cout << "0";
        }else cout << "1";
        if (i%8 == 0){
            cout << " ";
        }
    }

    
    return 0;
}