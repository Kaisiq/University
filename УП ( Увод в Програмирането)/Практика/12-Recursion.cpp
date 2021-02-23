#include <iostream>
using namespace std;




//task 1
int factoriel(int n){
    if (n==0){
        return 1;
    }
    return n*factoriel(n-1);
}





//task 2
bool isPrime(int n, int i = 2){
    if(n==2){
        return true;
    }
    if(n % i == 0){
        return false;
    }
    if(i*i>n){
        return true;
    }
    return isPrime(n,i+1);

    
}



//task 3
void printbytes(int n, int i=32){
    if(i==0){
        return;
    }
    printbytes(n/2, i-1);
    cout << (n & 1);
}




//task 4
void numberOfZeroesAndOnes(int n, int i=31, int zeroes = 0, int ones = 0){

    if(i==0){
        cout << zeroes << "    " << ones;
        return;
    }
    if(n%2){
        numberOfZeroesAndOnes(n/2, i-1, zeroes, ones+1);
    }
    else{
        numberOfZeroesAndOnes(n/2, i-1, zeroes+1, ones);
    }

}




//task 5
void printDigitsOfNumber(int n){
    if(n==0){
        return;
    }
    printDigitsOfNumber(n/10);
    cout << n%10 << " ";

}




//task 6
void printDigitsOfNumberBack(int n){
    if(n==0){
        return;
    }
    cout << n%10 << " ";
    printDigitsOfNumberBack(n/10);
}




//task 7



int powersOfTen(int n){
    if(n == 0){
        return 1;
    }
    return 10*powersOfTen(n-1);
}


void printTens(int n, int i=1){
    if(i>n){
        return;
    }
    cout << powersOfTen(i) << " ";
    printTens(n,i+1);
    cout << powersOfTen(i) << " ";
}






//task 8
int euklidNOD(int a, int b){
    if(b==0){
        return a;
    }
    else{
        euklidNOD(b,a%b);
    }
}









int main(){
    // cout << isPrime(13);
    // printbytes(10);
    // numberOfZeroesAndOnes(10);
    // printDigitsOfNumber(12345);
    // printTens(3);
    // return 0;
    cout << euklidNOD(1071,1029);
}