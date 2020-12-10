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






//TASK 3
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
// int main(){
//     long long n,b;
//     cin >> n;
//     b=n;
//     for (int i=31; i>=0; i--){
//         n=b;
//         n = n>>i;
//         if((n&1) == 0){
//         cout << "0";
//         }
//         else cout << "1";
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
//     a = n&255;
//     b = n&(255<<8);
//     a = a <<8;
//     b = b >>8;
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
//     do{
//     cin >>a1;
//     }while ((a1<0) || (a1>31));
//     do{
//     cin >>a2;
//     }while ((a2<0) || (a2>31));
//     do{
//     cin >>a3;
//     }while ((a3<0) || (a3>31));

//     A1= A | (1<<(a1));
//     A1= A1 | (1<<(a2));
//     A1= A1 | (1<<(a3));

//     cout << A1;
//     return 0;
// }







//TASK 12
// int main(){
//     unsigned int n;
//     int max=0;
//     int count=0;
//     cin >> n;
//     for(int i=0; i<32; i++){

//         if (n & (1<<i)){
//             count++;
//         }else {
//             if(max<count){
//                 max = count;
//             }
//             count =0;
//         }
//     }
//     if(max<count){
//         max = count;
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
//     if(egn3==4 || egn3==5){
//         cout << "godina na rajdane: " << 20 << egn1 << egn2 << endl;
//     }else if (egn3==2 || egn3==3){
//         cout << "godina na rajdane: " << 19 << egn1 << egn2 << endl;
//     }
//     if (egn3 == 4 || egn3 == 2){
//     cout << "mesec na rajdane: 0" <<  egn4 << endl;
//     } 
//     else if (egn3 == 5 || egn3 == 3){
//     cout << "mesec na rajdane: 1" <<  egn4 << endl;
//     }
//     cout << "den na rajdane: " << egn5 << egn6 << endl;
//     int egn789 = (egn7*100)+(egn8*10)+egn9;
//     if (egn789>=0 && egn789 <= 43){
//         cout << "grad na rajdane: Blagoevgrad" << endl;
//     }
//     if (egn789>=44 && egn789 <= 93){
//         cout << "grad na rajdane: Burgas"  << endl;
//     }
//     if (egn789>=94 && egn789 <= 139){
//         cout << "grad na rajdane: Varna" << endl;
//     }
//     if (egn789>=140 && egn789 <= 169){
//         cout << "grad na rajdane: Veliko Turnovo" << endl;
//     }
//     if (egn789>=170 && egn789 <= 183){
//         cout << "grad na rajdane: Vidin" << endl;
//     }
//     if (egn789>=184 && egn789 <= 217){
//         cout << "grad na rajdane: Vraca" << endl;
//     }
//     if (egn789>=218 && egn789 <= 233){
//         cout << "grad na rajdane: Gabrovo" << endl;
//     }
//     if (egn789>=234  && egn789 <= 281){
//         cout << "grad na rajdane: Kurdjali" << endl;
//     }
//     if (egn789>=282 && egn789 <= 301){
//         cout << "grad na rajdane: Kiustendil" << endl;
//     }
//     if (egn789>=301 && egn789 <= 319){
//         cout << "grad na rajdane: Lovech" << endl;
//     }
//     if (egn789>=320 && egn789 <= 341){
//         cout << "grad na rajdane: Montana" << endl;
//     }
//     if (egn789>=342 && egn789 <= 377){
//         cout << "grad na rajdane: Pazardjik" << endl;
//     }
//     if (egn789>=378 && egn789 <= 395){
//         cout << "grad na rajdane: Pernik" << endl;
//     }
//     if (egn789>=396 && egn789 <= 435){
//         cout << "grad na rajdane: Pleven" << endl;
//     }
//     if (egn789>=436 && egn789 <= 501){
//         cout << "grad na rajdane: Plovdiv" << endl;
//     }
//     if (egn789>=502 && egn789 <= 527){
//         cout << "grad na rajdane: Razgrad" << endl;
//     }
//     if (egn789>=528 && egn789 <= 555){
//         cout << "grad na rajdane: Ruse" << endl;
//     }
//     if (egn789>=556 && egn789 <= 575){
//         cout << "grad na rajdane: Silistra" << endl;
//     }
//     if (egn789>=576 && egn789 <= 601){
//         cout << "grad na rajdane: Sliven" << endl;
//     }
//     if (egn789>=602 && egn789 <= 623){
//         cout << "grad na rajdane: Smolqn" << endl;
//     }
//     if (egn789>=624 && egn789 <= 721){
//         cout << "grad na rajdane: Sofia grad" << endl;
//     }
//     if (egn789>=722 && egn789 <= 751){
//         cout << "grad na rajdane: Sofia okrug" << endl;
//     }
//     if (egn789>=752 && egn789 <= 789){
//         cout << "grad na rajdane: Stara Zagora" << endl;
//     }
//     if (egn789>=790 && egn789 <= 821){
//         cout << "grad na rajdane: Dobrich" << endl;
//     }
//     if (egn789>=822 && egn789 <= 843){
//         cout << "grad na rajdane: Turgovishte" << endl;
//     }
//     if (egn789>=844 && egn789 <= 871){
//         cout << "grad na rajdane: Haskovo" << endl;
//     }
//     if (egn789>=872 && egn789 <= 903){
//         cout << "grad na rajdane: Shumen" << endl;
//     }
//     if (egn789>=904 && egn789 <= 925){
//         cout << "grad na rajdane: Yambol" << endl;
//     }
//     if (egn789>=926 && egn789 <= 999){
//         cout << "grad na rajdane: Drug/Neizvesten" << endl;
//     }
//     if (egn9%2 == 0){
//         cout << "pol: muj" << endl;
//     } else{
//         cout << "pol: jena" << endl;
//     }
//     return 0;
// }




//TASK 14
// int main(){
//     int n,m;
//     cin >> n >> m;
//     for (int i=0; i<n ;i++){
//         cout << "*";
//     }
//     cout << endl;
//     for (int i=0; i<(m-2); i++){
//         cout << "*";
//         for (int j=0; j<(n-2); j++){
//             cout << " ";
//         }
//         cout << "*" << endl;
//     }
//     for (int i=0; i<n ;i++){
//         cout << "*";
//     }
//     return 0;
// }





//TASK 15
// int main() {
//     int n,count=0;
//     cin >> n;
//     for (int i=2; i<n; i++){
//         if (n%i==0){
//             count++;
//         }
//     }
//     if (count == 0){
//         cout << "prime";
//     } else {
//         cout << "compose";
//     }
//     return 0;
// }