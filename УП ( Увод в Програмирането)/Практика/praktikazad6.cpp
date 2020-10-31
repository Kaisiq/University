// #include <iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int nechetno = 0;
//     int chetno = 1;
//     for (int i=2; i<=n; i++){
//         if (i % 2 == 0){
//             chetno += nechetno;
//         }
//         else {
//             nechetno += chetno;
//         }
//     }
//     if (chetno>nechetno){
//         cout << chetno;
//     }
//     else {
//         cout << nechetno;
//     }
    
//     return 0;
// }
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int fn = 0;
    int f1 = 0;
    int f2 = 1;
    for (int i=0; i<=n; i++){
        if (i<=1){
            fn = 0;
        }else{
            fn = f1 + f2;
            f2 = f1;
            f1 = fn;
        }

    }
    cout << fn;
 
    return 0;
}