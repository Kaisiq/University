#include <iostream>
using namespace std;

//TASK 1
// int main(){
//     int a,b,c;
//     cin >> a >> b >> c;
//     if ((a>=b) && (b>=c)){
//         cout << a << b << c;
//     }else if ((a>=c) && (c>=b)){
//         cout << a << c << b;
//     }else if ((b>=a) && (a>=c)){
//         cout << b << a << c;
//     }else if ((b>=c) && (c>=a)){
//         cout << b << c << a;
//     }else if ((c>=a) && (a>=b)){
//         cout << c << a << b;
//     }else {
//         cout << c << b << a;
//     }
    
//     return 0;
// }


//TASK 2
// #include <iostream>
// using namespace std;

// int main(){
//     int chas,min,sek;
//     cin >> chas >> min >> sek;
//     if ((chas>=14) && (min>=0) && (sek>=0)){
//         cout << "zakusnqvash";
//     }else {
//         cout << "ne zakusnqvash";
//     }
    
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main(){
//     int den;
//     do{
//         cin >> den;
//     }while (den<0 || den>7);
//     switch (den){
//         case 2:
//             cout << "4"; break;
//         case 3:
//             cout << "7"; break;
//         case 4:
//             cout << "8"; break;
//         case 5:
//             cout << "7"; break;
//         default: 
//             cout << "0";
//     }
//     return 0;
// }


//TASK 4
// #include <iostream>
// using namespace std;

// int main(){
//     int a,b;
//     cin >> a >> b;
//     for (a; a<b; a++){
//         if (a%2 == 1){
//             cout << a << " ";
//         }
//     }
    
//     return 0;
// }


//TASK 5
// #include <iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int sum = 0;
//     for (int i=0; i<=n; i++){
//         if (i%5 == 0){
//             sum += 2*i;
//         }else {
//             sum += i+2;
//         }
//     }
//     cout << sum;
    
//     return 0;
// }


//TASK 6
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
//TASK 6 2
// #include <iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int fn = 0;
//     int f1 = 0;
//     int f2 = 1;
//     for (int i=0; i<=n; i++){
//         if (i<=1){
//             fn = 0;
//         }else{
//             fn = f1 + f2;
//             f2 = f1;
//             f1 = fn;
//         }

//     }
//     cout << fn;
 
//     return 0;
// }


//TASK 7
// #include <iostream>
// using namespace std;

// int main(){
//     long long n,b;
//     cin >> n;
//     b=n;
//     for (int i=31; i>=0; i--){
//         n=b;
//         n = n>>i;
//         if(n%2 == 0){
//         cout << "0";
//         }else cout << "1";
//         if (i%8 == 0){
//             cout << " ";
//         }
//     }

    
//     return 0;
// }



//TASK 8
//00000000 00000001
//00000001 00000000
// int main(){
//     int n,a,b;
//     cin >> n;
//     a = n>>8;
//     b = n<<8;
//     n = a+b;
//     cout << n;
//     return 0;
// }





//TASK 9
// int main(){
//     int n,a;
//     int sum=0;
//     int del=0;
//     cin >> n;
//     for (int i=0; i<n; i++){
//         cin >> a;
//         sum += a;
//         del++;
//     }
//     cout << sum/del;
//     return 0;
// }



//TASK 10
//1101 1011
//1110 0111
//1111 0000
//1111 0100
// int main(){
//     int n,a,b,c;
//     cin >> n;
//     a = n>>4;
//     for (int i=0; i<4; i++){
//         c = ((a>>i)&1)<<(4-i);
//     }
//     b = n-240;
//     if (c & b){
//         cout << "true";
//     }else cout << "false";
//     return 0;
// }



//TASK 11
// int main(){
//     int A,A1;
//     int a1,a2,a3;
//     cin >> A;
//     do{cin >>a1;}
//     while (a1<0 || a1>31);
//     do{cin >>a2;}
//     while (a2<0 || a2>31);
//     do{cin >>a1;}
//     while (a3<0 || a3>31);
//     a1 = (a1<<12);
//     a2 = (a2<<8);
//     a3 = (a3<<4);
//     A1 = A - (a1 + a2 + a3);
//     cout << A1;
//     return 0;
// }



//TASK 12
// int main(){
//     long long n;
//     int max=0;
//     int count=0;
//     cin >> n;
//     for(int i=0; i<32; i++){

//         if (n & (1<<i)){
//             count++;
//             if(max<count){
//                 max = count;
//             }
//         }else {
//             count =0;
//         }
//     }
//     cout << max;
//     return 0;
// }



//TASK 13

// int main(){
//     int egn;
//     cin >> egn;
//     int egn1,egn2,egn3,egn4,egn5,egn6,egn7,egn8,egn9,egn10;
//     egn10 = egn%10;
//     egn9 = egn/10%10;
//     egn8 = egn/100%10;
//     egn7 = egn/1000%10;
//     egn6 = egn/10000%10;
//     egn5 = egn/100000%10;
//     egn4 = egn/1000000%10;
//     egn3 = egn/10000000%10;
//     egn2 = egn/100000000%10;
//     egn1 = egn/1000000000;
//     if(egn3==4){
//         cout << "godina na rajdane: " << 20 << egn1 << egn2;
//     }else if (egn3==2){
//         cout << "godina na rajdane: " << 19 << egn1 << egn2;
//     }


//     return 0;
// }




