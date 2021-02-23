//TASK 3


#include <iostream>
#include <cstring>

using namespace std;

const unsigned int maxLength = 8192;



void difference(char* number1, char* number2);

bool isCorrectNumber(const char* number) {
    if(*number && ((*number>='0' && (*number<='9')) || *number == '-')){
        if(*number == '0'){
            if(*(number+1)){
                return 0;
            }
        }
        if(*number == '-'){
            if(!*(number+1)){
                return 0;
            }
        }
        if(*number == '-' && *(number+1) == '0'){
            return 0;
        }
        number++;
    }else{
        return 0;
    }
    for(; *number; number++){
        if(*number<'0' || (*number>'9')){
            return 0;
        }
    }
    return 1;
}

int getLength(const char* number){
    int length = 0;
    while (*number){
        number++;
        length++;
    }
    return length;
}


void readCorrectNumber(char* number){
    do{
        cin.getline(number,maxLength);
    }
    while((!isCorrectNumber(number)));
}


void printNumber(const char* number){
    while(*number){
        cout << *number;
        number++;
    }
    cout << endl;
}


bool isEqual(const char* number1, const char* number2){
    if(getLength(number1)<getLength(number2) || getLength(number1)>getLength(number2)){
        return 0;
    }
    else {
        for(int i=0; i<getLength(number1); i++){
            if(number1[i] != number2[i]){
                return 0;
            }
        }
    }
    return 1;
}



int comparison(const char* number1, const char* number2){             //returns 1/0/-1
    if (*number1=='-'  &&  *number2!='-'){
        return -1;
    }
    if (*number1!='-'  &&  *number2=='-'){
        return 1;
    }
    if (getLength(number1) > getLength(number2)){
        if(*number1=='-'  &&  *number2=='-'){
            return -1;
        }
        return 1;
    }
    else if(getLength(number2) > getLength(number1)){
        if(*number1=='-'  &&  *number2=='-'){
            return 1;
        }
        return -1;
    }
    else{        //length1 == length2
        for(int i=0;i<getLength(number1);i++){
            if (number1[i] > number2[i]){
                if(*number1=='-'  &&  *number2=='-'){
                    return -1;
                }
                return 1;
            }
            else if (number1[i] < number2[i]){
                if(*number1=='-'  &&  *number2=='-'){
                    return 1;
                }
                return -1;
            } 
        }
    }
    return 0;
}



void push(char* number, int& length){
    for(int i=length-1; i>=0; i--){
        if(number[i]=='-'){
            continue;
        }
        number[i+1] = number[i];
    }
    if(number[0] == '-'){
        number[1] = '0';
    }
    else{
        number[0] = '0';
    }
    length++;
}


void removeZeroes(char* number, int& length){
    int count=0;
    if(number[0] == '-' && number[1]!='0'){
        return;
    }
    for(int i=0; i<length; i++){
        if(number[i]=='-'){
            continue;
        }
        else if(number[i]=='0'){
            count++;
        }
        else if(number[i]!='0'){
            break;
        }
    }

    for(int i=0; i<count; i++){
        if (length == 1){
            break;
        }
        for(int j=0; j<length; j++){

            if(number[j]=='-'){
                continue;
            }
            number[j] = number[j+1];
            number[j+1] = '\0';
        }
        length--;
    }
}



void alignLesserNumberToBigger(char* number1, char* number2){
    int length1 = getLength(number1);
    int length2 = getLength(number2);
    while(length1>length2){
        push(number2,length2);
    }
    while(length1<length2){
        push(number1,length1);
    }
}


void removeMinus(char* number){
    int length = getLength(number);
    for(int i=1; i<length; i++){
        number[i-1] = number[i];
    }
    number[length-1] = '\0';
}

void addMinus(char* number){
    int length = getLength(number);
    push(number,length);
    number[0] = '-';
}


void sum(char* number1, char* number2){
    if(number1[0] == '0'){
        cout << number2;
        return;
    }
    if(number2[0] == '0'){
        cout << number1;
        return;
    }
    char result[maxLength];
    int sum;
    //<----------------------------- START OF (a) + (-b)  and  (-a) + (b) ------------------------>
    if(number1[0]=='-' && number2[0]!='-'){
        removeMinus(number1);
        difference(number2,number1);
        addMinus(number1);
    }
    else if(number1[0]!='-' && number2[0]=='-'){
        removeMinus(number2);
        difference(number1,number2);
        addMinus(number2);
    }

    //<----------------------------- END OF (a) + (-b)  and  (-a) + (b) ------------------------>


    //<----------------------------- START OF (a) + (b) and (-a) + (-b) ------------------------>

    else{
        if(getLength(number1)!=getLength(number2)){
            alignLesserNumberToBigger(number1,number2);
        }

        int nextsum = 0;
        int resultLength = getLength(number1);
        for (int i=getLength(number1)-1; i>=0; i--){
            sum = nextsum;
            nextsum = 0;
            sum += (int)number1[i] - '0' + (int)number2[i] - '0';
            result[i] = (char)sum + '0';

            if(result[i] > '9'){
                if(number1[0]=='-' && number2[0]=='-'){
                    if(i==1){
                        result[i] = result[i]-10;
                        push(result,resultLength);
                        result[1] = '1';
                    }
                    else{
                        result[i] -= 10;
                        nextsum++;
                    }
                }
                else{
                    if(i==0){
                        result[i] = result[i]-10;
                        push(result,resultLength);
                        result[0] = '1';
                    }
                    else{
                        result[i] -= 10;
                        nextsum++;
                    }
                }
            }    
        }
        if(number1[0]=='-' && number2[0]=='-'){
            result[0] = '-';
        }


                //<------- Print Result --------->
                for(int i=0; i<resultLength; i++){
                    cout << result[i];
                }
    }
    //<----------------------------- END OF (a) + (b)  ------------------------>


    int length1 = getLength(number1);
    int length2 = getLength(number2);
    removeZeroes(number1,length1);
    removeZeroes(number2,length2);
}





void difference(char* number1, char* number2){
    if(number2[0] == '0'){
        cout << number1;
        return;
    }
    //<----------------------------- START OF (a) - (-b)  and  (-a) - (b)  and  (-a) - (-b)  ------------------------>

    if (number1[0]!='-' && number2[0]=='-'){
        removeMinus(number2);
        sum(number1,number2);
        addMinus(number2);
    }
    else if (number1[0]=='-' && number2[0]!='-'){
        int length2 = getLength(number2);
        addMinus(number2);
        sum(number1,number2);
        removeMinus(number2);
    }
    else if (number1[0]=='-' && number2[0]=='-'){
        removeMinus(number2);
        sum(number1,number2);
        addMinus(number2);
    }
    //<----------------------------- END OF (a) - (-b)  and  (-a) - (b)  and  (-a) - (-b) ------------------------>


    //<-----------------------------START OF (a) - (b) ------------------------>
    else{
        if(comparison(number1,number2)==0){
            cout << "0";
            return;
        }

        int length1 = getLength(number1);
        int length2 = getLength(number2);
        char result[maxLength];
        int difference;
        if(length1>length2){
            alignLesserNumberToBigger(number1,number2);
            int difference;
            int nextdifference = 0;
            for(int i=length1-1; i>=0; i--){
                difference = nextdifference;
                nextdifference = 0;
                difference += (int)number1[i] - (int)number2[i];
                if(difference < 0){
                    difference = 10 + difference;
                    nextdifference -= 1;
                }
                result[i] = difference + '0';
            }
        }
        else if(length1<length2){
            alignLesserNumberToBigger(number1,number2);
            int difference;
            int nextdifference = 0;
            for(int i=length2-1; i>=0; i--){
                difference = nextdifference;
                nextdifference = 0;
                difference += (int)number2[i] - (int)number1[i];
                if(difference < 0){
                    difference = 10 + difference;
                    nextdifference -= 1;
                }
                result[i] = difference + '0';
            }
            int resultlength = getLength(number2);
            push(result,resultlength);
            result[0] = '-';
        }
        else{
            
            if(comparison(number1,number2)==1){
                int difference;
                int nextdifference = 0;
                for(int i=length1-1; i>=0; i--){
                    difference = nextdifference;
                    nextdifference = 0;
                    difference += (int)number1[i] - (int)number2[i];
                    if(difference < 0){
                        difference = 10 + difference;
                        nextdifference -= 1;
                    }
                    result[i] = difference + '0';
                }
            } 
            
            else if(comparison(number1,number2)==-1){
                int difference;
                int nextdifference = 0;
                for(int i=length1-1; i>=0; i--){
                    difference = nextdifference;
                    nextdifference = 0;
                    difference += (int)number2[i] - (int)number1[i];
                    if(difference < 0){
                        difference = 10 + difference;
                        nextdifference -= 1;
                    }
                    result[i] = difference + '0';
                }
                int resultlength = getLength(number2);
                push(result,resultlength);
                result[0] = '-';
            }
        }
        int resultlength = getLength(result);
        removeZeroes(result,resultlength);
        for(int i=0; i<resultlength; i++){
            cout << result[i];
        }
    }
    //<-----------------------------END OF (a) - (b) ------------------------>


    //<--------- Repair Numbers (IF NEEDED) ------------>
    int length1 = getLength(number1);
    int length2 = getLength(number2);
    removeZeroes(number1,length1);
    removeZeroes(number2,length2);
}

int max(const int a, const int b){
    return a > b ? a : b;
}




void multipy(char* number1, char* number2){
    if(number1[0]=='0' || number2[0]=='0'){
        cout << "0";
        return;
    }
    bool bothNumbersHaveAMinus = number1[0] == '-' && number2[0] == '-';
    bool number1HasMinus = number1[0] == '-';
    bool number2HasMinus = number2[0] == '-';

    if(bothNumbersHaveAMinus){
        removeMinus(number1);
        removeMinus(number2);
    }
    else if(number1HasMinus){
        removeMinus(number1);
    } 
    else if(number2HasMinus){
        removeMinus(number2);
    }

    if (number1[0]=='0' || number2[0]=='0'){
        cout << "0";
        return;
    }

    int length1 = getLength(number1); 
    int length2 = getLength(number2); 
    int resultInt[maxLength]; 
  
    int index1 = 0;  
    int index2 = 0;  
      
    for (int i=length1-1; i>=0; i--) 
    { 
        int nextsum = 0; 
        int num1 = number1[i] - '0'; 
  
        index2 = 0;  
                  
        for (int j=length2-1; j>=0; j--) 
        { 
            int num2 = number2[j] - '0'; 
            int sum = num1*num2 + resultInt[index1 + index2] + nextsum; 
  
            nextsum = sum/10; 
            resultInt[index1 + index2] = sum % 10; 

            index2++; 
        } 
  
        if (nextsum > 0) 
            resultInt[index1 + index2] += nextsum; 
  
        index1++; 
    } 

    char result[maxLength];

    for (int i=0; i<length1+length2+1; i++){
        result[length1+length2-i] = resultInt[i] + '0';
    }



    if(bothNumbersHaveAMinus){
        addMinus(number1);
        addMinus(number2);
    }
    else if(number1HasMinus){
        addMinus(number1);
        addMinus(result);
    } 
    else if(number2HasMinus){
        addMinus(number2);
        addMinus(result);
    } 

    //<--------------- Print Result -------------->
    int resultlength = getLength(result);
    removeZeroes(result,resultlength);
    for (int i=0; i<resultlength; i++){
        cout << result[i];
    }


}




int main(){
    char firstNumber[maxLength];
    char secondNumber[maxLength];
    cout << "Enter first number: ";
    readCorrectNumber(firstNumber);
    cout << "Enter second number: "; 
    readCorrectNumber(secondNumber);
    cout << "First number: ";
    printNumber(firstNumber);
    cout << "Second number: ";
    printNumber(secondNumber);
    if (isEqual(firstNumber,secondNumber)){
        cout << firstNumber << " == " << secondNumber << endl;
    } else {
        cout << firstNumber << " != " << secondNumber << endl;
    }
    if ((comparison(firstNumber,secondNumber))==1){
        cout << firstNumber << " > " << secondNumber <<endl;
    } else if ((comparison(firstNumber,secondNumber))==-1){
        cout << firstNumber << " < " << secondNumber <<endl;
    } else if ((comparison(firstNumber,secondNumber))==0){
        cout << firstNumber << " = " << secondNumber <<endl;
    }
    cout << firstNumber << " + " << secondNumber << " = ";
    sum(firstNumber,secondNumber);
    cout << endl;
    cout << firstNumber << " - " << secondNumber << " = ";
    difference(firstNumber,secondNumber);
    cout << endl;
    cout << firstNumber << " * " << secondNumber << " = ";
    multipy(firstNumber,secondNumber);
    cout << endl;



    return 0;
}