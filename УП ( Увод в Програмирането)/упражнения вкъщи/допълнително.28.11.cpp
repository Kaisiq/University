#include <iostream>
using namespace std;






//TASK 1

double min(double arr[], int length){
    double min=arr[0];
    for(int i=0;i<length;i++){
        if(min>arr[i]){
            min = arr[i];
        }
    }
    return min;
}
double max(double arr[], int length){
    double max=arr[0];
    for(int i=0;i<length;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}
double srednoAritm(double arr[], int length){
    double sum=0;
    double count=0;
    for(int i=0;i<length;i++){
        sum += arr[i];
        count++;
    }
    if(count==0){
        return 0;
    }
    return (sum/count);
}


double sum(double arr[],int length){
    double sum=min(arr,length)+max(arr,length)+srednoAritm(arr,length);
    return sum; 
}

// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while(n>1000 || n<0);
//     double arr[1000];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << sum(arr,n);
//     return 0;
// }









//TASK 2

void reversePrintArr(int arr[],int length){
    for (int i=length-1;i>=0;i--){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while(n>1000 || n<0);
//     int arr[1000];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     reversePrintArr(arr,n);
//     return 0;
// }








//TASK 3

int howMuchNumbers(long int n){
    int count=0;
    while (n>0){
        count++;
        n/=10;
    }
    return count;
}

int howMuchTimesDuplicate(int arr[],int x, int length){
    int count=0;
    for(int i=0;i<length;i++){
        if(arr[i]==x){
            count++;
        }
    }
    return count;
}

// int main(){
//     long int n;
//     do{
//         cin >> n;
//     }while (howMuchNumbers(n)>12 || howMuchNumbers(n)<0);
//     int length = howMuchNumbers(n);
//     int arr[length]={0,};
//     for(int i=length-1;i>=0;i--){
//         arr[i]=n%10;
//         n/=10;
//     }
//     for(int i=0;i<9;i++){
//         cout << i << " - " << howMuchTimesDuplicate(arr,i,length) << endl;
//     }

//     return 0;
// }











//TASK 4

bool isPalindrome(char* str, int halflength,int length){
    for (int i=0;i<halflength;i++){
        if (str[i] != str[(length-1)-i]){
            return 0;
        }
    }
    return 1;
}


// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while (n<0 || n>100);
//     char str[100];
//     for(int i=0;i<n;i++){
//         cin >> str[i];
//     }
//     int halflength = n/2;
//     if(isPalindrome(str,halflength,n)){
//         cout << "yes";
//     }
//     else cout << "no";
//     return 0;
// }







//TASK 5

int createArrBAndSum2(int arr[],int length){
    int arr2[35];
    int sum2=0;
    for (int i=0;i<length;i++){
        if(arr[i]%10==0){
            arr2[i]=arr[i]/10;
        }
        else if(arr[i]%10!=0){
            if (i%2==0){
                arr2[i]=arr[i]/10;
            }
            if (i%2!=0){
                arr2[i]=(arr[i]/10) + 1;
            }
        }
        sum2 += arr2[i];
    }
    return sum2*10;
}


// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while (n<5||n>35);
//     int arr[35];
//     int sum1=0;
//     for(int i=0;i<n;i++){
//         do{
//             cin >> arr[i];
//             sum1 += arr[i];
//         }while (arr[i]<100 || arr[i]>990);
//     }
//     int sum2 = createArrBAndSum2(arr,n);
//     cout << sum1 << endl << sum2;


//     return 0;
// }









//TASK 6

bool isArmstrong(int n){
    int a=n%10;
    int b=n/10%10;
    int c=n/100;
    if (((a*a*a)+(b*b*b)+(c*c*c)) == n){
        return 1;
    }
    else return 0;
}


// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while (n<5||n>100);
//     int arr[100];
//     for (int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     int count=0;
//     for (int i=0;i<n;i++){
//         if(!(isArmstrong(arr[i]))){
//             count++;
//         }
//         if(count==n){
//             cout << "Nqma chisa na Armstrong";
//         }
//     }
//     for (int i=0;i<n;i++){
//         if (isArmstrong(arr[i])){
//             cout << arr[i] << " ";
//         }
//     }
//     return 0;
// }










//TASK 7
bool isEqualToFibonacci(int n){
    int fibonacci=1;
    int fibonacci2=1;
    while(fibonacci<1005){
        if(n==fibonacci){
            return 1;
        }
        int c = fibonacci;
        fibonacci += fibonacci2;
        fibonacci2 = c;
    }
    return 0;
}


// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while (n<5||n>1005);
//     int arr[1006];
//     for (int i=1; i<n;i++){
//         do{
//             cin >> arr[i];
//         }while (arr[i]<10 || arr[i]>99);
//     }   
//     int sum=0;
//     for (int i=0;i<n;i++){
//         if(isEqualToFibonacci(i)){
//             cout << arr[i] << " ";
//             if(i==1){
//                 sum+=arr[i];
//             }
//             sum += arr[i];
//         }
//     }
//     cout << endl << sum;

//     return 0;
// }













//TASK 8
// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while (n<5||n>25);
//     int arr[25];
//     for (int i=0; i<n;i++){
//         cin >> arr[i];
//     }  
//     for (int i=0;i<n;i++){
//         int a=arr[i];
//         int b=arr[i+1];
//         if(a<0){
//             a *= -1;
//         }
//         if (b<0){
//             b *= -1;
//         }
//         if (a==b){
//             cout << arr[i] << " ; " << arr[i+1] << endl;
//         }
//     }
//     return 0;
// }














//TASK 9

int sumOfAllPositiveNumbers(int arr[],int length){
    int sum=0;
    for(int i=0;i<length;i++){
        if(arr[i]>0){
            sum += arr[i];
        }
    }
    return sum;
}


// int main(){
//     int n;
//     do{
//         cin >> n;
//     }while (n<0||n>3000);
//     int arr[3000];
//     for (int i=0; i<n;i++){
//         cin >> arr[i];
//     }
//     int sum=sumOfAllPositiveNumbers(arr,n);
    
    

//     int count=1;
//     for(int i=0;i<n;i++){
//         if (arr[i]==arr[i+1]){
//             count++;
//         }
//         else if (count>=3){
//             for(int k=i-count+1;k<n-count+1;k++){
//                 arr[k+1]=arr[k+count];
//             }
//             arr[i-count+1]=sum;
//             n -= count - 1;
//             count = 1;
//         }
//         else count = 1;
//     }



//     for (int i=0; i<n;i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }













//TASK 10
int zeroesCount(int n){
    int zeroes=0;
    while(n!=0){
        if((n&1)==0){
            zeroes++;
        }
        n>>=1;
    }
    return zeroes;
}




int main(){
    int n;
    cin >> n;
    cout << zeroesCount(n);
    return 0;
}
