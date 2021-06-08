#pragma once
#include "Registration.h"
#include <iostream>
#include <cstring>
#include <cassert>


bool isNumber(char a){
  return a<='9' && a>='0';
}

bool isSymbol(char a){
  return a>='A' && a<='Z';
}

bool oneSymFourNumsTwoSym(const char* str){
  return (isSymbol(str[0]) && isNumber(str[1]) && isNumber(str[2]) && isNumber(str[3]) && isNumber(str[4]) && isSymbol(str[5]) && isSymbol(str[6]));
}

bool twoSymFourNumsTwoSym(const char* str){
  return (isSymbol(str[0]) && isSymbol(str[1]) && isNumber(str[2]) && isNumber(str[3]) && isNumber(str[4]) && isNumber(str[5]) && isSymbol(str[6]) && isSymbol(str[7]));
};

bool isValidRegistration(const char* str){
  return oneSymFourNumsTwoSym(str) || twoSymFourNumsTwoSym(str);
}

Registration::Registration(){}

Registration::Registration(const char *str) {
  if(!isValidRegistration(str)){
    throw std::invalid_argument("Invalid Registration\n");
  }
  strncpy(this->registration, str, 8);
}

Registration& Registration::operator=(const char* str){
  if(!isValidRegistration(str)){
    throw std::invalid_argument("Invalid Registration\n");
  }
  strncpy(this->registration, str, 8);
  return *this;
}
bool Registration::operator==(const char* str) const{
  size_t countTo = strlen(this->registration);
  for(int i=0; i<countTo; i++){
    if(str[i] != this->registration[i]){
      return 0;
    }
  }
  return 1;
}
const char *Registration::toString() const {
    size_t len = strlen(this->registration);
    try {
      char *result = new char[len + 1];
      strcpy(result,this->registration);
      result[len] = 0;
      return result;
    }
    catch(std::bad_alloc& e){
      std::cerr << "Couldn't allocate memory to create string.\n";
      throw;
    }
}
