#pragma once
#include "MyString.h"
#include <cstring>
#include <cassert>

MyString::MyString()
{
  this->string = nullptr;
  this->len = 0;
}


MyString::~MyString(){
  delete[] this->string;
}


bool MyString::setString(const char* str){
  this->len = strlen(str);
  assert(len>=0);

  char* tmpStr = new (std::nothrow) char[len + 1];
  if(!tmpStr){
    return false;
  }
  strncpy(tmpStr,str,len);
  tmpStr[len] = '\0';
  if(this->string != nullptr) {
    delete[] this->string;
  }
  this->string = tmpStr;
  return true;
}

const char* MyString::getString() const{
  return this->string;
}

MyString::MyString(const MyString& str){
  this->len = str.len;
  if(!setString(str.getString())){
    std::cout << "No Memory.";
  }
}

MyString::MyString(const char* str){
  this->len = strlen(str);
  if(!setString(str)){
    std::cout << "No memory.";
  }
}

char& MyString::at (std::size_t pos){
  if(pos<=(this->len)){
    return this->string[pos-1];
  }
  else{
    throw std::out_of_range(this->string);    // <------------------Idk if this even works
  }
}

const char& MyString::at(std::size_t pos) const{
  if(pos<=(this->len)){
    return this->getString()[pos-1];
  }
  else{
    throw std::out_of_range(this->getString());    // <------------------Idk if this even works
  }
}
char& MyString::operator[](std::size_t pos){
  assert(pos<=len);
  return this->string[pos-1];
}

const char& MyString::operator[](std::size_t pos) const{
  assert(pos<=len);
  return this->getString()[pos-1];
}
char& MyString::front(){
  assert(len>0);
  return *this->string;
}
const char& MyString::front() const{
  assert(len>0);
  return this->getString()[0];
}
char& MyString::back(){
  assert(len>0);
  return this->string[len-1];
}
const char& MyString::back() const{
  assert(len>0);
  return this->getString()[len-1];
}
bool MyString::empty() const{
  return len==0;
}
std::size_t MyString::size() const{
  return this->len;
}
void MyString::clear(){
  this->len = 0;
  delete[] this->string;
  this->string = nullptr;
}
void MyString::push_back(char c){
  this->len += 1;
  char* result = new(std::nothrow) char[len+1];
  if(!result){
    std::cout << "No Memory";
  }
  strncpy(result,this->getString(),len-1);
  result[len-1] = c;
  result[len] = '\0';
  delete[] this->string;
  this->string = result;
}
void MyString::pop_back(){
  assert(len>=1);
  this->len -= 1;
  char* result = new(std::nothrow) char[len-1];
  if(!result){
    std::cout << "No Memory";
  }
  strncpy(result,getString(),len);
  result[len] = '\0';
  delete[] this->string;
  this->string = result;
}
MyString& MyString::operator+=(char c){
  this->len += 1;
  char* result = new(std::nothrow) char[len+1];
  if(!result){
    std::cout << "No Memory";
  }
  strncpy(result,this->getString(),len-1);
  result[len-1] = c;
  result[len] = '\0';
  delete[] this->string;
  this->string = result;

  return *this;
}
MyString& MyString::operator+=(const MyString& rhs){
  int resultLen = this->len + rhs.size() - 1;
  char* result = new (std::nothrow) char[resultLen+1];
  if(!result){
    std::cout<< "No Memory.";
  }
  strcpy(result,this->getString());
  strcat(result,rhs.getString());
  this->len = resultLen;
  delete[] this->string;
  this->string = result;
}

MyString MyString::operator+(char c) const{
  MyString result;
  result.len = this->len + 1;
  char* resultStr = new (std::nothrow) char[result.size()+1];
  if(!resultStr){
    std::cout << "No Memory";
  }
  strncpy(resultStr,this->getString(),this->len);
  resultStr[result.size()-1] = c;
  resultStr[result.size()] = '\0';
  result.setString(resultStr);
  return result;
}

MyString MyString::operator+(const MyString& rhs) const{
  MyString result;
  int resultLen = this->len + rhs.size() - 1;
  char* resultStr = new (std::nothrow) char[resultLen+1];
  if(!resultStr){
    std::cout<< "No Memory.";
  }
  strcpy(resultStr,this->getString());
  strcat(resultStr,rhs.getString());
  result.len = resultLen;
  result.setString(resultStr);
  return result;
}


const char* MyString::c_str() const{
  char* result = new (std::nothrow) char[this->len+1];
  strncpy(result,this->getString(),this->len);
  result[len] = '\0';
  return result;
}

bool MyString::operator==(const MyString &rhs) const{
  if(this->len!=rhs.size()){
    return false;
  }
  for(int i=0; i<this->len; i++){
    if(this->getString()[i] != rhs.getString()[i]){
      return false;
    }
  }
  return true;
}
bool MyString::operator<(const MyString &rhs) const{
  if(this->size() >= rhs.size()){
    int n = rhs.size();
    for(int i=0; i<n; i++){
      if((int)this->getString()[i] < (int)rhs.getString()[i]){
        return true;
      }
    }
    return false;
  }
  else{
    int n = this->size();
    for(int i=0; i<n; i++) {
      if ((int)this->getString()[i] < (int)rhs.getString()[i]) {
        return true;
      }
      return false;
    }
  }
}