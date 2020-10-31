#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 0;
    for (int i=0; i<=n; i++){
        if (i%5 == 0){
            sum += 2*i;
        }else {
            sum += i+2;
        }
    }
    cout << sum;
    
    return 0;
}