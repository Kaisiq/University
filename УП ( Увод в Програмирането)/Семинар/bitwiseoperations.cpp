#include <iostream>
using namespace std;

//TASK 1
// int main(){
//     int a,b;
//     cin >> a >> b;
//     cout << (a & b) << endl;
//     cout << (a | b) << endl;
//     cout << (a ^ b) << endl;
//     cout << (a << b) << endl;
//     cout << (a >> b) << endl;
//     return 0;
// }


//TASK 2
// int main(){
//     int a;
//     cin >> a;
//     a = (a>>2);
//     if (a%2 == 0){
//         cout << " 0";
//     }else {
//         cout << " 1";
//     }
//     return 0;
// }

//TASK 3
// int main(){
//     int n,m;
//     cin >> n >> m;
//     n = (n>>m);
//     if (n%2 == 0){
//         cout << "0";
//     }else {
//         cout << "1";
//     }
//     return 0;
// }

//TASK 4
// int main(){
//     int N;
//     cin >> N;
//     int n=1;
//     while (n<N){
//         n = (n << 1);
//     }
//     cout << n;
//     return 0;
// }

//TASK 5
// int main(){
//     int N;
//     cin >> N;
//     int count = 0;
//     while (N != 0){
//         if ((N % 2) != 0){
//             count += 1;
//         }
//         N = (N>>1);
//     }
//     cout << count;
//     return 0;
// }

//TASK 5a
// int main(){
//     int N;
//     cin >> N;
//     int count = 0;
//     for (int i=0; i<16; i++){
//         if ((N & (1<<i))){
//             count += 1;
//         }
//     }
//     cout << count;


//     return 0;
// }



//TASK 6
// int main(){
//     int N,M;
//     cin >> N;
//     M = ~N;
//     M += 1;
//     cout << M;

//     return 0;
// }


//TASK 7
// int main(){
//     int N,M,K;
//     cin >> N;
//     M = (N & 65535);
//     K = ~N;
//     M = (M & K);
//     cout << (N<<1);
    


//     return 0;
// }

// 00000...101
// 00000..1000



//TASK 8
// int main(){
//     int N;
//     cin >> N;
//     if (N & 1){
//         cout << "Слънчево е!\n";
//     }
//     if (N & (1<<2)){
//         cout << "Ветровито е!\n";
//     }
//     if (N & (1<<3)){
//         cout << "Вали дъжд!\n";
//     }
//     if (N & (1<<4)){
//         cout << "Вали сняг!\n";
//     }
//     if (N & (1<<5)){
//         cout << "Студено е!\n";
//     }
//     return 0;
// }