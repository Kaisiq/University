#include <iostream>
using namespace std;




//TASK 1
// void sum(int n){
//     int sum=0,b;
//     for (int i=0; i<n; i++){
//         cin >> b;
//         sum += b;
//     }
//     cout << sum;
// }
// int main(){
//     int n;
//     cin >> n;
//     sum(n);
//     return 0;
// }






//TASK 2
// bool isPrime(int n){
//     for (int i=2; i<=n/2; i++){
//         if(n%i==0){
//             return 0;
//         }
//     }
//     return 1;
// }


// int main(){
//     int a,b,sum=0;
//     cin >> a >> b;
//     for (a; a<=b; a++){
//         if (isPrime(a)){
//             sum += a;
//         }
//     }
//     cout << sum;
// }



//TASK 3
// int main(){
//     for (int i=100; i<=999; i++){
//         if ((i%10 != i/10%10) && (i%10!=i/100)  &&  (i/10%10) != (i/100)) {
//             cout << i << " ";
//         }
//     }
//     return 0;
// }




//TASK 4
// int pow (int a, int n);
// int main(){
//     int n,sum=0;
//     cin >> n;
//     for (int i=1; i<=n; i++){
//         sum += pow(i,i);
//     }
//     cout << sum;
// }

// int pow (int a, int n){
//     int sum = 1;
//     for (int i=0; i<n ; i++){
//         sum *= a;
//     }
//     return sum;
// }
//1 + 4 + 27





//TASK 5
// int vdignatiBitove(int a);
// int main(){
//     int m,n,sum=0;
//     cin >> m >> n;
//     for (int i=m ; i<=n ; i++){
//         sum += vdignatiBitove(i);
//     }
//     cout << sum;
//     return 0;
// }


// int vdignatiBitove(int a){
//     int sum = 0;
//     for (int i=0; i<31; i++){
//         if (a&(1<<i)){
//             sum += 1;
//         }
//     }
//     return sum;
// }









//ТASK 6 

// int main(){
//     int m,n;
//     cin >> m >> n;
//         for (m; m <= n; m++){
//             for (int a=m; a <= n; a++){
//                 for (int b=m; b <= n; b++){
//                     for (int c=m; c <= n; c++){
//                         if ((a!=b) && (a!=c) && (b!=c)){
//                             cout << '(' << a << ',' << b << ',' << c << ')' << endl;
//                         }
//                     }
//                 }
//             }
//         }
//     return 0;
// }












// TASK 7
// bool issquare(int n){
//     for (int i=1; i<n; i++){
//         if ((i*i) == n){
//             return 1;
//         }
//     }
//     return 0;
// }

// int startnumber(int n){
//     int number = 1;
//     for (int i=1;i<n;i++){
//         number = number * 10;
//     }
//     return number;
// }

// int endnumber(int n){
//     int endnumber = 9;
//     for (int i=1; i<n; i++){
//         endnumber = endnumber*10 + 9;
//     }
//     return endnumber;
// }

// int main(){
//     int n;
//     cin >> n;
//     int startnumb = startnumber(n);
//     int endnumb = endnumber(n);
//     for (startnumb; startnumb<=endnumb; startnumb++){
//         if(issquare(startnumb)){
//             if(startnumb%2 == 0){
//                 cout << startnumb << endl;
//             }
//         }
//     }
//     return 0;
// }














//TASK 8     ???????????????????//
int del(int n){
    int del = 1;
    for (int i=1; i<n ; i++){
        del*=10;
    }
    return del;
}

int cifrivchislo(int n){
    int count = 1;
    if (n=0){
        count = 1;
        return count;
    }
    while (n>0){
        n/=10;
        count++;
    }
    return count;
}

bool isavtomorfic(int a){
    int a2= a*a;
    int cifriVA = cifrivchislo(a);
    int delitel = del(cifriVA);
    int a3 = a2 % delitel;
    return (a&a3);
}

int main(){
    int count = 1;
    while (count <= 5){
        for (int i=1;;i++){
            if (isavtomorfic(i)){
                cout << i << endl;
                break;
            }
        }
        count ++;
    }
    return 0;
}