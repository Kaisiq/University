#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
    while (a !=5 ){
        cout<<"do not enter 5: ";
        cin>>a;
        int i=0;
        i++;
        if (i>9){
            cout<<"nice";
            return 0;
        }
    }
    return 0;
}