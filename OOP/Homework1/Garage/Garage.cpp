#pragma once
#include <iostream>
#include <cassert>
#include <cstring>
#include "../Vehicle/Vehicle.cpp"
#include "Garage.h"

Garage::Garage(std::size_t size)
{
  vehicles = new (std::nothrow) Vehicle*[size];
  this->capacity = size;
  this->used = 0;
  this->vehicleCount = 0;

}
Garage::~Garage(){
  delete[] vehicles;
}
Garage::Garage(const Garage& rhs){
  this->capacity = rhs.size();
  this->used = rhs.used;
  this->vehicleCount = rhs.vehicleCount;
  Vehicle** resultVehicles = new(std::nothrow) Vehicle*[this->capacity];
  for(int i=0; i<vehicleCount; i++){
    resultVehicles[i] = rhs.vehicles[i];
  }
  this->vehicles = resultVehicles;
}
void Garage::insert(Vehicle& v){
  if(v.space() + this->used > this->capacity){
    throw std::out_of_range("");
  }
  for(int i=0; i<this->vehicleCount; i++){
    if(strcmp(v.registration(), this->vehicles[i]->registration())==0){
      throw std::invalid_argument("");
      break;
    }
  }
  this->used += v.space();
  this->vehicles[vehicleCount] = &v;
  this->vehicleCount++;
  std::cout << "Vehicle added. \n";
}

//idk if this works
void Garage::removeVehicleFromArr(int i){
  size_t toRemove = this->vehicles[i]->space();
  this->vehicles[i] = this->vehicles[used];
  delete[] this->vehicles[vehicleCount];
  this->vehicles[vehicleCount] = nullptr;
  this->used -= toRemove;
  this->vehicleCount--;
  std::cout << "Vehicle was removed.\n";
}

void Garage::erase(const char* registration){
  for(int i=1; i<this->vehicleCount; i++){
    if(strcmp(this->at(i).registration(),registration) == 0){
      removeVehicleFromArr(i);
    }
  }
}
const Vehicle& Garage::at(std::size_t pos) const{
  if(pos-1 >= vehicleCount){
    throw std::out_of_range("at");
  }
  return *this->vehicles[pos-1];
}

const Vehicle& Garage::operator[](std::size_t pos) const{
  assert(pos < vehicleCount);
  return *this->vehicles[pos];
}
bool Garage::empty() const{
  return this->vehicleCount == 0;
}
std::size_t Garage::size() const{
  return this->vehicleCount;
}
void Garage::clear(){
  delete[] this->vehicles;
  this->vehicles = new(std::nothrow) Vehicle*[this->capacity];
  this->used = 0;
  this->vehicleCount = 0;
}
const Vehicle* Garage::find(const char* registration) const{
  for(int i=0; i<vehicleCount; i++){
    if(strcmp(registration, this->vehicles[i]->registration())==0){
      return this->vehicles[i];
    }
  }
  return nullptr;
}

void Garage::printGarage(){
  for(int i=0; i<vehicleCount; i++){
    vehicles[i]->printVehicle();
  }
}

