#pragma once
#include "../Person/Person.cpp"
#include "Peoplelist.h"
#include "../Vehiclelist/Vehiclelist.cpp"

void Peoplelist::addPerson(Person p){
  getInstance()->people.push_back(p);
  std::cout << "Person was added.\n";
}

bool Peoplelist::duplicateID(Person p){
  for(int i=0; i < people.size(); i++){
    if(people[i].getID() == p.getID()){
      return true;
    }
  }
  return false;
}

bool Peoplelist::isEmpty(){
  return people.empty();
}

void Peoplelist::removePerson(const unsigned int ID){
  for(int i=0; i<people.size(); i++){
    if(people.at(i).getID() == ID){
      people.erase(people.begin()+i);
      std::cout << "Person with ID " << ID << " was removed\n";
      return;
    }
    if(i==people.size()-1){
      throw std::out_of_range("Couldn't find Person with such an ID in the peoplelist!\n");
    }
  }
}

void Peoplelist::clearPeople(){
  people.clear();
  std::cout << "People List was cleared\n";
}

Person* Peoplelist::getPerson(const unsigned int ID){
  for(int i=0; i<people.size(); i++) {
    if (people.at(i).getID() == ID) {
      return &people[i];
    }
  }
  throw std::out_of_range("Couldnt find person\n");
}

void Peoplelist::addVehicleToPerson(const unsigned int ID, Vehicle& v){
  for(int i=0; i<people.size(); i++) {
    if (people.at(i).getID() == ID) {
      people[i].addVehicle(v);
      v.addOwner(&people[i]);
      std::cout << "Vehicle with registration number " << v.getRegNum().toString() << " was added to person with ID " << ID << "\n";
    }
  }
}

void Peoplelist::addVehicleToPerson(const unsigned int ID, const char* regNum){
  for(int i=0; i<people.size(); i++) {
    if (people.at(i).getID() == ID) {
      people[i].addVehicle(regNum);
      Vehiclelist::getInstance()->getVehicle(regNum)->addOwner(&people[i]);
      std::cout << "Vehicle with registration number " << regNum << " was added to person with ID " << ID << "\n";
    }
  }
}

void Peoplelist::removeVehicleFromPerson(const unsigned int ID, const char* regNum){
  for(int i=0; i<people.size(); i++) {
    if (people.at(i).getID() == ID) {
      people[i].removeVehicle(regNum);
      std::cout << "Vehicle with registration number " << regNum << " was removed from person with ID " << ID << "\n";
    }
  }
}


std::ofstream& operator << (std::ofstream& out, Peoplelist& pl){
  for(int i=0; i<pl.people.size(); i++){
    out << pl.people[i] << "\n";
  }
  return out;
}
std::ifstream& operator >> (std::ifstream& in, Peoplelist& pl){
  char dummy;
  for(int i=0; i<pl.people.size(); i++){
    in >> pl.people[i] >> dummy;
  }
  return in;
}

void Peoplelist::print() {
  int countTo = people.size();
  for(int i=0; i<countTo; i++){
    people[i].print();
  }
}