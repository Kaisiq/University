//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 2
// 2021-01-17
//
// Начален час: 10:00
// Име: Даниел Даниел Иванов
// ФН: 45792
// Специалност: Информатика
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>
using namespace std;


int main(){
    unsigned int n,m;
    cin >> m >> n;



    int **matrix = new(nothrow) int*[m];
    if(!matrix){
        return 1;
    }

    for(int i=0;i<m;i++){
        matrix[i] = new(nothrow) int[n];
        if(!matrix){
            return 1;
        }
        for(int j=0; j<n;j++){
            cin >> matrix[i][j];
        }
    }

    int k;
    do{
        cin >> k;
    }while(k==0);

    if(k==1){
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
               cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{

        if(k==43){
            int **resultMatrix = new(nothrow) int*[m];  //k=43  => 43%37 != 0
            if(!resultMatrix){
                delete[] matrix;
                return 1;
            }

            for(int i=0;i<m;i++){
                resultMatrix[i] = new(nothrow) int[n];
                if(!resultMatrix){
                    delete[] matrix;
                    delete[] resultMatrix;
                    return 1;
                }
                for(int j=0; j<n;j++){
                    resultMatrix[i][j] = 37;
                }
            }



            for(int i=0;i<m;i++){
                for(int j=0; j<n;j++){
                    if(matrix[i][j] % k == 0){
                        resultMatrix[i][j] = matrix[i][j];
                    }
                }
            }
            for(int i=0;i<m;i++){
                for(int j=0; j<n;j++){
                    if(resultMatrix[i][j] != 37){
                        cout << resultMatrix[i][j] << " ";
                    }
                }
                cout << endl;
            }
            delete[] resultMatrix;
        }

        else{
            int **resultMatrix = new(nothrow) int*[m];  //k=43  => 43%37 != 0
            if(!resultMatrix){
                delete[] matrix;
                return 1;
            }

            for(int i=0;i<m;i++){
                resultMatrix[i] = new(nothrow) int[n];
                if(!resultMatrix){
                    delete[] matrix;
                    delete[] resultMatrix;
                    return 1;
                }
                for(int j=0; j<n;j++){
                    resultMatrix[i][j] = 43;
                }
            }

            for(int i=0;i<m;i++){
                for(int j=0; j<n;j++){
                    if(matrix[i][j] % k == 0){
                        resultMatrix[i][j] = matrix[i][j];
                    }
                }
            }
            for(int i=0;i<m;i++){
                for(int j=0; j<n;j++){
                    if(resultMatrix[i][j] != 43){
                        cout << resultMatrix[i][j] << " ";
                    }
                }
                cout << endl;
            }
            delete[] resultMatrix;
        }
    }


    delete[] matrix;
    return 0;
}