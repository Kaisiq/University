#include <iostream>
using namespace std;

int main(){
    int chas,min,sek;
    cin >> chas >> min >> sek;
    if ((chas>=14) && (min>=0) && (sek>=0)){
        cout << "zakusnqvash";
    }else {
        cout << "ne zakusnqvash";
    }
    
    return 0;
}