#include "Branch.h"

Branch::Branch(){
}

Branch::Branch(char* address, int coef, unsigned int ID){
  this->ID = ID;
  this->address = address;
  this->coefficient = coef;
}
Branch::~Branch(){
  delete[] this->address;
}
Branch::Branch(const Branch& rhs){
  this->coefficient = rhs.coefficient;
  this->address = rhs.address;
  this->ID = rhs.ID;
}
Branch &Branch::operator=(const Branch& rhs){
  if(this == &rhs){
    return *this;
  }
  this->coefficient = rhs.coefficient;
  this->address = rhs.address;
  this->ID = rhs.ID;
  return *this;
}
void Branch::operator++(){
  this->coefficient ++;
}
const int Branch::getCoef() const{
  return this->coefficient;
}
std::ostream &operator<<(std::ostream& out, const Branch &branch) {
  out << "Branch " << branch.ID << " " << branch.address << " " << branch.coefficient << "\n";
  return out;
}
std::istream& operator>>(std::istream& in, Branch& branch) {
  char dummy[10];
  in >> dummy;
  in >> branch.ID;
  in >> branch.address;
  in >> branch.coefficient;
  return in;
}
