//TASK 1


#include <iostream>
using namespace std;


const unsigned int maxHeight = 20;
const unsigned int maxLength = 40;


bool isPlayerInputValid(const int input,const unsigned int length, int& inputHeight, const char playField[][maxLength]){
    if(input < 0 || input > length-1){
        return 0;
    }
    while (playField[inputHeight][input] != ' '){
        if (inputHeight<0){
            return 0;
        }
        inputHeight--;
    }


    return 1;
}

void fillPlayField(char playField[maxHeight][maxLength], const unsigned int length, const unsigned int height){
    for (int i=0; i<height; i++){
        for (int j=0; j<=length; j++){
            playField[i][j] = ' ';
        }
    }
}

void printField(const char playField[][maxLength], const unsigned int length, const unsigned int height){
    for (int i=0;i<height;i++){
        for (int j=0; j<length; j++){
            cout << "|" << playField[i][j];
        }
        cout << "|" << endl;
    }
}

unsigned int min(const int a, const int b){
    return a < b ? b : a;
}


//<------------------Checks start here------------------->
bool fourInARow(const char playField[][maxLength], const unsigned int length, const unsigned int height, const char Player){
    for (int i=0; i<height; i++){
        for (int j=0; j<length-3; j++){
            if((playField[i][j] == Player) && (playField[i][j+1] == Player) && (playField[i][j+2] == Player) &&  (playField[i][j+3] == Player)){
                return 1;
            }
        }
    }
    return 0;
}

bool fourInACol(const char playField[][maxLength], const unsigned int length, const unsigned int height, const char Player){
    for (int i=0; i<height-3; i++){
        for (int j=0; j<length; j++){
            if((playField[i][j] == Player) && (playField[i+1][j] == Player) && (playField[i+2][j] == Player) &&  (playField[i+3][j] == Player)){
                return 1;
            }
        }
    }
    return 0;
}


bool fourInADiagonal(const char playField[][maxLength], const unsigned int length, const unsigned int height, const char Player){
    for (int i=0; i<min(length,height)-3; i++){
        if ((playField[i][i] == Player) && (playField[i+1][i+1] == Player) && (playField[i+2][i+2] == Player) &&  (playField[i+3][i+3] == Player)){
            return 1;
        }
    }
    return 0;
}




bool fourOverDiagonal(const char playField[][maxLength], const unsigned int length, const unsigned int height, const char Player){
    for (int i=length-3; i>0; i--){
        for (int j=0; j<length-3 - (i-1); j++){
            if((playField[j][i] == Player) && (playField[j+1][i+1] == Player) && (playField[j+2][i+2] == Player) &&  (playField[j+3][i+3] == Player)){
                return 1;
            }
        }
    }
    return 0;
}

bool fourUnderDiagonal(const char playField[][maxLength], const unsigned int length, const unsigned int height, const char Player){
    for (int i=0; i<height-3; i++){
        for(int j=0;j<length-3;j++){
            if((playField[j][i] == Player) && (playField[j+1][i+1] == Player) && (playField[j+2][i+2] == Player) &&  (playField[j+3][i+3] == Player)){
                return 1;
            }
        }
    }
    return 0;
}




bool fourInSecondaryDiagonal(const char playField[][maxLength], const unsigned int length, const unsigned int height, const char Player){
    for (int i=0; i<min(length,height)-3; i++){
        for (int j=0; j<min(length,height);j++){
            if ((i+j) == (min(length,height)-1)){
                if ((playField[i][j] == Player) && (playField[i+1][j-1] == Player) && (playField[i+2][j-2] == Player) &&  (playField[i+3][j-3] == Player)){
                return 1;
                }
            }
        }
    }
    return 0;
}




bool fourOverSecondaryDiagonal(const char playField[][maxLength], const unsigned int length, const unsigned int height, const char Player){
    for (int k=2; k<=length-3;k++){
        for (int i=0; i<min(length,height)-3; i++){
            for (int j=0; j<min(length,height);j++){
                if ((i+j) == (min(length,height)-k)){
                    if ((playField[i][j] == Player) && (playField[i+1][j-1] == Player) && (playField[i+2][j-2] == Player) &&  (playField[i+3][j-3] == Player)){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}




bool fourUnderSecondaryDiagonal(const char playField[][maxLength], const unsigned int length, const unsigned int height, const char Player){
    for (int k=0; k<=length-3;k++){
        for (int i=0; i<min(length,height)-3; i++){
            for (int j=0; j<min(length,height);j++){
                if ((i+j) == (min(length,height)+k)){
                    if ((playField[i][j] == Player) && (playField[i+1][j-1] == Player) && (playField[i+2][j-2] == Player) &&  (playField[i+3][j-3] == Player)){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}




// <-------------Checks for win-------------------->

bool player1Wins(const char playField[][maxLength], const unsigned int length, const unsigned int height){
    return (fourInARow(playField,length,height,'X') || fourInACol(playField,length,height,'X') || fourInADiagonal(playField,length,height,'X') ||
    fourOverDiagonal(playField,length,height,'X') || fourUnderDiagonal(playField,length,height,'X') || fourInSecondaryDiagonal(playField,length,height,'X') ||
    fourOverSecondaryDiagonal(playField,length,height,'X') || fourUnderSecondaryDiagonal(playField,length,height,'X'));
}

bool player2Wins(const char playField[][maxLength], const unsigned int length, const unsigned int height){
    return (fourInARow(playField,length,height,'O') || fourInACol(playField,length,height,'O') || fourInADiagonal(playField,length,height,'O') ||
    fourOverDiagonal(playField,length,height,'O') || fourUnderDiagonal(playField,length,height,'O') || fourInSecondaryDiagonal(playField,length,height,'O') ||
    fourOverSecondaryDiagonal(playField,length,height,'O') || fourUnderSecondaryDiagonal(playField,length,height,'O'));
}

// <-----------------Checks end here---------------------->


int main(){
    unsigned int length, height;
    do {
        cin >> height;
    }while (height<4 || height>20);
    do {
        cin >> length;
    }while (length<4 || length>40);

    char playField[maxHeight][maxLength];

    fillPlayField(playField, length, height);





    unsigned int Player1,Player2;   //X - Player 1        O - Player 2
    unsigned int turns = 0;
    int inputHeight;
    printField(playField, length, height);

    while (turns<((length*height)/2)){
        do{
            inputHeight = height-1;
            cin >> Player1;
            Player1--;
        }while (!isPlayerInputValid(Player1, length, inputHeight, playField));
        playField[inputHeight][Player1] = 'X';

        printField(playField, length, height);

        if (player1Wins(playField,length,height)){
            cout << "Player 1 Wins!";
            return 0;
        }


        do{
            inputHeight = height-1;
            cin >> Player2;
            Player2--;
        }while (!isPlayerInputValid(Player2, length, inputHeight, playField));
        playField[inputHeight][Player2] = 'O';

        printField(playField, length, height);

        if (player2Wins(playField,length,height)){
            cout << "Player 2 Wins!";
            return 0;
        }

        turns++;
    }

    cout << "No winner" << endl;

    return 0;
}