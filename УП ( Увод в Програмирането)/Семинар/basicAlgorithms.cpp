#include <iostream>

using namespace std;

const unsigned maxSize = 128;


//TASK 0a
void printArray(int arr[], int length){
    for (int i=0;i<length;i++){
        cout << arr[i] << " ";
    }
}

//TASK 0b
void readArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}



//TASK 1
int minElementInArray(int arr[],int length){
    int min = arr[0];
    for (int i=1;i<length;i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}






//TASK 2
int maxElementIndexInArray(int arr[],int length){
    int maxindex = 0;
    for (int i=0;i<length;i++){
        if (arr[maxindex] < arr[i]){
            maxindex = i;
        }
    }
    return maxindex;
}


//TASK 3
void printdoubleElementsInArray(int arr[],int length){
    for (int i=0; i<length; i++){
        cout << arr[i] * 2 << " ";
    }
    cout << endl;
}



//TASK 3a
// int numberOfDigits(int n){
//     if (n==0){
//         return 1;
//     }
//     int count=0;
//     while (n>0){
//         count++;
//         n/=10;
//     }
//     return count;
// }

// void printFormattedElement(const int n1, const int n2){
//     const int len1 = numberOfDigits(n1);
//     const int len2 = numberOfDigits(n2);
//     if (len1>=len2){
//         ;
//     }
//     else{
//         for (int i=len1; i<len2; i++){
//             cout << " ";
//         }
//     }
//     cout << n1 << " ";
// }

// void printdoubleElementsInArray(int arr[],int length){
//     for (int i=0; i<length; i++){
//         printFormattedElement((arr[i]*2), arr[i]);
//     }
//     for (int i=0; i<length; i++){
//         printFormattedElement(arr[i], (arr[i] * 2));
//     }
//     cout << endl;
// }

// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<0 || n>100);
//     int arr[maxSize];
//     readArray(arr,n);
//     printdoubleElementsInArray(arr,n);
//     printArray(arr,n);

//     return 0;
// }





//TASK 4
bool deleteElementInArrayAtIndex(int arr[], const int length,const int index){
    if(index>=length || index<0){
        return 0;
    }
    int c;
    for (int i=index; i<length; i++){
        arr[i] = arr[i+1];
    }
    return 1;
}

// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<0 || n>100);
//     int arr[maxSize];
//     readArray(arr,n);
//     if (deleteElementInArrayAtIndex(arr,n,3)){
//         n--;
//     }
//     printArray(arr,n);
//     return 0;
// }








//TASK 5
bool changeElementInArray(int arr[],const int x,const int index){
    if(index>=0 || index<0){
        return 0;
    }
    arr[index] = x;
    return 1;
}






//TASK 6
bool addElementInArray(int arr[],const int length,const int x,const int index){
    if (index<0 || index>length){
        return 0;
    }
    for (int j= length; j-1>index;j--){
        arr[j-1]= arr[j-2];
    }
    arr[index] = x;
    return 1;
}
// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<0 || n>100);
//     int arr[maxSize];
//     n++;
//     readArray(arr,n);
//     addElementInArray(arr,n,312,2);
//     printArray(arr,n);
//     return 0;
// }







//TASK 7
int firstIndexOfNumberInArray(int arr[],int length, int x){
    for(int i=0; i<length; i++){
        if (arr[i] == x){
            cout << i;
        }
    }
}






//TASK 7a
int lastIndexOfNumberInArray(int arr[],int length, int x){
    for(int i=length-1; i>=0; i--){
        if (arr[i] == x){
            cout << i;
        }
    }
}









//TASK 8
int evenElementsInArray(int arr[],int length){
    int count=0;
    for (int i=0; i<length; i++){
        if (arr[i]%2==0){
            count++;
        }
    }
    return count;
}










//TASK 9
bool isPrime(int x){
    int count=0;
    for(int i=2;i<x;i++){
        if(x%i==0){
            count++;
        }
    }
    if (count>0){
        return 0;
    }
    return 1;
}

int primeElementsInArray(int arr[],int length){
    int count=0;
    for (int i=0; i<length; i++){
        if (isPrime){
            count++;
        }
    }
    return count;
}





//TASK 10
int VisokosniGodini(int arr[],int length){
    int count;
    for(int i=0;i<length;i++){
        if(arr[i]%400==0  ||  (arr[i]%100!=0 && arr[i]%4==0)){
            count ++;
        }
    }
    return count;
}






//TASK 11
int sumArray(int arr[], int length){
    int sum=0;
    for(int i=0;i<length;i++){
        sum += arr[i];
    }
    return sum;
}







//TASK 12
int biggestDifferenceInTwoNearbyElements(int arr[],int length){
    int max=arr[1]-arr[0];
    if(max<0){
        max += -1;
    }
    for (int i=1;i<length;i++){
        if (0 < arr[i+1]-arr[i]){
            if (max < arr[i+1]-arr[i]){
                max = arr[i+1] - arr[i];
            }
        }
        if (0 > arr[i+1]-arr[i]){
            if (max < arr[i]-arr[i+1]){
                max = arr[i] - arr[i+1];
            }
        }
    }
    return max;
}

// int main(){
//     int arr[]={1,2,3,3,2,1,4,4,4,4,4,4,126,122,3,140,1};
//     cout << biggestDifferenceInTwoNearbyElements(arr,16);
//     return 0;
// }






//TASK 13
const int maxSize13 = 1000;

int srednoAritmetichno(int arr[],int length){
    int count=0;
    int sum=0;
    for(int i=0;i<length;i++){
        sum += i;
        count++;
    }
    return (sum/count);
}

void removeElementInArrayByIndex(int arr[],int length, int index){
    for (int i=index;i<length-1;i++){
        arr[i]=arr[i+1];
    }
}

int createArrayWithoutNumbersLessThanMiddle(int arr[], int length){
    int count=0;
    int middle = srednoAritmetichno(arr,length);
    for(int i=0;i<length;i++){
        if(arr[i]<middle){
            removeElementInArrayByIndex(arr,length,i);
            count++;
        }
    }
    return count;
}


// int main(){
//     int n;
//     do {
//         cin >> n;
//     }while (n<0|| n>1000);
//     int arr[maxSize13]={0,};
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     int a = createArrayWithoutNumbersLessThanMiddle(arr,n);
//     n = n - a;
//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }


















//TASK 14
int srednoAritmetichno(int arr[],int length){
    int count=0;
    int sum=0;
    for(int i=0;i<length;i++){
        sum += i;
        count++;
    }
    return (sum/count);
}


void createArr2(int arr[],int length, int sredno){
    int arr2[maxSize13];
    int j=0;
    for (int i=0;i<length;i++){
        if(arr[i]>=sredno){
            arr2[j]=arr[i];
            j++;
        }
    }
}

int main(){
    int n;
    do {
        cin >> n;
    }while(n<0 || n>1000);
    int arr[maxSize13];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
     for (int i=0;i<n;i++){
        cout << arr[i];
    }
    createarr2(arr,n,srednoAritmetichno(arr,n));



}






















//TASK 17
bool onlyDifferentNumbers(const int a){
    for (int i=0; i<=9; i++){
        int acopy=a;
        int count=0;
        while(acopy>0){
            if(acopy%10 == i){
                count++;
                if(count>1){
                    return 0;
                }
            }
            acopy/=10;
        }
    }
    return 1;
}

// int main(){
//     int a,b;
//     cin >> a >> b;
//     int count=0;
//     for(int i=a;i<b;i++){
//         if (onlyDifferentNumbers(i)){
//             count++;
//         }
//     }
//     cout << count;
//     return 0;
// }