#pragma once
#include "../Peoplelist/Peoplelist.cpp"
#include "../Vehiclelist/Vehiclelist.cpp"
//#include <cstring>
#include <cmath>

int charToInt(char* str){
  size_t sz = strlen(str);
  int result = 0;
  for(int i=0; i<sz; i++){
    result += (str[i] - '0') * pow(10, sz-i-1);
  }
  return result;
}

char* tolower(const char* str){
  int len = strlen(str);
  try {
    char *result = new char[len + 1];
    strcpy(result, str);
    for (int i = 0; i < len; i++) {
      if (result[i] >= 'A' && result[i] <= 'Z') {
        result[i] = result[i] - 'A' + 'a';
      }
    }
    return result;
  }
  catch(std::bad_alloc& e){
    std::cerr << "Not enough memory to allocate string.\n";
    throw;
  }
}

void addVehicle(const char* registration, const char* desc){
  Vehicle v(registration, desc);
}

void addPerson(const std::string& name, const unsigned int ID){
  Person p(name, ID);
}

void release(const unsigned int PID, const Registration VID){
  Peoplelist::getInstance()->removeVehicleFromPerson(PID, VID.toString());
}

void acquire(const unsigned int PID, const Registration VID){
  if(Vehiclelist::getInstance()->getVehicle(VID.toString())->hasOwner()){
    release(Vehiclelist::getInstance()->getVehicle(VID.toString())->getOwner()->getID(), VID);
    Peoplelist::getInstance()->addVehicleToPerson(PID, VID.toString());
  }
  else{
    Peoplelist::getInstance()->addVehicleToPerson(PID, VID.toString());
  }
}

bool isValidID(const char* str){
  int len = strlen(str);
  for(int i=0; i<len; i++){
    if(str[i]< '0' || str[i]> '9'){
      return false;
    }
  }
  return true;
}

void removeP(const int ID){
  Peoplelist::getInstance()->removePerson(ID);
}

void removeV(const char* regNum){
  Vehiclelist::getInstance()->removeVehicle(regNum);
}

void removeVorP(const char* what){
  int len = strlen(what);
  if(isValidID(what)){
    int ID=0;
    for(int i=0; i<len;i++) {

      ID += (int)(what[i] - '0') * pow(10,len-i-1);
    }
    removeP(ID);
  }
  else{
    if(!isValidRegistration(what)){
      throw std::invalid_argument("Not a Registration/ID!\n");
    }
    removeV(what);
  }
}

void saveP(const char* path){
  std::ofstream out(path, std::ios::out | std::ios::app);
  if(out.is_open()){
    out << *Peoplelist::getInstance();
    std::cout << "Peoplelist was saved. \n";
  }
  else{
    throw std::runtime_error("Couldn't open file\n");
  }
  out.close();
}


void saveV(const char* path){
  std::ofstream out(path, std::ios::out | std::ios::app);
  if(out.is_open() && out.end != out.beg){
    std::cout << "The file is not empty.\nDo you want to overwrite? (Y/N)\n";
    char option;
    std::cin >> option;
    if(tolower(option) == 'y'){
      out.close();
      out.open(path, std::ios::out | std::ios::trunc);
    }
  }
  else{
    throw std::runtime_error("Couldn't open file\n");
  }
  if(out.is_open()){
    out << *Vehiclelist::getInstance();
    std::cout << "Vehiclelist was saved. \n";
  }
  else{
    throw std::runtime_error("Couldn't open file\n");
  }
  out.close();
}

void save(const char* path){
  saveV(path);
  saveP(path);
  std::cout << "The Peoplelist and Vehiclelist were saved to the file.\n";
}

void open(const char* path){
  std::ifstream in;
  in.open(path);
  if(in.is_open()) {
    while (true) {
      char command[10];
      in >> command;
      if(in.eof()){
        break;
      }
      if (strcmp(tolower(command), "vehicle") == 0) {
        char registration[9];
        char description[128];
        char dummy;
        in >> registration;
        in >> dummy;
        in.get(description,128,'\"');
        in >> dummy;
        if (!isValidRegistration(registration)) {
          throw std::invalid_argument("");
        }
        addVehicle(registration, description);
      } else if (strcmp(tolower(command), "person") == 0) {
        char name[32];
        int ID;
        char dummy;
        in >> dummy;
        in.get(name,32,'\"');
        in >> dummy;
        in >> ID;
        addPerson(name, ID);
      } else if (strcmp(tolower(command), "acquire") == 0) {
        int ID;
        char registration[9];
        in >> ID;
        in >> registration;
        if (!isValidRegistration(registration)) {
          throw std::invalid_argument(
              "The registration you entered is not valid!\n");
        }
        acquire(ID, registration);
      }
    }
    in.close();
    std::cout << "\n\n\n <----------------------The file was read------------------->\n\n\n";
  }
  else{
    throw std::runtime_error("Couldn't open file\n");
  }
}


void show(char* what){
  if(strcmp(tolower(what), "vehicles")==0){
    std::cout << "\nVehicles: \n";
    Vehiclelist::getInstance()->print();
  }
  else if(strcmp(tolower(what), "people")==0){
    std::cout << "\nPeople: \n";
    Peoplelist::getInstance()->print();
  }
  else if(isValidID(what)){
    int len = strlen(what);
    int ID=0;
    for(int i=0; i<len;i++) {

      ID += (int)(what[i] - '0') * pow(10,len-i-1);
    }
    Peoplelist::getInstance()->getPerson(ID)->print();
    int countTo = Peoplelist::getInstance()->getPerson(ID)->vehiclesCount();
    if(Peoplelist::getInstance()->getPerson(ID)->hasVehicles()){
      std::cout << "Vehicles:\n";
    }
    for(int i=0; i < countTo; i++){
      Peoplelist::getInstance()->getPerson(ID)->getVehicleViaID(i)->print();
    }
  }
  else if(isValidRegistration(what)){
    Vehiclelist::getInstance()->getVehicle(what)->print();
    if(Vehiclelist::getInstance()->getVehicle(what)->hasOwner()){
      std::cout << "Owner: "
                << Vehiclelist::getInstance()->getVehicle(what)->getOwner()->getName();
      std::cout << " ID: " << Vehiclelist::getInstance()->getVehicle(what)->getOwner()->getID();
    }
  }
  else{
    throw std::invalid_argument("Bad input\n");
  }

}
