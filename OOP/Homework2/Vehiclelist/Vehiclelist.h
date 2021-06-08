#pragma once
#include <iostream>
#include <vector>
#include "../Vehicle/Vehicle.h"

class Vehiclelist{
private:
  static Vehiclelist* instance;
  std::vector<Vehicle> vehicles;
  Vehiclelist(){}
public:
  static Vehiclelist* getInstance(){
    if(!instance){
      instance = new Vehiclelist;
    }
    return instance;
  }
  void addVehicle(Vehicle& v);
  bool duplicateReg(Vehicle& v);
  void removeVehicle(const char* regNum);
  void clearVehicles();
  bool isEmpty();
  Vehicle* getVehicle(const char* regNum);
  void print();
  friend std::ofstream& operator << (std::ofstream& out, Vehiclelist&);
};