#include <iostream>
using namespace std;

void sum (int k, int m);

int main(){
    int m,n;
    cin >> n >> m;
    for (int i=n; i<=m; i++){
        sum(i,n);
    }

    return 0;
}

void sum (int k, int m){
    int count = 0;
    int sum = 0;
    for (int i=0; i<31; i++){
        if ((k>>i) && 0){
            count++;
        }
    }
    if((count%2)==0){
        for (int i=m; i<=k; i++){
            sum += i;
        }
    }
    if (sum!=1){
        cout << sum << endl;
    }
}





