#include <iostream>

int main(){
    int a = 0;
    std::cin >> a;
    if (a<=59){
        std::cout << "your Grade is F";
    }
    else if (a<=69){
        std::cout << "your grade is D";
    }
    else if (a<=79){
        std::cout << "your grade is C";
    }
    else if (a<=89){
        std::cout << "your grade is B";
    }
    else {
        std::cout << "your grade is A";
    }
}