#include <iostream>
using namespace std;

int main(){
    int a;
    int i=1;
    int b=0;
    cout<<"do not enter " << b << ": ";
    cin>>a;
    while (a !=b ){
        b++;
        cout<<"do not enter " << b << ": ";
        cin>>a;
        i++;
        if (i>9){
            cout<<"nice job";
            return 0;
        }
    }
    cout << "haha you lost";
    return 0;
}