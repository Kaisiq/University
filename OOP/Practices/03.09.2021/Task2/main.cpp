#include <iostream>
using namespace std;

struct Human {
  char firstName[16];
  char lastName[16];
  int internship;
  int sold;

};

void printHumanInfo(Human h) {
  cout << "First name: "<< h.firstName <<
      "\nLast name: "<< h.lastName <<
      "\nYears of experience: "<<
      h.internship << "\nSold automobiles: "<<
      h.sold << endl;
}

void createHuman (Human& human) {
  cin >> human.firstName;
  cin >> human.lastName;
  cin >> human.internship;
  cin >> human.sold;
}

struct Automobile{
  char brand[16];
  char model[16];
  int yearOfCreation;
  int price;
  int mileage;

};

void printInfo(Automobile& car) {
  cout << "Brand: ";
  for(int i = 0; i < 16; i++) {
    cout << car.brand[i];
  }
  cout << "\nModel: ";
  for(int i = 0; i < 16; i++) {
    cout << car.model[i];
  }

  cout << "\nYear of creation: " << car.yearOfCreation;
  cout << "\nPrice: " << car.price;
  cout << "\nMileage: " << car.mileage;

}

void createAuto (Automobile& automobile) {
  cin >> automobile.brand;
  cin >> automobile.model;
  cin >> automobile.yearOfCreation;
  cin >> automobile.price;
  cin >> automobile.mileage;
}

struct AutoHouse{
  int employeesLen = 1;
  int autosLen = 1;
  Human owner;
  Human *employees = new Human[employeesLen];
  Automobile *autos = new Automobile[autosLen];

  void employNewHuman(Human newEmployee){
    Human *result = new Human[employeesLen+1];
    for(int i=0; i<employeesLen; i++){
      result[i] = employees[i];
    }
    createHuman(newEmployee);
    result[employeesLen] = newEmployee;
    employees = result;
    delete[] result;
    employeesLen++;
  }

  void fireById(unsigned id){
    Human *result = new Human[employeesLen-1];
    for(int i=0; i<id; i++){
      result[i] = employees[i];
    }
    for(int i=id+1; i<employeesLen; i++){
      result[i-1] = employees[i];
    }
    employees = result;
    delete[] result;
    employeesLen--;
  }

  void changeOwner(Human newOwner) {
    owner = newOwner;
  }

  void addAuto(Automobile newCar){
    Automobile *result = new Automobile[autosLen+1];
    for(int i=0; i<autosLen; i++){
      result[i] = autos[i];
    }
    createAuto(newCar);
    result[autosLen] = newCar;
    autos = result;
    delete[] result;
    autosLen++;
  }

  void sellAuto(int sellerID, int index) {
    deleteAuto(index);
    employees[sellerID].sold += 1;
    autosLen--;
  }

  void sortEmployees() {
    for(int i = 0; i < employeesLen; i++) {
      for(int j = i; j < employeesLen; j++){
        if(employees[i].internship < employees[j].internship) {
          swap(employees[i], employees[j]);
        }
      }
    }
  }

  void sortAutos() {
    for(int i = 0; i < autosLen; i++) {
      for(int j = i; j < autosLen; j++){
        if(autos[i].price < autos[j].price) {
          swap(autos[i], autos[j]);
        }
      }
    }
  }

  void printEmployees() {
    for (int i = 0; i < employeesLen; ++i) {
      printHumanInfo(employees[i]);
    }
  }

  void printAutos() {
    for (int i = 0; i < autosLen; ++i) {
      printInfo(autos[i]);
    }
  }

  void deleteAuto(int index) {
    Automobile *result = new Automobile[employeesLen-1];
    for(int i=0; i < index; i++){
      result[i] = autos[i];
    }
    for(int i=index+1; i<autosLen; i++){
      result[i-1] = autos[i];
    }
    autos = result;
    delete[] result;
  }

  ~AutoHouse(){
    delete[] employees;
    delete[] autos;
  };
};







int main() {
  AutoHouse autohouse;
  Human owner;
  cout << "Enter Owner: \n";
  createHuman(owner);
  cout << "Enter employee1: \n";
  createHuman(autohouse.employees[0]);
  cout << "Enter auto1 \n";
  createAuto(autohouse.autos[0]);
  autohouse.owner = owner;



  cout << "\n\n" << autohouse.employees[0].sold << "\n\n\n\n";




  int option;
  cout << "\n ============ Welcome to Autohouse ============ \n";
  do {
    cout << "\n ============ Autohouse \"Armqnov & Semerjiev\" ============ \n";
    cout << "Press 1 to add a new employee \n";
    cout << "Press 2 to fire an existing employee \n";
    cout << "Press 3 to add a new car \n";
    cout << "Press 4 to sell an existing car \n";
    cout << "Press 5 to sort all cars and all employees \n";
    cout << "Press 6 to print all employees and their info \n";
    cout << "Press 7 to print all cars and their info \n";
    cout << "Enter 10 to leave \n";
    cout << "Enter a number to do an action: ";
    cin >> option;
    switch (option) {
    case 1:
      Human newHuman;
      autohouse.employNewHuman(newHuman);
      break;
    case 2:
      int id;
      cout << "Enter ID of employee who has to be fired: ";
      cin >> id;
      autohouse.fireById(id);
      break;
    case 3:
      Automobile car;
      autohouse.addAuto(car);
      break;
    case 4:
      int id1;
      int employeeId;
      cout << "Enter ID of auto which you want to sell: ";
      cin >> id1;
      cout << "Enter ID of employee who is selling it: ";
      cin >> employeeId;
      autohouse.sellAuto(employeeId, id1);
      break;
    case 5:
      autohouse.sortAutos();
      autohouse.sortEmployees();
      break;
    case 6:
      printHumanInfo(owner);
      cout << endl;
      autohouse.printEmployees();
      break;
    case 7:
      autohouse.printAutos();
      break;
    case 10:
      return 0;
    default:
      cout << "Wrong input, please try again.";
      break;
    }
  } while (option != 10);


  return 0;
}


