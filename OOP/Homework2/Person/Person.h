#pragma once
#include "../Vehicle/Vehicle.cpp"
#include <vector>

class Vehicle;

class Person{
  std::string name;
  uint ID;
  std::vector<Vehicle> vehicles;

public:
  Person() = delete;
  Person(const std::string name, const unsigned int ID);
  std::string getName() const;
  const char* getReg(int i);
  unsigned int getID() const;
  void addVehicle(Vehicle& v);
  void addVehicle(const char* regnum);
  void removeVehicle(Vehicle& v);
  void removeVehicle(const char* regnum);
  Vehicle* getVehicleViaReg(const char* regnum);
  Vehicle* getVehicleViaID(const int id);
  int findVehicle(const Vehicle& v);
  void print() const;
  bool hasVehicles();
  unsigned int vehiclesCount();
  int findVehicleByRegnum(const char* regnum);
  friend std::ofstream& operator << (std::ofstream& out, Person&);
  friend std::ifstream& operator >> (std::ifstream& in, Person&);
  };