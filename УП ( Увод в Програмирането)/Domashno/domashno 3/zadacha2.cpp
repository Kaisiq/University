#include <iostream>
#include "BullsAndCows.h"

using namespace std;

const int* tryGuess(int);


bool isNotValid(int i, int* notMatching){
    int lastd = i/1000;
    int thirdd = (i/100)%10;
    int secondd = (i/10)%10;
    int firstd = i%10;
    for(int j=0; j<9;j++){
        if(firstd == notMatching[j] || secondd == notMatching[j] || thirdd == notMatching[j] || lastd == notMatching[j]){
            return 1;
        }
    }
    return(lastd == thirdd || lastd == secondd || lastd == firstd || thirdd == secondd || thirdd == firstd || secondd == firstd || firstd == 0 || secondd == 0 || thirdd == 0 || lastd == 0);
}


bool guessNext(int& i, int& guesses, int bulls, int cows, int* notMatching){
    if(i>9876){
        cout << "Either invalid number, or my code doesn't work";
        return 0;
    }
    int lastd = i/1000;
    int thirdd = (i/100)%10;
    int secondd = (i/10)%10;
    int firstd = i%10;

    if(isNotValid(i,notMatching)){
        i++;
        return guessNext(i, guesses, bulls, cows, notMatching);
    }
    
    const int* bullsAndCows = tryGuess(i);
    bulls = bullsAndCows[0];
    cows = bullsAndCows[1];
    delete[] bullsAndCows;
    if(cows==0 && bulls==0){
        int helper = 1;
        for(int k=0; k<9; k++){
            if(notMatching[k] == 0){
                notMatching[k] = i/helper%10;
                helper*10;
                if(helper>1000){
                    break;
                }
            }
        }
    }
    guesses++;
    if(guesses>7){
        return 0;
    }
    if(guesses == 7 && bulls!=4){
        return 0;
    }
    if(bulls==4){
        return 1;
    }

    i++;
    return guessNext(i, guesses, bulls, cows, notMatching);
}





void play(){
    int guessNumber;
    int bullsTurn1, cowsTurn1;
    int bullsTurn2, cowsTurn2;


    const int* bullsAndCows = tryGuess(1234);
    bullsTurn1 = bullsAndCows[0];
    cowsTurn1 = bullsAndCows[1];
    delete[] bullsAndCows;
    if(bullsTurn1 == 4){
        cout << "I Win! The number was: 1234  It Took me 1 turn.";
        return;
    }
    bullsAndCows = tryGuess(5678);
    bullsTurn2 = bullsAndCows[0];
    cowsTurn2 = bullsAndCows[1];
    delete[] bullsAndCows;
    if(bullsTurn2 == 4){
        cout << "I Win! The number was: 5678  It Took me 2 turns.";
        return;
    }
    
    int guesses = 2;

    bool is9InTheNumber = (bullsTurn1 + bullsTurn2 + cowsTurn1 + cowsTurn2) != 4;
    int bulls = bullsTurn2;
    int cows = cowsTurn2;
    int i = 1235;

    if(!is9InTheNumber){
        int notMatching[9] = {9,0,0,0,0,0,0,0,0};
        if(guessNext(i, guesses, bulls, cows, notMatching)){
            cout<< "I win! The number was: " << i << "\n It took me " << guesses << " tries";
            return;
        }
        else{
            cout<< "I lost..";
            return;
        }
    }
    if(is9InTheNumber){
        int notMatching[9] = {0,};
        if(guessNext(i, guesses, bulls, cows, notMatching)){
            cout<< "I win! The number was: " << i << "\n It took me " << guesses << " tries";
            return;
        }
        else{
            cout<< "I lost..";
            return;
        }
    }

    return;
}