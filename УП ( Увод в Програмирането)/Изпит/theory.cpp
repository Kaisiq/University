#include <iostream>
void mistery(const char* const text) {
    std:: cout << (*text ? (mistery(text+1), *text) : '\n');
    return;
}
int main(){
    mistery("abcd");
    return 0;
}