//Цикли задачки
#include <iostream>
using namespace std; 


//TASK 1
// int main(){
//     int a = 5;
//     int counter = 0;
//     while (counter<5){
//         counter++;
//         cout << "*";
//     }
//     for (int i=0; i<5; i++){
//         cout << "*";
//     }
//     return 0;
// }

//TASK 2
// int main(){
//     int n;
//     int counter = 0;
//     cin >> n;
//     while (counter<n){
//         counter++;
//         cout << "*";
//     }
//     int m;
//     cin >> m;
//     for (int i=0; i<m;i++){
//         cout << "*";
//     }
//     return 0;
// }


//TASK 3
// int main(){
//     int n;
//     cin >> n;
//     int counter = 0;
//     int factoriel = 1;
//     while (counter<n){
//         counter++;
//         factoriel = factoriel * counter;
//     }
//     cout << factoriel << endl;

//     int factorielfor = 1;
//     for (int i=1 ; i<=n ; i++){
//         factorielfor = factorielfor * i;
//     }
//     cout << factorielfor; 
//     return 0;
// }


//TASK 4
// int main(){
//     int zero = 10;
//     while (zero<100){
//         cout << zero << endl;
//         zero++;
//     }

//     for (int i=10 ; i<100 ; i++){
//         cout << i << endl;
//     }
//     return 0;
// }


//TASK 5
// int main(){
//     int a = 10;
//     while (a<100){
//         if(a%5==0){
//             cout << a << endl;
//         }
//         a++;
//     }
//     for (int i=10; i<100; i++){
//         if (i%5==0){
//             cout << i << endl;
//         }
//     }
//     return 0;
// }


//TASK 6
// int main(){
//     int a=10;
//     while (a<100){
//         int desetici = a/10;
//         int edinici = a%10;
//         if (a%(edinici+desetici)==0){
//             cout << a << endl;
//         }
//         a++;
//     }
//     for (int i=10;i<100;i++)
//     {
//         int desetici = i/10;
//         int edinici = i%10;
//         if(i%(edinici+desetici)==0){
//             cout << i << endl;
//         }
//     }
//     return 0;
// }


//TASK 7
// int main(){
//     int n;
//     int sum = 0;
//     cin >> n;
//     int counter = 0;
//     while (counter<=n){
//         cout << counter << endl; 
//         sum = sum + counter;
//         counter++;
//     }
//     cout << sum << endl;
//     int sum2 = 0;
//     for (int i=0;i<=n;i++)
//     {
//         cout << i << endl;
//         sum2 = sum2 + i;
//     }
//     cout << sum2 << endl;
//     return 0;
// }


//TASk 8
// int main(){
//     int n;
//     int big = 0;
//     cin >> n;
//     int counter = 1;
//     while (counter<=n){
//         cout << counter << endl; 
//         if (counter>big){
//             big = counter;
//         }
//         counter++;
//     }
//     cout << big << endl;
//     int big2 = 0;
//     for (int i=1;i<=n;i++)
//     {
//         cout << i << endl;
//         if (i>big2){
//             big2=i;
//         }
//     }
//     cout << big2 << endl;
//     return 0;
// }


//TASK 9
// int main(){
//     int n;
//     cin >> n;
//     int counter = 0;
//     while (counter<n){
//         cout << counter << endl;
//         if (counter%8==0){
//             cout << "chisloto " << counter << " se deli na 8\n";
//         }
//         counter++;
//     }
//     cout << endl;
//     for (int i=0; i<n; i++){
//         cout << i << endl;
//         if (i % 8 == 0){
//             cout << "chisloto " << i << " se deli na 8\n";
//         }
//     }
//     return 0;
// }


//TASK 10
// int main(){
//     int n;
//     cin >> n;
//     int counter = 0;
//     int c = 0;
//     while (counter<n){
//         cout << counter << endl;
//         if (counter % 8 == 0){
//             c++;
//         }
//         counter++;
//     }
//     cout << c << " chisla se delqt na 8" << endl;
//     int d = 0;
//     for (int i=0; i<n; i++){
//         cout << i << endl;
//         if (i % 8 == 0){
//             d++;
//         }
//     }
//     cout << d << " chisla se delqt na 8" << endl;
//     return 0;
// }


//TASK 11
// int main(){
//     int n = 0;
//     cin >> n;
//     int counter = 0;
//     int big = 0;
//     while (counter < n){
//         cout << counter << endl;
//         if ((counter > big) && (counter % 2 == 0)){
//             big = counter;
//         }
//         counter++;
//     }
//     cout << big << endl;
// }


//TASK 12
// int main(){
//     int n;
//     cin >> n;
//     bool a;
//     int c = 0;  //kolko puti sme uspqli da delim chisloto na nqkoe
//     for (int i=2 ; i<=n ; i++)
//     {
//         a = n%i;
//         if (a == 0){
//             c++;
//         }
//     }
//     if (c > 1){ //ako sme razdelili chisloto na drugo osven na sebe si (ne mojem na edno, tui kato zapochvame s i=2)
//         cout << "chisloto ne e prosto";
//     }
//     else {
//         cout << "chisloto e prosto";
//     }
//     return 0;
// }


//TASK 13
// int main()
// {
//     long long n;
//     int digits = 0;
//     long long m;

//     cin >> n;
//     m = n;
//     while (n>0){
//         n /= 10;
//         digits++;
//     }

//     digits /= 2;
//     //trqbva mi masiv, ne moga da q resha zasega

//     return 0;
// }


//TASK 14
// int main(){
//     long long n;
//     int sbor = 0;
//     cin >> n;
//     while (n>0){
//         sbor = sbor + n % 10;
//         n/=10;
//     }
//     cout << sbor;
// }


//TASK 15
// int main()
// {
//     int n;
//     int sborocenki = 0;
//     int broiocenki = 0;
//     double sredno = 0;
//     cout << "vuvedi ocenka: ";
//     cin >> n;
//     while (n>=2 && n<=6)
//     {
//         sborocenki += n;
//         broiocenki++;
//         sredno = sborocenki / broiocenki;
//         cout << "sredno :"<< sredno;
//         cout << "\nVuvedi ocenka: ";
//         cin >> n;
//     }
//     return 0;
// }


//TASK 16
// int main(){
//     for(int i=0; i<9; i++){
//         for (int i=0; i<6; i++){
//             cout <<"*";
//         }
//         cout << "\n";
//     }
//     return 0;
// }