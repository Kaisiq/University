#include "Bank.h"
#include <cassert>


Bank::Bank(std::string name, unsigned int clients){
  this->name = name;
  this->clients = clients;
  this->branches = new(std::nothrow) Branch[10];
  this->ID = num++;

}

Bank::~Bank(){
  delete[] this->branches;
}

Bank::Bank(const Bank& rhs){
  this->name = rhs.name;
  this->clients = rhs.clients;
  this->branches = rhs.branches;
  this->ID = num++;
}

Bank &Bank::operator=(const Bank& rhs){
  if(this==&rhs){
    return *this;
  }
  this->branches = rhs.branches;
  this->name = rhs.name;
  this->clients = rhs.clients;
  return *this;
}

void Bank::operator++(int id){
  assert(id<10);
  this->branches[id].operator++();
}

const int Bank::getCoef() const{
  int coefficient = 0;
  for(int i=0; i<10; i++){
    coefficient += this->branches[i].getCoef();
  }
  coefficient/=10;
  return coefficient;
}

const int Bank::getWorstCoef() const{
  int min = this->branches[0].getCoef();
  for(int i=1; i<10; i++){
    if(min>this->branches[i].getCoef()){
      min = branches[i].getCoef();
    }
  }
  return min;
}


Bank &Bank::operator+=(Bank& rhs){
  Bank copy = *this;

  for(int i=0; i<9; i++){
    for(int j=i+1; j<10; j++){
      if(copy.branches[i].getCoef() < copy.branches[j].getCoef()){
        std::swap(copy.branches[i],copy.branches[j]);
      }
    }
  }
  for(int i=0; i<9; i++){
    for(int j=i+1; j<10; j++){
      if(rhs.branches[i].getCoef() < rhs.branches[j].getCoef()){
        std::swap(rhs.branches[i],rhs.branches[j]);
      }
    }
  }

  int count1=0;
  int count2=0;
  int count=0;
  while(count<10){
    if(copy.branches[count1].getCoef() > rhs.branches[count2].getCoef()){
      this->branches[count] = copy.branches[count1];
      count1++;
    }
    else{
      this->branches[count] = rhs.branches[count2];
      count2++;
    }
    count++;
  }

  for(int i=0; i<9; i++){
    for(int j=i+1; j<10; j++){
      if(this->branches[i].getCoef() < this->branches[j].getCoef()){
        std::swap(this->branches[i],this->branches[j]);
      }
    }
  }
  this->clients+=rhs.clients;
  return *this;
}



const unsigned int Bank::getBankCount() const{
  return ID;
}

void compareTwoBanks(Bank& bank1, Bank& bank2){
  if(bank1.getCoef() > bank2.getCoef()){
    bank1.clients++;
    bank2.clients--;
  }
  else if(bank1.getCoef() < bank2.getCoef()){
    bank2.clients++;
    bank1.clients--;
  }
}

std::ostream& operator << (std::ostream& out, const Bank& bank){
  out << "Bank " << bank.ID << " " << bank.name << " " << bank.clients << " [\n";
  for(int i=0; i<10; i++){
    out << bank.branches[i];
  }

  out << "]";

  return out;
}

std::istream& operator >> (std::istream& in, Bank &bank){
  char dummy[10];
  in >> dummy;
  in >> bank.ID;
  in >> bank.name;
  in >> bank.clients;

  for(int i=1; i<10; i++){
    in >> bank.branches[i];
  }
  return in;
}


