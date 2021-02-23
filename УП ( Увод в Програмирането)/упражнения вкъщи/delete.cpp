//Kontr variant 1 
#include <iostream>
using namespace std;

//TASK 1
// int main(){
//     float Ax,Ay,Bx,By,Cx,Cy;
//     cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
//     float ABx, BCx, ABy, BCy;
//     ABx = Bx-Ax;
//     BCx = Cx-Bx;
//     ABy = By-Ay;
//     BCy = Cy-By;
//     if (ABx/BCx  ==  ABy/BCy){
//         cout << "yes";
//     }
//     else {
//         cout << "no";
//     }
//     return 0;
// }   







//TASK 2
// int main(){
//     short int a,b;
//     cin >> a >> b;
//     int count = 0;
//     for (int i=a; i<b; i++){
//         int suma =0;
//         int sumb=1;
//         int icopy=i;
//         while(icopy!=0){
//             suma+=(icopy%10);
//             icopy/=10;
//         }
//         icopy =i;
//         while(icopy!=0){
//             if(icopy%10==0){
//                 icopy/=10;
//                 continue;
//             }
//             sumb*=(icopy%10);
//             icopy/=10;
//         }
//         if (suma==sumb){
//             count++;
//         }
//     }
//     cout << count;
//     return 0;
// }













//TASK 3
// unsigned Max_Size = 1000;
// int main(){
//     int n=0;
//     double sum=0;
//     double count=0;
//     do {
//         cin >> n;
//     }while (n<=0 || n>1000);
//     float masiv[Max_Size];
//     for (int i=0;i<n;i++){
//         cin >> masiv[i];
//     }
//     for (int i=0;i<n;i++){
//         sum += masiv[i];
//         count++;
//     }
//     double average = sum/count;
//     float masiv2[Max_Size];
//     int j=0;
//     for (int i=0;i<n;i++){
//         if (masiv[i]>average){
//             masiv2[j]=masiv[i];
//             j++;
//         }
//     }
//     for (int i=0; i<j; i++){
//         cout << masiv2[i] << " ";
//     }
//     return 0;
// }














//TASK 4
// int max_Size = 100;
// int main(){
//     int n=0;
//     do {
//         cin >> n;
//     }while (n<2 || n>100);
//     int array[max_Size];
//     for(int i=0; i<(n*n);i++){
//         cin >> array[i];
//     }
//     int sumgore=0, sumdolu=0, sumlqvo=0,sumdqsno=0, sumdiagonal=0, sumdiagonal2=0;
//     for(int i=0; i<n; i++){
//         sumgore += array[i];
//     }
//     for(int i=(n-1)*n; i<n*n; i++){
//         sumdolu += array[i];
//     }
//     for (int i=0; i<n; i++){
//         sumlqvo += array[i*n];
//     }
//     for (int i=0; i<n; i++){
//         sumdqsno += array[i*n+(n-1)];
//     }
//     for (int i=0; i<n; i++){
//         sumdiagonal += array[i*n+i];
//     }
//     for (int i=0; i<n; i++){
//         sumdiagonal2 += array[i*n+(n-1-i)];
//     }
//     if (sumgore==sumdolu && sumdolu==sumlqvo && sumlqvo==sumdqsno && sumdqsno==sumdiagonal && sumdiagonal==sumdiagonal2){
//         cout << "yes";
//     }else {
//         cout << "no";
//     }
// }








//група Б







//TASK 1

// int main(){
//     float Ax,Ay,Bx,By,Cx,Cy;
//     cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
//     float ABx = Bx-Ax;
//     float ABy = By-Ay;
//     float BCx = Cx-Bx;
//     float BCy = Cy-By;
//     float CAx = Ax-Cx;
//     float CAy = Ay-Cx;
//     float AB = ABx*ABx + ABy*ABy;
//     float BC = BCx*BCx + BCy*BCy;
//     float CA = CAx*CAx + CAy*CAy;
//     if (AB>BC && AB>CA){
//         if(AB==BC + CA){
//             cout << "Yes";
//         }
//         else cout << "No";
//     }
//     else if (BC>AB && BC>CA){
//         if(BC==AB + CA){
//             cout << "Yes";
//         }
//         else cout << "No";
//     }
//     else if (CA>BC && CA>AB){
//         if(CA==BC + AB){
//             cout << "Yes";
//         }
//         else cout << "No";
//     }
//     return 0;
// }












//TASK 2
// bool povtorkaNaCifraVChislo(int a, int n){
//     int count=0;
//     while(a>0){
//         if(n==a%10){
//             count++;
//         }
//         a/=10;
//     }
//     if (count>1){
//         return 1;
//     }
//     return 0;
// }

// int main(){
//     int a,b;
//     cin >> a >> b;
//     int count =0;
//     int lastdigit;
//     for (int i=a; i<b;i++){
//         count++;
//         for (int j=i;j>10;j/=10){
//             lastdigit = j%10;
//             if(povtorkaNaCifraVChislo(i,lastdigit)){
//                 count--;
//                 break;
//             }
//         }
//     }
//     cout << count;
//     return 0;
// }















//TASK 3
// int sumOddNumbers(int n){
//     int sum=0;
//     for (int i=1;i<n;i+=2){
//         sum += i;
//     }
//     return sum;
// }


// const unsigned int max_Size = 5000;
// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while (n<=0 || n>5000);
//     int arr[max_Size];
//     for (int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     for (int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     int j=0;
//     int arr2[max_Size];
//     for (int i=0;i<n;i++){
//         if(arr[i]%2==0){
//             arr2[j]=arr[i];
//             j++;
//             arr2[j]=arr[i]/2;
//             j++;
//         }else {
//             arr2[j]=arr[i];
//             j++;
//             arr2[j]=sumOddNumbers(arr[i]);
//             j++;
//         }
//     }
//     for (int i=0;i<n*2;i++){
//         cout << arr2[i] << " ";
//     }
    
// }

















//TASK 1
int main(){
    float Ax,By,C;
    float Dx,Ey,F;
    cin >> Ax >> By >> C >> Dx >> Ey >> F;
    float X,Y;
    if ((Ax*Ey - By*Dx) ==0){
        cout << "NRK";
        return 0;
    }
    cout << "X = " << ((C*Ey)-(By*F))/ ((Ax*Ey)-(By*Dx)) << endl;
    cout << "Y = " << ((Ax*F)-(C*Dx))/ ((Ax*Ey)-(By*Dx));

    return 0;
}