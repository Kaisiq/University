#include <iostream>
using namespace std;



bool isValidInput(unsigned den, unsigned mesec, unsigned godina, unsigned chas, unsigned minuta, unsigned sekunda);


int main(){
    unsigned int denA,mesecA,godinaA,chasA,minutaA,sekundaA;
    unsigned int denB,mesecB,godinaB,chasB,minutaB,sekundaB;
    char a;

    cin >> denA >> a >> mesecA >> a >> godinaA >> chasA>> a >> minutaA >> a >> sekundaA;
    cin >> denB >> a >> mesecB >> a >> godinaB >> chasB>> a >> minutaB >> a >> sekundaB;

    if(!(isValidInput(denA,mesecA,godinaA,chasA,minutaA,sekundaA))){
        return 0;
    }

    if(!(isValidInput(denB,mesecB,godinaB,chasB,minutaB,sekundaB))){
        return 0;
    }


    bool visokosnaA = (godinaA % 400 == 0) || ((godinaA%100 !=0 ) && (godinaA%4 == 0));  
    bool visokosnaB = (godinaB % 400 == 0) || ((godinaB%100 !=0 ) && (godinaB%4 == 0));  


    godinaA--;
    godinaB--;


    unsigned int dniVGodinaA = (godinaA*365) + (godinaA/4) + (godinaA/400) - (godinaA/100);
    unsigned int dniVGodinaB = (godinaB*365) + (godinaB/4) + (godinaB/400) - (godinaB/100);


    unsigned int sborDniA=0, sborDniB=0;
    sborDniA += dniVGodinaA;
    sborDniB += dniVGodinaB;



    switch (mesecA){
        case 12:
            sborDniA += 30; //november
        case 11:
            sborDniA += 31; //october
        case 10:
            sborDniA += 30; //sept
        case 9:
            sborDniA += 31; //aug
        case 8:
            sborDniA += 31; //jul
        case 7:
            sborDniA += 30; //june
        case 6:
            sborDniA += 31; //may
        case 5:
            sborDniA += 30; //apr
        case 4:
            sborDniA += 31; //mar
        case 3:
            if (visokosnaA){
                sborDniA += 29;
            }else{
                sborDniA += 28; //feb
            }
        case 2:
            sborDniA += 31; //january
        case 1:
            sborDniA += denA;

    }

    switch (mesecB){
        case 12:
            sborDniB += 30; //november
        case 11:
            sborDniB += 31; //october
        case 10:
            sborDniB += 30; //sept
        case 9:
            sborDniB += 31; //aug
        case 8:
            sborDniB += 31; //jul
        case 7:
            sborDniB += 30; //june
        case 6:
            sborDniB += 31; //may
        case 5:
            sborDniB += 30; //apr
        case 4:
            sborDniB += 31; //mar
        case 3:
            if (visokosnaB){
                sborDniB += 29;
            }else{
                sborDniB += 28; //feb
            }
        case 2:
            sborDniB += 31; //january
        case 1:
            sborDniB += denB;
    }

    int dniRazlika = 0; 
    int chasRazlika, minutaRazlika, sekundaRazlika;
    if (sborDniA>sborDniB){
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


    if(sekundaRazlika<0){
        sekundaRazlika = 60+sekundaRazlika;
        minutaRazlika--;
    }
    if(minutaRazlika<0){
        minutaRazlika = 60+minutaRazlika;
        chasRazlika--;
    }
    if(chasRazlika<0){
        chasRazlika = 24+chasRazlika;
        dniRazlika--;
    }



    if (dniRazlika != 0){ 
        cout << dniRazlika << "-";
    }

    cout << chasRazlika << ":";
    cout << minutaRazlika << ":";
    cout << sekundaRazlika;


    return 0;
}


bool isValidInput(unsigned den, unsigned mesec, unsigned int godina, unsigned chas, unsigned minuta, unsigned sekunda){
    bool visokosna = (godina % 400 == 0) || ((godina%100 !=0 ) && (godina%4 == 0));
    if (den < 1 || den > 31){
        cout << "Invalid input";
        return 0;
    }else if (mesec <1 || mesec > 12){
        cout << "Invalid input";
        return 0;
    }else if (godina < 0 || godina > 9999){
        cout << "Invalid input";
        return 0;
    }else if (chas<0 || chas>23){
        cout << "Invalid input";
        return 0;
    }else if (minuta<0 || minuta>59){
        cout << "Invalid input";
        return 0;
    }else if (sekunda<0 || sekunda>59){
        cout << "Invalid input";
        return 0;
    }else if((mesec==4 || mesec==6 || mesec==9 || mesec==11)  &&  den>30){
        cout << "Invalid input";
        return 0;
    }else if(visokosna){
        if (mesec==2 && den>29){
            cout << "Invalid input";
            return 0;
        }
    }else if(!visokosna){
        if (mesec==2 && den>28){
            cout << "Invalid input";
            return 0;
        }
    }else{
        return 1;
    }
}