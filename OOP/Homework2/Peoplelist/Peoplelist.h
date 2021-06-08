#pragma once
#include "../Person/Person.h"

class Peoplelist{
private:
  static Peoplelist* instance;
  std::vector<Person> people;
  Peoplelist(){}
public:
  static Peoplelist* getInstance(){
    if(!instance){
      instance = new Peoplelist;
    }
    return instance;
  }

  void addPerson(Person p);
  bool duplicateID(Person p);
  void removePerson(const unsigned int ID);
  void clearPeople();
  void print();
  bool isEmpty();
  Person* getPerson(const unsigned int ID);
  void addVehicleToPerson(const unsigned int ID, Vehicle& v);
  void addVehicleToPerson(const unsigned int ID, const char* regNum);
  void removeVehicleFromPerson(const unsigned int ID, const char* regNum);
  friend std::ofstream& operator << (std::ofstream& out, Peoplelist&);
  friend std::ifstream& operator >> (std::ifstream& in, Peoplelist&);
};