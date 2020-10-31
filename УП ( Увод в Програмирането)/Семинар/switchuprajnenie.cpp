#include <iostream>
using namespace std;


//TASK 1
// int main(){
//     int n;
//     cin >> n;
//     switch (n){
//         case 1: cout << "January"; break;
//         case 2: cout << "February"; break;
//         case 3: cout << "March"; break;
//         case 4: cout << "April"; break;
//         case 5: cout << "May"; break;
//         case 6: cout << "June"; break;
//         case 7: cout << "July"; break;
//         case 8: cout << "August"; break;
//         case 9: cout << "September"; break;
//         case 10: cout << "October"; break;
//         case 11: cout << "November"; break;
//         case 12: cout << "December"; break;
//         default: cout << "Molq vuvedi chislo 1-12";
//     }
//     return 0;
// }


//TASK 2
// int main(){
//     int n;
//     cin >> n;
//     switch (n){
//         case 1: cout << "I"; break;
//         case 2: cout << "II"; break;
//         case 3: cout << "III"; break;
//         case 4: cout << "IV"; break;
//         case 5: cout << "V"; break;
//         case 6: cout << "VI"; break;
//         case 7: cout << "VII"; break;
//         case 8: cout << "VIII"; break;
//         case 9: cout << "IX"; break;
//         case 10: cout << "X"; break;
//         default: cout << "Please enter number 1-10"; break;
//     }
//     return 0;
// }


//TASK 3
// int main(){
//     int n;
//     cin >> n;
//     n = n % 10;
//     switch (n){
//         case 0: cout << "0"; break;
//         case 1: cout << "1"; break;
//         case 2: cout << "4"; break;
//         case 3: cout << "9"; break;
//         case 4: cout << "6"; break;
//         case 5: cout << "5"; break;
//         case 6: cout << "6"; break;
//         case 7: cout << "9"; break;
//         case 8: cout << "4"; break;
//         case 9: cout << "1"; break;
//         default: cout << "enter a number.";
//     }
//     return 0;
// }


// TASK 4
// #include <cmath>
// int main(){
//     char sym;
//     int a;
//     cin >> sym;
//     do{
//         cin >> a;
//     } while (a<0);
//     switch (sym){
//         case 'S': cout << a*a; break;
//         case 'C': cout << a*a*3.14; break;
//         case 'R': cout << a*2*a; break;
//         case 'T': cout << (a+2*a)/2*a; break;
//         case '3': cout << sqrt(3)/2*a*a*1.0; break;
//         default : cout << "Molq vuvedi suotveten simvol";
//     }
//     return 0;
// }


//TASK 5
// #include <cmath>
// int main(){
//     char sym;
//     int a,b,r,h,c,p;
//     cin >> sym;
//     switch (sym){
//         case 'S': 
//             cin >> a;
//             if (a<0){
//                 cout << "nevalidno chislo";
//                 return 0;
//             }
//             cout << a*a; 
//             break;
//         case 'C': 
//             cin >> r;
//             if (r<0){
//                 cout << "nevalidno chislo";
//                 return 0;
//             }
//             cout << r*r*3.14; break;
//         case 'R': 
//             cin >> a >> b;
//             if (a<0 || b<0){
//                 cout << "nevalidno chislo";
//                 return 0;
//             }
//             cout << a*b; break;
//         case 'T': 
//             cin >> a >> b >> h;
//             if (a<0 || b<0 || h<0){
//                 cout << "nevalidno chislo";
//                 return 0;
//             }
//             cout << (a+b)/2*h; break;
//         case '3': 
//             cin >> a >> b >> c;
//             if (a<0 || b<0 || c<0){
//                 cout << "nevalidno chislo";
//                 return 0;
//             }
//             p = (a+b+c)/2;
//             cout << sqrt(p*(p-a)*(p-b)*(p-c)); break;
//         default: 
//             cout << "Molq vuvedi suotveten simvol";
//     }
//     return 0;
// }