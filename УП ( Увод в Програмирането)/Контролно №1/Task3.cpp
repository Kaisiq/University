//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 1
// 2020-11-29
//
// Начален час: 09:00
// Име: Даниел Даниел Иванов
// ФН: 45792
// Специалност: Информатика
// Курс: Първи
// Административна група: 4
// Използван компилатор: G++
//

#include <iostream>
using namespace std;

bool isEqualToM(int m, double a, double b){
    if(a>b){
        if ((a-b) == m){
            return 1;
        }
    }
    else if(a<b){
        if ((b-a) == m){
            return 1;
        }
    }
    else return 0;
}



int main(){
    int n;
    do{
        cin >> n;
    }
    while (n<0 || n>1000000);
    double arr[1000000];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int m=0;
    int i;
    for (int k=1;k<n-1;k++){
        for(i=0;i<n;i+=k){
            if(i==0){
                m=arr[i]-arr[i+k];
                if(m<0){
                    m*=-1;
                }
            }
            if (!isEqualToM(m,arr[i],arr[i+k])){
                break;
            }
        }
        if (isEqualToM(m,arr[i],arr[i+k])){
            cout << k << " ";
        }
    }

    return 0;
}