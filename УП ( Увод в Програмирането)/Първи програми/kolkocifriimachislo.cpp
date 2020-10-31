#include <iostream>
using namespace std;

int main()
{
    long long n;
    int digits = 0;
    cin >> n;
    while (n>0){
        n/=10;
        digits++;
    }
    cout << digits;
return 0;
}