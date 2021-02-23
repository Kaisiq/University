#include <iostream>
using namespace std;



//task 0
void printDigitsBackwardsHelper(int n, int toBeUsed){
    if(n<0){
        return;
    }
    if(toBeUsed<=0){
        return;
    }

    cout << toBeUsed%10 << " ";


    printDigitsBackwardsHelper(n,toBeUsed/10);
}

void printDigitsBackwards(const int n){
    if(n==0){
        cout << 1;
        return;
    }
    printDigitsBackwardsHelper(n,n);
}





//task 0a
void printDigitsHelper(int n, int toBeUsed){
    if(n<0){
        return;
    }
    if(toBeUsed<=0){
        return;
    }

    printDigitsHelper(n,toBeUsed/10);
    cout << toBeUsed%10 << " ";
}

void printDigits(const int n){
    if(n==0){
        cout << 1;
        return;
    }
    printDigitsHelper(n,n);
}




//task 0b
void printString(const char* str, int i=0){
    if(str[i]==0){
        return;
    }
    cout << str[i];
    printString(str, i+1);
}



//task 1
void printSeveral(const char sym, const int n){
    if(n<=0){
        return;
    }
    cout << sym;
    printSeveral(sym, n-1);
}



//task 2
void printK(const int size){
    if(size<0){
        return;
    }
    cout << "*";
    if(size==0){
        cout << "*";
        return;
    }
    for(int i=0;i<size;i++){
        cout << " ";
    }
    cout << "*";
    cout << endl;
    printK(size-1);
    cout << endl;
    cout << "*";
    if(size==0){
        return;
    }
    for(int i=0;i<size;i++){
        cout << " ";
    }
    cout << "*";
}


//task 3
void printLetters(const char start, const char end){
    if(start>end){
        return;
    }
    cout << start << " ";
    printLetters(start+1, end);
}




//task 4

int OnesInBinary(int n, int count=0){
    if(n==0){
        return count;
    }
    if(n & 1){
        count++;
    }
    OnesInBinary(n/2, count);
}



//task 4a
int OnesInBinaryV2(int n, int count=0){
    if(n==0){
        return count;
    }
    if(n & 1){
        count++;
    }
    OnesInBinaryV2(n>>1, count);
}




//task 5
unsigned int cache[100] = {0,};
unsigned int calculateFib(const int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(cache[n-1] == 0){
        cache[n-1] = calculateFib(n-1);
    }
    if(cache[n-2] == 0){
        cache[n-2] = calculateFib(n-2);
    }
    return cache[n-1]+cache[n-2];
}



unsigned int calculateFibV2(const int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int curr = 1;
    int prev = 0;
    for (int i=1; i<n; i++){
        unsigned int next = curr + next;
        prev = curr;
        curr = next;
    }
    return curr;
}




//task 5a
bool isFib(const int n, int fibonacci=0){
    if(n==calculateFib(fibonacci)){
        return true;
    }
    if(n<calculateFib(fibonacci)){
        return false;
    }
    if(n>calculateFib(fibonacci)){
        return isFib(n,fibonacci+1);
    }
}




//task 6
void toHex(const unsigned int n, int i=0){
    if(n<=0){
        return;
    }
    int rem = n%16;
    if(rem>=0 && rem<=9){
        cout << rem;
    }
    else{
        switch (rem) {
            case 10: rem = 'A'; break;
            case 11: rem = 'B'; break;
            case 12: rem = 'C'; break;
            case 13: rem = 'D'; break;
            case 14: rem = 'E'; break;
            case 15: rem = 'F'; break;
        }
        cout << (char)rem;
    }
    toHex(n/16,i+1);
}




//task 6a
int toHexCalc(const unsigned int n, int i=0,int count=0){
    if(n<=0){
        return count;
    }
    int rem = n%16;
    if(rem>9 && rem<16){
        switch (rem) {
            case 10: rem = 'A'; break;
            case 11: rem = 'B'; break;
            case 12: rem = 'C'; break;
            case 13: rem = 'D'; break;
            case 14: rem = 'E'; break;
            case 15: rem = 'F'; break;
        }
        count++;
    }
    return toHexCalc(n/16,i+1, count);
}


int Ermit(int n, int x){
    if (n<0){
        return 0;
    }
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 2*x;
    }
    return 2*x*Ermit(n-1,x)-2*(n-1)*Ermit(n-2,x);
}






int main(){
    // printDigits(5);
    // cout << endl;
    // printDigits(125);
    // cout << endl;
    // printString("asd");
    // cout << endl;
    // printSeveral('4',123);
    // cout << endl;
    // printK(6);
    // cout << endl;
    // printLetters('C','J');
    // cout << endl;
    // cout << OnesInBinary(128);
    // cout << OnesInBinaryV2(127);
    // cout << endl;
    cout << calculateFibV2(50);
    // cout << endl;
    // cout << isFib(13);
    // cout << endl;
    // toHex(162646464);
    // cout << endl;
    // cout << toHexCalc(162646464);
    // cout << endl;
    // cout << Ermit(7,4);

    return 0;
}