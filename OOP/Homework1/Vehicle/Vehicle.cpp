#pragma once
#include "Vehicle.h"
#include <cassert>

Vehicle::Vehicle(const char* registration, const char* description, std::size_t space)
{
  assert(registration);
  assert(description);
  assert(space>0);
  this->licensePlate.setString(registration);
  this->descriptionOfVehicle.setString(description);
  this->parkingPlacesNeeded = space;
}
const char* Vehicle::registration() const{
  return this->licensePlate.getString();
}
const char* Vehicle::description() const{
  return this->descriptionOfVehicle.getString();
}
std::size_t Vehicle::space() const{
  return this->parkingPlacesNeeded;
}

void Vehicle::printVehicle(){
  std::cout << "\nRegistration:" << this->registration() << "\n"
            << "Description: " << this->description() << "\n"
            << "Parking space needed: " << this->space() << "\n";
}