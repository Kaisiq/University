#include <iostream>
using namespace std;



bool isValidInput(unsigned den, unsigned mesec, unsigned godina, unsigned chas, unsigned minuta, unsigned sekunda);


int main(){
    unsigned int denA, mesecA, godinaA, chasA, minutaA, sekundaA;
    unsigned int denB, mesecB, godinaB, chasB, minutaB, sekundaB;
    char a;

    cin >> denA >> a >> mesecA >> a >> godinaA >> chasA>> a >> minutaA >> a >> sekundaA;
    cin >> denB >> a >> mesecB >> a >> godinaB >> chasB>> a >> minutaB >> a >> sekundaB;


    //проверяваме дали въведените данни са верни
    if(!(isValidInput(denA, mesecA, godinaA, chasA, minutaA, sekundaA))){
        return 0;
    }

    if(!(isValidInput(denB, mesecB, godinaB, chasB, minutaB, sekundaB))){
        return 0;
    }


    bool visokosnaA = (godinaA % 400 == 0) || ((godinaA % 100 !=0 ) && (godinaA % 4 == 0));  //проверява дали годината А е високосна
    bool visokosnaB = (godinaB % 400 == 0) || ((godinaB % 100 !=0 ) && (godinaB % 4 == 0));  //проверява дали годината Б е високосна



    /* изваждаме по 1 от двете години, тъй като сегашната година все още не е изминала
    и не трябва да се прибавя към сбора от дни.
    Примерно ако сме 2.1.0002г. са изминали 365 дни + 1 ден от януари, а не 2*365 дни + 1 ден от януари */
    godinaA--; 
    godinaB--;


    unsigned int dniVGodinaA = (godinaA*365) + (godinaA/4) + (godinaA/400) - (godinaA/100); //добавя всички години като невисокосни, след това прибавя формула,
    unsigned int dniVGodinaB = (godinaB*365) + (godinaB/4) + (godinaB/400) - (godinaB/100); //която добавя по 1 ден за всяка високосна година


    unsigned int sborDniA = 0, sborDniB = 0;
    sborDniA += dniVGodinaA;
    sborDniB += dniVGodinaB;



    switch (mesecA){
        case 12:
            sborDniA += 30; //добавя ноември
        case 11:
            sborDniA += 31; //добавя окт
        case 10:
            sborDniA += 30; //добавя септ
        case 9:
            sborDniA += 31; //добавя авг
        case 8:
            sborDniA += 31; //добавя юли
        case 7:
            sborDniA += 30; //добавя юни
        case 6:
            sborDniA += 31; //добавя май
        case 5:
            sborDniA += 30; //добавя апр
        case 4:
            sborDniA += 31; //добавя март
        case 3:
            if (visokosnaA){
                sborDniA += 29; //добавя февруари (високосна)
            }else{
                sborDniA += 28; //добавя февруари (невисокосна)
            }
        case 2:
            sborDniA += 31; //добавя януари
        case 1:
            sborDniA += denA; //добавя изминалите дни от сегашния месец

    }

    switch (mesecB){
        case 12:
            sborDniB += 30; //добавя ноември
        case 11:
            sborDniB += 31; //добавя октомври
        case 10:
            sborDniB += 30; //добавя септ
        case 9:
            sborDniB += 31; //добавя авг
        case 8:
            sborDniB += 31; //добавя юли
        case 7:
            sborDniB += 30; //добавя юни
        case 6:
            sborDniB += 31; //добавя май
        case 5:
            sborDniB += 30; //добавя апр
        case 4:
            sborDniB += 31; //добавя март
        case 3:
            if (visokosnaB){
                sborDniB += 29; //добавя февруари (високосна)
            }else{
                sborDniB += 28; //добавя февруари (невисокосна)
            }
        case 2:
            sborDniB += 31; //добавя януари
        case 1:
            sborDniB += denB; //добавя изминалите дни от сегашния месец
    }

    int dniRazlika; 
    int chasRazlika, minutaRazlika, sekundaRazlika;

    if (sborDniA > sborDniB){

        dniRazlika = sborDniA - sborDniB;
        chasRazlika = chasA - chasB;
        minutaRazlika = minutaA - minutaB;
        sekundaRazlika = sekundaA - sekundaB;

    } else if (sborDniA<sborDniB){

        dniRazlika = sborDniB - sborDniA;
        chasRazlika = chasB - chasA;
        minutaRazlika = minutaB - minutaA;
        sekundaRazlika = sekundaB - sekundaA;
    }


    if(sekundaRazlika < 0){
        sekundaRazlika = 60 + sekundaRazlika;
        minutaRazlika--;
    }
    if(minutaRazlika < 0){
        minutaRazlika = 60 + minutaRazlika;
        chasRazlika--;
    }
    if(chasRazlika < 0){
        chasRazlika = 24 + chasRazlika;
        dniRazlika--;
    }



    if (dniRazlika != 0){ 
        cout << dniRazlika << "-";
    }

    if (chasRazlika < 10)  cout << "0";
    cout << chasRazlika << ":";
    if (minutaRazlika < 10)  cout << "0";
    cout << minutaRazlika << ":";
    if (sekundaRazlika < 10)  cout << "0";
    cout << sekundaRazlika;


    return 0;
}


bool isValidInput(unsigned den, unsigned mesec, unsigned int godina, unsigned chas, unsigned minuta, unsigned sekunda){

    bool visokosna = (godina % 400 == 0) || ((godina%100 != 0 ) && (godina%4 == 0));  //проверка дали годината е високосна

    if (den < 1 || den > 31){   //ден от месецът не може да е <1 или >31
        cout << "Invalid input";
        return 0;
    }else if (mesec < 1 || mesec > 12){
        cout << "Invalid input";
        return 0;
    }else if (godina < 0 || godina > 9999){
        cout << "Invalid input";
        return 0;
    }else if (chas < 0 || chas > 23){
        cout << "Invalid input";
        return 0;
    }else if (minuta < 0 || minuta > 59){
        cout << "Invalid input";
        return 0;
    }else if (sekunda < 0 || sekunda > 59){
        cout << "Invalid input";
        return 0;
    }else if(((mesec == 4) || (mesec == 6) || (mesec == 9) || (mesec == 11))  &&  den > 30){   //април, юни, септември, ноември са месеци с по 30 дни
        cout << "Invalid input";
        return 0;
    }else if(visokosna){
        if ((mesec == 2) && den > 29){    //ако е високосна февруари има 29 дни
            cout << "Invalid input";
            return 0;
        }
    }else if(!visokosna){
        if ((mesec == 2) && den > 28){     //ако не е високосна февруари има 28 дни 
            cout << "Invalid input";
            return 0;
        }
    }else{
        return 1;
    }
}