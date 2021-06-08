#pragma once
#include <vector>
#include "../Registration/Registration.cpp"

class Person;

class Vehicle{
private:
  Registration reg;
  std::string description;
  Person* owner;
public:
  Vehicle(const char* regNum, const char* desc);
  Vehicle()=delete;
  const Registration getRegNum() const;
  const std::string getDesc() const;
  void addOwner(Person* p);
  void removeOwner();
  void print();
  bool hasOwner();
  Person* getOwner();
  friend std::ofstream& operator << (std::ofstream& out, Vehicle&);
};
