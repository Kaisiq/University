#pragma once
#include <fstream>
#include <iostream>
#include "Vehicle.h"
#include "../Vehiclelist/Vehiclelist.cpp"


Vehicle::Vehicle(const char* regNum, const char* description)
{
  this-> reg = Registration(regNum);
  if(Vehiclelist::getInstance()->duplicateReg(*this)){
    throw std::invalid_argument("Registration Duplication\n");
  }
  this->description = description;
  this->owner = nullptr;
  Vehiclelist::getInstance()->addVehicle(*this);
}


const Registration Vehicle::getRegNum() const{
  return this->reg;
}

const std::string Vehicle::getDesc()const{
  return this->description;
}

void Vehicle::addOwner(Person* p) {
  this->owner = p;
}
void Vehicle::removeOwner(){
  this->owner = nullptr;
}

Person* Vehicle::getOwner(){
  return this->owner;
}

bool Vehicle::hasOwner(){
  return this->owner;
}


std::ofstream& operator << (std::ofstream& out, Vehicle& v){
  out << "VEHICLE " <<  v.getRegNum().toString() << " \"" << v.getDesc() << "\"";
  return out;
}

void Vehicle::print() {
  std::cout << "Registration number: " << this->getRegNum().toString() << "; Description: " << this->getDesc() << "\n";
}

