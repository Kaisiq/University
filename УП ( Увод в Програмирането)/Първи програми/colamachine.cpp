#include <iostream>

int main (){
    int a = 0;
    std::cin >> a;
    switch (a) {
        case 1:
            std::cout<<"Cola";
            break;
        case 2:
            std::cout<<"Fanta";
            break;
        case 3:
            std::cout<<"Sprite";
            break;
        case 4:
            std::cout<<"Mirinda";
            break;
        case 5:
            std::cout<<"Water";
            break;
        default: 
            std::cout<<"Error. choice was not valid, here is your money back.";
    }
}