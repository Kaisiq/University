#include <iostream>
using namespace std;


//Домашна работа, Задача 1
int main(){
    double Ax, Ay, Bx, By, Ax1, Ay1, Bx1, By1;
    double Ashirochina, Avisochina, Bshirochina, Bvisochina;
    int S, a, b;

    //въвеждаме данни за правоъгълник А
    cout << "Molq vuvedete Ax: ";
    cin >> Ax;
    cout << "Molq vuvedete Ay: ";
    cin >> Ay;
    do{
        cout << "Molq vuvedete shirochina na A: ";
        cin >> Ashirochina;
    }while (Ashirochina < 0);
    do{
        cout << "Molq vuvedete visochian na A: ";
        cin >> Avisochina;
    }while (Avisochina < 0);

    //въвеждаме данни за правоъгълник В
    cout << "Molq vuvedete Bx: ";
    cin >> Bx;
    cout << "Molq vuvedete By: ";
    cin >> By;
    do{
        cout << "Molq vuvedete shirochina na B: ";
        cin >> Bshirochina;
    }while (Bshirochina < 0);
    do{
        cout << "Molq vuvedete visochian na B: ";
        cin >> Bvisochina;
    }while (Bvisochina < 0);


    //Долен ляв ъгъл на правоъгълника А е с координати (Ax,Ay)
    //Горен десен ъгъл на A (Ах1,Ау1)
    //Долен ляв ъгъл на B (Bx,By)
    //Горен десен ъгъл на B (Bx1, By1)
    Ax1 = Ax + Ashirochina;
    Ay1 = Ay + Avisochina;
    Bx1 = Bx + Bshirochina;
    By1 = By + Bvisochina;


    //Проверка за кой ъгъл на правоъгълника А принадлежи на правоъгълника В
    // (((Ax,Ay) > (Bx,By)) && ((Ax,Ay) < (Bx1,By1)))  || (((Ax,Ay) < (Bx,By)) && ((Ax,Ay) > (Bx1,By1)))
    

    //Ако двойката (Ах1,Ау) е в правоъгълника В =>  Обратната двойка (Вх,Ву1) е в правоъгълника А. 
    //Това важи за всяка двойка координати на ъглите на правоъгълниците
    bool AxinB = ((Ax>Bx) && (Ax<Bx1)) || ((Ax<Bx) && (Ax>Bx1));     //Проверка за Ax
    bool AyinB = ((Ay>By) && (Ay<By1)) || ((Ay<By) && (Ay>By1));     //Проверка за Ау
    bool Ax1inB = ((Ax1>Bx) && (Ax1<Bx1)) || ((Ax1<Bx) && (Ax1>Bx1));     //Проверка за Ах1
    bool Ay1inB = ((Ay1>By) && (Ay1<By1)) || ((Ay1<By) && (Ay1>By1));     //Проверка за Ау1


    if (AxinB){   //Проверка за Ax
        if (AyinB){   //Проверка за Ay
            //(Ax,Ax) принадлежи на правоъгълника В
            a = Ax-Bx1;
            if (a<0){
                a = -a;    //обръщаме а в положително число ако е отрицателно
            }
            b = Ay-By1;
            if (b<0){
                b = -b;  //обръщаме b в положително число ако е отрицателно
            }
            S = a*b;
            cout << S;

        }else {cout << "0";} 
    }
    else if (Ax1inB){   //Проверка за Ax1
        if (AyinB){    //Проверка за Ay
            // (Ax1,Ay) принадлежи на правоъгълника В
            a = Ax1-Bx;
            if (a<0){
                a = -a; 
            }
            b = Ay-By1;
            if (b<0){
                b = -b;
            }
            S = a*b;
            cout << S;
        }else {cout << "0";} 
    }
    else if (AxinB){    //Проверка за Ax
        if (Ay1inB){    //Проверка за Ay1
            //(Ax,Ay1) принадлежи на правоъгълника B
            a = Ax-Bx1;
            if (a<0){
                a = -a; 
            }
            b = Ay1-By;
            if (b<0){
                b = -b;
            }
            S = a*b;
            cout << S;
        }else {cout << "0";} 
    }
    else if (Ax1inB){    //Проверка за Ax1
        if (Ay1inB){    //Проверка за Ay1
            //(Ax1,Ay1) принадлежи на правоъгълника B
            a = Ax1-Bx;
            if (a<0){
                a = -a; 
            }
            b = Ay1-By;
            if (b<0){
                b = -b;
            }
            S = a*b;
            cout << S;
        }
    }
    else{
        cout << "0";
        }
    return 0;
}