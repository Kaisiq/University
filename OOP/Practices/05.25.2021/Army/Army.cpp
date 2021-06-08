#include "Army.h"
#include <cassert>
Army::Army(){}
Army::Army(std::initializer_list<Unit*> units){
  for(int i=0; i<units.size(); i++){
    pushBack(*(units.begin()+i));
  }
}
Army::Army(const Army& other){
  for(int i=0; i<other.army.size(); i++){
    this->army.push_back(other.army[i]);
  }
}
Army::Army(Army&& other){}
Army& Army::operator=(const Army& other){
  if(this != &other){
    this->copy(other);
  }
  return *this;
}
Army& Army::operator=(Army&& other){
  if(this != &other){
    this->copy(other);
  }
  return *this;
}
Army::~Army(){
  this->army.clear();
}

const Unit* const& Army::operator[](size_t index) const{
  assert(index < this->army.size());
  return this->army[index];
}
Unit*& Army::operator[](size_t index){
  assert(index < this->army.size());
  return this->army[index];
}

void Army::pushBack(Unit* unit){
  this->army.push_back(unit);
}

Army& Army::goToWar(Army& other){
  int i=0;
  int j=0;
  while(i<this->army.size()  &&  j<other.army.size()){
    if(&this->army[i]->duel(*other.army[j]) == this->army[i]){
      j++;
    }
    else{
      i++;
    }
  }
  if(i==this->army.size()){
    std::cout << "Army two won!\n";
    return other;
  }
  else if (j==other.army.size()){
    std::cout << "Army one won!\n";
    return *this;
  }
  else if(i==this->army.size() && j==other.army.size()){
    throw std::runtime_error("Both armys have won!\n");
  }
  else{
    throw std::runtime_error("No army has won!\n");
  }
}

const size_t Army::getSize() const{
  return this->army.size();
}
const size_t Army::getCapacity() const{

}