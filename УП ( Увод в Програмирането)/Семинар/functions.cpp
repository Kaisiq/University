#include <iostream>
using namespace std;



//TASK 1
// void print(){
//     cout << 1;
// }

// int main(){
//     print();
//     return 0;
// }








//TASK 2
// void print(int n){
//     cout << n;
// }

// int main(){
//     print(2);
//     return 0;
// }






//TASK 3
// int read(int n){
//     cin >> n;
//     return n;
// }

// int main(){
//     int a;
//     read(a);
//     return 0;
// }





//TASK 4
// int read(int n){
//     cin >> n;
//     return n;
// }

// int main(){
//     int a;
//     cout << read(a);
//     return 0;
// }





//TASK 5
// bool chetno (int n){
//     return !(n%2);
// }






//TASK 6
// bool nechetno (int n){
//     return (n%2);
// }






//TASK 7
// bool chetno (int n){
//     return !(n%2);
// }

// int main(){
//     int a;
//     cin >> a;
//     cout << chetno(a);
// }






//TASK 8
// bool nechetno (int n){
//     return (n%2);
// }

// int main(){
//     int a;
//     cin >> a;
//     cout << nechetno(a);
// }






//TASK 9    nedovurshena
// bool palindrom (int n){
//     int obr = 0;
//     while (n > 0){
//         obr = obr*10 + (n%10);
//         n/=10;
//     }
//     return (n==obr); 
// }
// int main(){
//     int a;
//     cin >> a;
//     cout << palindrom(a);
// }






//TASK 10
// int sledvashtastepenna2(int n){
//     int a = 0;
//     for (int i=31; i>=0; i--){
//         if ((1<<i)&n){
//             a = 1<<(i+1);
//             break;
//         }
//     }
//     return a;
// }






//TASK 11
// int minalastepenna2(int n){
//     int a = 0;
//     for (int i=31; i>=0; i--){
//         if ((1<<i)&n){
//             a = 1<<(i);
//             break;
//         }
//     }
//     return a;
// }






//TASK 12
// int naiblizkastepenna2(int n){
//     int a = 0;
//     int b = 0;
//     for (int i=31; i>=0; i--){
//         if ((1<<i)&n){
//             a = 1<<(i);
//             b = 1<<(i+1);
//             break;
//         }
//     }
//     if ((n-a)>(b-n)){
//         return b;
//     }
//     else {
//         return a;
//     }
// }






//TASK 13
// bool visokosna(int n){
//     if(n%400==0){
//         return 1;
//     }else if ((n%100!=0)&& (n%4==0)){
//         return 1;
//     }else {
//         return 0;
//     }
// }







//TASK 14
// bool isValidDate(int den, int mesec, int godina){
//     if ((den>=1&&den<=31)&&(mesec>=1&&mesec<=12) && (godina>=1)){
//         return 1;
//     }else return 0;
// }







//TASK 15
// bool isValidInput (int den, int mesec, int godina){
//     if (den<1 || den > 31){
//         cout << "anus";
//         return 0;
//     }
//     else if (mesec < 1 || mesec > 12){
//         cout << "anus";
//         return 0;
//     }
//     else if (godina < 0 || godina > 9999){
//         cout << "anus";
//         return 0;
//     }
//     else {
//         return 1;
//     }
// }


// void nextdate(int a, int b, int c){
//     if (a < 28){
//         cout << a+1 << "." <<  b << "." << c;
//     }
//     switch (b){
//         case 1: 
//         case 3:
//         case 5:
//         case 7:
//         case 8:
//         case 10:
//         case 12:
//             if (a<31){
//                 a++;
//             }
//             else {
//                 if (b == 12){
//                     a = 1;
//                     b = 1;
//                     c++;
//                 }else{
//                     a = 1;
//                     b++;
//                 }
//             }
//             break;
//         case 2:
//             if ((c%400==0) || ((c%100 != 0) && (c%4 == 0))){
//                 if (a==29){
//                     a = 1;
//                     b++;
//                 } else {
//                     a++;
//                 }
//             }
//             else {
//                 if (a==28){
//                     a = 1;
//                     b++;
//                 }
//             }
//             break;
//         case 4:
//         case 6:
//         case 9:
//         case 11:
//             if (a<30){
//                 a++;
//             }
//             else {
//                 a = 1;
//                 b++;
//             }
//             break;
//     }
//     cout << a << "." << b << "." << c;
// }

// int main(){
//     int den, mesec, godina;
//     char a;
//     cin >> den >> a >> mesec >> a >> godina;
//     if (isValidInput (den, mesec, godina) == 0){
//         return 0;
//     }else {
//         nextdate(den, mesec, godina);
//     }
//     return 0;
// }








//TASK 16
// bool isPrime(int n){
//     for (int i=2; i<n; i++){
//         if(n%i==0){
//             return 0;
//         }
//     }
//     return 1;
// }









//TASK 17
// bool isPrime(int n){
//     for (int i=2; i<n; i++){
//         if(n%i==0){
//             return 0;
//         }
//     }
//     return 1;
// }



// bool isCubePrime(int n){
//     if (!isPrime(n)){
//         return 0;
//     }
//     if (isPrime(n)){
//         for (int i=1; i<n; i++){
//             if (((i*i*i)-(i-1)*(i-1)*(i-1))==n){
//                 return 1;
//             }
//         }
//         return 0;
//     }

// }









//TASK 18
// void licenakvadrat(int Ax, int Bx, int Ay, int By){
//     if ((Ax-Bx)*(Ay-By) > 0){
//         cout << ((Ax-Bx)*(Ay-By));
//     }else if ((Ax-Bx)*(Ay-By) < 0){
//         cout << -((Ax-Bx)*(Ay-By));
//     }
// }

// int main(){
//     int ax,bx,ay,by;
//     cin >> ax >> bx >> ay >> by;
//     licenakvadrat(ax,bx,ay,by);
//     return 0;
// }





//TASK 19
// int NOD (int a, int b){
//     for (int i=a*b; i>0; i--){
//         if((a%i==0) && (b%i==0)){
//             return i;
//         }
//     }
//     return 0;
// }





//TASK 20
// int NOK (int a, int b){
//     for (int i=1; i<=a*b; i++){
//         if((i%a==0) && (i%b==0)){
//             return i;
//         }
//     }
//     return 0;
// }


// int main (){
//     int a,b;
//     cin >> a >> b;
//     cout << NOK(a,b);
//     return 0;
// }













//TASK 21
// void srednoaritm (int n){
//     int sum = 0;
//     int del = -1;
//     int art;
//     do {
//         cin >> n;
//         sum += n;
//         del++;
//     }
//     while (n!=0);
//     art = sum/del;
//     cout << art;
// }









//TASK 22
// int naimalko (int n){
//     int naimalko = n;
//     while (n != 0) {
//         if (n==0){
//             return naimalko;
//         }
//         if (naimalko > n){
//             naimalko = n;
//         }
//         cin >> n;
//     }
//     return naimalko;
// }













//TASK 23
// int naigolqmo (int n){
//     int naigolqmo = n;
//     while (n != 0) {
//         if (n==0){
//             return naigolqmo;
//         }
//         if (naigolqmo < n){
//             naigolqmo = n;
//         }
//         cin >> n;
//     }
//     return naigolqmo;
// }











//TASK 24
// bool isPrime(int n){
//     for (int i=2; i<n; i++){
//         if(n%i==0){
//             return 0;
//         }
//     }
//     return 1;
// }
// int srednoaritmetichnonaprosti (int n){
//     int sum = 0;
//     int del = 0;
//     while (n != 0){
//         if (isPrime(n)){
//             sum += n;
//             del++;
//         }
//         cin >> n;
//     }
//     return sum/del;
// }

// int main(){
//     int a;
//     cin >> a;
//     cout << srednoaritmetichnonaprosti(a);
//     return 0;
// }





//TASK 25
// int naigolqmochetno (int n){
//     int naigolqmo = 0;
//     if (n%2==0){
//         int naigolqmo = n;
//     }
//     while (n != 0) {
//         if (n==0){
//             return naigolqmo;
//         }
//         if ((naigolqmo < n) && (n%2==0)){
//             naigolqmo = n;
//         }
//         cin >> n;
//     }
//     return naigolqmo;
// }
// int main(){
//     int a;
//     cin >> a;
//     cout << naigolqmochetno(a);
//     return 0;
// }







//TASK 26
// int fibonacci(int n){
//     int F1=0;
//     int F2=1;
//     int Fn=0;
//     if (n==2){
//         return 1;
//     }
//     for (int i=2; i<n; i++){
//         Fn = F2 + F1;
//         F1= F2;
//         F2 = Fn;
//     }
//     return Fn;
// }










//TASK 27
// int nfactoriel(int n){
//     int sum = 1;
//     for (int i=0; i<n; i++){
//         sum *= (n-i);
//     }
//     return sum;
// }







//TASK 28     nedovurshena
// bool isPrime(int n){
//     for (int i=2; i<n; i++){
//         if(n%i==0){
//             return 0;
//         }
//     }
//     return 1;
// }
// int Oiler(int n){
//     int Oilern = 0;
//     for (int i=0; i<n; i++){
//         if (isPrime(i)){
//             Oilern++;
//         }
//     }
//     return Oilern;
// }
// int main(){
//     int a;
//     cin >> a;
//     cout << Oiler(a);
//     return 0;
// }








//TASK 29
// int broichisla (int n){
//     if (n==0){
//         return 1;
//     }
//     int broichisla = 0;
//     while (n > 0){
//         broichisla++;
//         n /= 10;
//     }
//     return broichisla;
// }
// int power(int a, int b){
//     int result = 1;
//   for (int i = 0; i < b; i++) {
//     result = result * a;
//   }
//   return result;
// }


// bool isMunheizen (int n){
//     int sum;
//     int n2 = n;
//     for (int i=0; i<broichisla(n); i++){
//         int poslednacifra = n2%10;
//         sum += power(poslednacifra, poslednacifra);
//         n2/=10;
//     }
//     return (n==sum);
// }

// int main(){
//     int a;
//     cin >> a;
//     int c = broichisla(a);
//     cout << isMunheizen(a);
//     return 0;
// }






//TASK 30
int broichisla (int n){
    if (n==0){
        return 1;
    }
    int broichisla = 0;
    while (n > 0){
        broichisla++;
        n /= 10;
    }
    return broichisla;
}
int power(int a, int b){
    int result = 1;
  for (int i = 0; i < b; i++) {
    result = result * a;
  }
  return result;
}


bool isMunheizen (int n){
    int sum;
    int n2 = n;
    for (int i=0; i<broichisla(n); i++){
        int poslednacifra = n2%10;
        sum += power(poslednacifra, poslednacifra);
        n2/=10;
    }
    return (n==sum);
}

int main(){
    int a;
    cin >> a;
    for (int j=1; j<=a; j++){
        if (isMunheizen(j)){
            cout << j << " ";
        }
    }
    return 0;
}