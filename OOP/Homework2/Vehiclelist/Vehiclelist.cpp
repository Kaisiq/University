#pragma once
#include "Vehiclelist.h"
#include "../Person/Person.cpp"

void Vehiclelist::addVehicle(Vehicle& v){
  getInstance()->vehicles.push_back(v);
  std::cout << "Vehicle was added.\n";
}

bool Vehiclelist::duplicateReg(Vehicle& v){
  for(int i=0; i< getInstance()->vehicles.size(); i++){
    if(strcmp(vehicles[i].getRegNum().toString(), v.getRegNum().toString())==0){
      return 1;
    }
  }
  return 0;
}

void Vehiclelist::removeVehicle(const char* regNum){
  for(int i=0; i<Vehiclelist::getInstance()->vehicles.size(); i++){
    if(strcmp(Vehiclelist::getInstance()->vehicles[i].getRegNum().toString(), regNum)==0){
      vehicles.erase(vehicles.begin()+i);
      std::cout << "Vehicle with the number " << regNum << " was deleted successfully.\n";
      return;
    }
  }
  throw std::out_of_range("Couldn't find vehicle to remove\n");
}

void Vehiclelist::clearVehicles(){
  vehicles.clear();
}

bool Vehiclelist::isEmpty(){
  return vehicles.empty();
}

Vehicle* Vehiclelist::getVehicle(const char* regNum){
  for(int i=0; i<vehicles.size(); i++){
    if(strcmp(vehicles[i].getRegNum().toString(),regNum)==0){
      return &vehicles[i];
    }
  }
  throw std::out_of_range("Couldn't find vehicle\n");
}

std::ofstream& operator << (std::ofstream& out, Vehiclelist& vl){
  for(int i=0; i<vl.vehicles.size(); i++){
     out << vl.vehicles[i] << "\n";
  }
  return out;
}

void Vehiclelist::print(){
  int countTo = Vehiclelist::getInstance()->vehicles.size();
  for(int i=0; i<countTo; i++){
    vehicles[i].print();
  }
}