//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Практически изпит - задачи
// 2021-02-01
//
// Име: Даниел Иванов
// ФН:45792
// Специалност:Информатика
// Курс: 1
// Административна група: 4
// Използван компилатор:GCC
//


#include <iostream>
using namespace std;



void reverseDominoPart(unsigned& a, unsigned& b){
    int c = b;
    b = a;
    a = c;
}

void swap(int*a, int*b){
    int*c = b;
    b = a;
    a = c;
}

void dominos(unsigned** matrix, int len, int count=0, int current=0){
    bool foundNextDomino=0;
    for(int i=current+1; i<len; i++){
        if(matrix[current][1] == matrix[i][0]){
            swap(matrix[i],matrix[current+1]);
            foundNextDomino=1;
            break;
        }
        else if(matrix[current][1] == matrix[i][1]){
            reverseDominoPart(matrix[i][0],matrix[i][1]);
            swap(matrix[i],matrix[current+1]);
            foundNextDomino=1;
            break;
        }
        else if(matrix[current][0] == matrix[i][0]){
            reverseDominoPart(matrix[current][0],matrix[current][1]);
            swap(matrix[i],matrix[current+1]);
            foundNextDomino=1;
            break;
        }
        else if(matrix[current][0] == matrix[i][1]){
            reverseDominoPart(matrix[i][0],matrix[i][1]);
            reverseDominoPart(matrix[current][0],matrix[current][1]);
            swap(matrix[i],matrix[current+1]);
            foundNextDomino=1;
            break;
        }
    }
    if(foundNextDomino){
        dominos(matrix,len,count,current+1);
    }
    else{
        if((current==len) && (matrix[current-1][1]==matrix[current][0])){
            for(int i=0; i<len; i++){
                cout << matrix[i][0] << "-" << matrix[i][1] << "  ";
            }
            cout << endl;
            return;
        }
        if(count==len){
            for(int i=0; i<len; i++){
                cout << matrix[i][0] << "-" << matrix[i][1] << "  ";
            }
            cout << endl;
            return;
        }
        swap(matrix[current],matrix[0]);
        dominos(matrix,len,count+1,0);
    }
}


int main(){
    unsigned n;
    cin >> n;
    unsigned** matrix = new(nothrow) unsigned*[n];
    if(!matrix){
        cout << "No mem";
        return 1;
    }
    for(int i=0; i<n; i++){
        matrix[i] = new(nothrow) unsigned[2];
        if(!matrix){
            cout << "No mem";
            return 1;
        }
    }
    for(int i=0; i<n; i++){
        cin >> matrix[i][0];
        cin >> matrix[i][1];
    }


    dominos(matrix, n);



    delete[] matrix;
    return 0;
}