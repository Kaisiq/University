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

bool isPrime(int a){
    if (a<=1){
        return 0;
    }
    for(int i=2;i<a;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}



int main(){
    int a,b;
    cin >> a >> b;
    int count=0;
    int countNumbers=0;
    for (int i=a;i<=b;i++){
        for (int j=2;j<i;j++){
            if(((i%j)==0)){
                count++;
            }
        }
        if (isPrime(count)){
        countNumbers++;
        }
        count = 0;
    }

    cout << countNumbers;

    return 0;
}