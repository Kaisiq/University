#include <iostream>
using namespace std;

//Домашна работа, Задача 2
int main(){
    int m, n;
    unsigned minutiM, minutiN, chas1M, chas2M, chas1N, chas2N;
    cout << "моля въведете число N: ";
    cin >> n;
    cout << "моля въведете число M: ";
    cin >> m;

    minutiM = m & 31;           
    minutiN = n & 31;           //1|010011|001011 &  000...111111  =   000...001011

    chas2M = (m>>6) & 15;
    chas2N = (n>>6) & 15;       //1|010011 &  000..1111  =   000...0011

    chas1M = (m>>10) & 3;
    chas1N = (n>>10) & 3;       //1|01 & 000..11 = 00...01

    bool chasoviformatN = n>>12;  //0|010001|001011 >> 12 = 0
    bool chasoviformatM = m>>12;  //1|010011|001011 >> 12 = 1

    if ((chasoviformatN == 1)){   //проверка дали сме в 24часов формат
        cout << chas1N << chas2N << ":" << minutiN << endl;
    } else if ((chas1N > 1) || (chas2N > 2)){  //ако сме в 12часов формат проверява дали часа е след 12
        cout << "невалидно зададен час за числото N";  //ако е след 12 => грешно зададен час
        return 0;
    } else{
        cout << chas1N << chas2N << ":" << minutiN << endl;     //ако е в 12часов формат и не е след 12часа => изкарва часа и минутите
    }




    if ((chasoviformatM == 1)){
        cout << chas1M << chas2M << ":" << minutiM << endl;
    } else if ((chas1M > 1) || (chas2M > 2)){
        cout << "невалидно зададен час за числото M";
        return 0;
    } else {
        cout << chas1M << chas2M << ":" << minutiM << endl;
    }

    int minutiRazlika, chas2Razlika;
    if (chas1M > chas1N){
        minutiRazlika = minutiM - minutiN;

        if(minutiRazlika < 0){
            minutiRazlika = 60 - minutiRazlika;
            chas2M--;
        }

        chas2Razlika = chas2M - chas2N;

        if (chas2Razlika < 0){
            chas2Razlika = 10 - chas2Razlika;
            chas1M--;
        }

        cout << "diff: " << chas1M - chas1N << chas2Razlika << ":" << minutiRazlika;

    }else if (chas1N > chas1M){
        minutiRazlika = minutiN - minutiM;
        if (minutiRazlika < 0){
            minutiRazlika = 60 - minutiRazlika;
            chas2N--;
        }

        chas2Razlika = chas2N - chas2M;

        if (chas2Razlika < 0){
            chas2Razlika = 10 - chas2Razlika;
            chas1N--;
        }

        cout << "diff: " << chas1N - chas1M << chas2Razlika << ":" << minutiRazlika;

    }else {
        if (chas2M > chas2N){
            minutiRazlika = minutiM - minutiN;

            if (minutiRazlika < 0){
                minutiRazlika = 60 - minutiRazlika;
                chas2M--;
            }

            chas2Razlika = chas2M - chas2N;
            cout << "diff: " << chas1M - chas1N << chas2Razlika << ":" << minutiRazlika;

        } else if (chas2N > chas2M){
            minutiRazlika = minutiN - minutiM;

            if (minutiRazlika < 0){
                minutiRazlika = 60 - minutiRazlika;
                chas2N--;
            }

            chas2Razlika = chas2N - chas2M;
            cout << "diff: " << chas1N - chas1M << chas2Razlika << ":" << minutiRazlika;

        } else if (minutiM > minutiN){
            minutiRazlika = minutiM - minutiN;
            cout << "diff: " << chas1N - chas1M << chas2Razlika << ":" << minutiRazlika;

        } else if (minutiN > minutiM){
            minutiRazlika = minutiN - minutiM;
            cout << "diff: " << chas1N - chas1M << chas2Razlika << ":" << minutiRazlika;
            
        } else {
            cout << "diff: 00:00";
        }
    }


    return 0;
}