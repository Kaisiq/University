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

Garage& Garage::operator=(const Garage& rhs){
  if(this == &rhs){
    return *this;
  }
  if(this!=&rhs){
    delete[] this->vehicles;
  }
  this->capacity = rhs.size();
  this->used = rhs.used;
  this->vehicleCount = rhs.vehicleCount;
  Vehicle** resultVehicles = new(std::nothrow) Vehicle*[this->capacity];
  for(int i=0; i<vehicleCount; i++){
    resultVehicles[i] = rhs.vehicles[i];
  }
  this->vehicles = resultVehicles;
  return *this;
}

void Garage::insert(Vehicle& v){
  try {
    if (v.space() + this->used > this->capacity) {
      throw std::out_of_range("");
    }
    for (int i = 0; i < this->vehicleCount; i++) {
      if (this->find(v.registration()) != nullptr) {
        throw std::invalid_argument("invalid input");
      }
    }
    this->used += v.space();
    this->vehicles[vehicleCount] = new (std::nothrow)
        Vehicle(v.registration(), v.description(), v.space());
    this->vehicleCount++;
    std::cout << "Vehicle added. \n";
  }
  catch(std::invalid_argument& e){
    std::cerr << "Invalid Argument! Reverting back to previous stage.";
    std::cout << "Vehicle was not added.";
  }
  catch(std::out_of_range& e){
    std::cerr << "Out of range! The Space of the vehicle added to the used space exceeds the capacity! Reverting.";
    std::cout << "Vehicle was not added.";
  }
}


void Garage::erase(const char* registration){
  for(int i=0; i < this->size(); i++){
    if(strcmp(this->vehicles[i]->registration(),registration) == 0){
      size_t toRemove = this->vehicles[i]->space();
      this->vehicles[i] = this->vehicles[vehicleCount-1];
//      delete[] this->vehicles[vehicleCount-1];
      this->vehicles[vehicleCount-1] = nullptr;
      this->used -= toRemove;
      this->vehicleCount-=1;
      std::cout << "Vehicle was removed.\n";
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

