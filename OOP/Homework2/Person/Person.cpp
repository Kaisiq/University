#pragma once
#include "Person.h"
#include "../Peoplelist/Peoplelist.cpp"
#include <fstream>
#include <iostream>


Person::Person(const std::string name, const unsigned int ID){
  this->name = name;
  this->ID = ID;
  if(Peoplelist::getInstance()->duplicateID(*this)) {
    throw std::invalid_argument("Duplicate ID\n");
  }
  Peoplelist::getInstance()->addPerson(*this);
}

std::string Person::getName() const{
  return this->name;
}
unsigned int Person::getID() const{
  return this->ID;
}

bool Person::hasVehicles(){
  return !this->vehicles.empty();
}


void Person::addVehicle(Vehicle& v){
  this->vehicles.push_back(v);
}


int Person::findVehicle(const Vehicle& v){
  for(int i=0; i<this->vehicles.size(); i++){
    if(strcmp(this->vehicles.at(i).getRegNum().toString(), v.getRegNum().toString())==0){
      return i;
    }
  }
  throw std::out_of_range("Couldn't find Vehicle.\n");
}

int Person::findVehicleByRegnum(const char* regnum){
  for(int i=0; i<this->vehicles.size(); i++){
    if(strcmp(this->vehicles.at(i).getRegNum().toString(), regnum)==0){
      return i;
    }
  }
  throw std::out_of_range("ID of Vehicle not found\n");
}

Vehicle* Person::getVehicleViaID(const int id){
  return &this->vehicles[id];
}


Vehicle* Person::getVehicleViaReg(const char* regnum){
  for(int i=0; i<this->vehicles.size(); i++){
    if(strcmp(this->vehicles.at(i).getRegNum().toString(), regnum)==0){
      return &vehicles[i];
    }
  }
  throw std::out_of_range("Vehicle not found\n");
}


unsigned int Person::vehiclesCount(){
  return this->vehicles.size();
}

void Person::addVehicle(const char* regnum){
  this->vehicles.push_back(*Vehiclelist::getInstance()->getVehicle(regnum));
  Vehiclelist::getInstance()->getVehicle(regnum)->addOwner(this);
}

void Person::removeVehicle(Vehicle& v){
  this->vehicles.erase(vehicles.cbegin()+ findVehicle(v));
  v.removeOwner();
}

void Person::removeVehicle(const char* regnum){
  vehicles[findVehicleByRegnum(regnum)].removeOwner();
  this->vehicles.erase(vehicles.cbegin()+ findVehicleByRegnum(regnum));
}

const char* Person::getReg(int i){
  return vehicles[i].getRegNum().toString();
}

std::ofstream& operator << (std::ofstream& out, Person& person){
  out << "PERSON \"" << person.getName() << "\" " << person.getID();
  for(auto i=person.vehicles.begin(); i!=person.vehicles.end(); ++i){
    out << "\nACQUIRE " << person.getID() << " " << i->getRegNum().toString();
  }
  return out;
}

std::ifstream& operator >> (std::ifstream& in, Person& person){
  char dummy[10];
  in >> dummy;
  in >> person.name;
  in >> dummy;
  in >>  person.ID;
  return in;
}

void Person::print() const{
 std::cout << "Name: " << this->getName() << "; ID: " << this->getID() << "\n";
}