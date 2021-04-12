#pragma once
#include "../MyString/MyString.cpp"

class Vehicle{
private:
  MyString licensePlate;
  MyString descriptionOfVehicle;
  std::size_t parkingPlacesNeeded;

public:
  Vehicle(const char* registration, const char* description, std::size_t space);
  Vehicle() = delete;
  const char* registration() const;
  const char* description() const;
  std::size_t space() const;
  void printVehicle();
};