//Вложени цикли задачки 2-8

#include <iostream>
using namespace std;


//TASK 2
// int main(){
//     char sym;
//     int n;
//     cin >> sym;
//     cin >> n;
//     for(int i=0; i<n; i++){
//         for (int i=0; i<n; i++){
//             cout << sym;
//         }
//         cout << "\n";
//     }
//     return 0;
// }


//TASK 3
// int main(){
//     int n;
//     int b = 1;
//     cin >> n;

//     for(int i=0; i<n; i++){
//         for (int i=0; i<b; i++){
//             cout << '*';
//         }
//         b++;
//         cout << "\n";
//     }

//     return 0;
// }


//TASK 4
// int main(){
//     int i = 0;
//     int n = 9;

//     while(n<100){
//         for (i; i<=n; i++){
//             if (i<10){
//                 cout << " " << i << " ";
//             }else{
//             cout << i << " ";
//             }
//         }
//         cout << "\n";
//         n+=10;
//     }

//     return 0;
// }


//TASK 5
// int main(){
//     int ax = 0;
//     int ay = -5;
//     int bx = 5;
//     int by = 0;
//     int cx = 0;
//     int cy = 5;
//     int dx = -5;
//     int dy = 0;
//     int x = -5;
//     for (x; x<=5; x++){
//         for (int i=-5; i<=5 ; i++){
//             cout << "(" << x << "," << i << ")" << endl;
//         }
//     }

//     return 0;
// }


//TASK 6
// int main(){
//     int ax = 0;
//     int ay = -5;
//     int bx = 5;
//     int by = 0;
//     int cx = 0;
//     int cy = 5;
//     int dx = -5;
//     int dy = 0;   //това са 4-те точки A,B,C,D, които оформят квадрата (-5,-5) , (-5,0) , (5,0) , (5,5)
//     int y = -5; //помощна цифра за цикъла, като ще започнем от y координатата със стойност -5 нагоре докато стигнем 5
//     for (y; y<=5; y++){
//         for (int x=-5; x<=5 ; x++){ //х координатата със стойност -5 като цикъла върти до стойност 5
//             if ((x * y) >= (-15) && (x * y) <= 15){ //3.14*5~=15, затова пишем, че ако x * y <= 15 изкарваме двойката (х,у)
//             cout << "(" << x << "," << y << ")" << endl;
//             }
//         }
//     }

//     return 0;
// }


//TASK 7
// int main(){
//     int a = 1;
//     int b = 1;
//     for (a; a<=10 ; a++){
//         for (b; b<=10 ; b++){ 
//             if (a<10 && b<10){
//                 cout << " "<< a << " * " << " " << b << " = " << a*b << endl;
//             } else if (a<10){
//                 cout << " "<< a << " * " << b << " = " << a*b << endl;
//             } else if (b<10){
//                 cout << a << " * " << " " << b << " = " << a*b << endl;
//             } else {
//                 cout << a << " * " << b << " = " << a*b << endl;
//             }
//         }
//         b = 1;
//     }

//     return 0;
// }


//TASK 8
// int main(){
//     int deleno = 0;
//     for (int i=1 ; i<100; i++){
//         for (int c=1 ; c<i ; c++){
//             if ((i%c) == 0){
//                 deleno++;
//             }
//         }
//         if (deleno < 2){
//             cout << i << " e prosto chislo\n";
//         }
//         deleno = 0;
//     }
//     return 0;
// }