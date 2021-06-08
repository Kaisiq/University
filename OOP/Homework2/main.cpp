#include "Registration/Registration.cpp"
#include "Vehicle/Vehicle.cpp"
#include "Person/Person.cpp"
#include "Commands/Commands.cpp"
#include "Vehiclelist/Vehiclelist.cpp"
#include "Peoplelist/Peoplelist.cpp"
#include <fstream>
#include <cstring>

Vehiclelist* Vehiclelist::instance = nullptr;
Peoplelist* Peoplelist::instance = nullptr;

int main(int argCnt, char** path) {

  if (path[1]) {
    try {
      open(path[1]);
    }
    catch (std::invalid_argument& e) {
      std::cerr << "The operation was ended. \n";
    }
  }

  char command[10];
  std::cout << "<----------------Welcome to the database of Vehicles and People!----------------> \n";
  while (strcmp(tolower(command), "exit") != 0) {
    std::cout
        << "                                Commands: \n"
        << "Vehicle (registration, \"description\") -----------> adds a Vehicle with registration and description \n"
        << "Person (\"name\", id) -----------------------------------------------> adds a Person with name and ID \n"
        << "Acquire (id, regnum) --------------------------------------------------> assign a vehicle to a person \n"
        << "Release (id, regnum) -----------------------------------------------> release a vehicle from a person \n"
        << "Remove (what) -> remove a vehicle or a person (usage: remove person-id | remove vehicle-registration) \n"
        << "Save (\"path\") ------------------------------------> save the database in a directory given from you \n"
        << "Show (People|Vehicles|person-id|vehicle-registration) ---> shows the information of whatever you want \n"
        << "Exit -----------------------------------------------------------------------------> Closes the program\n";
    std::cin >> command;
    try {
      if (strcmp(tolower(command), "vehicle") == 0) {
        char registration[9];
        char description[128];
        char dummy;
        std::cin >> registration;
        std::cin >> dummy;
        std::cin.get(description,128,'\"');
        std::cin >> dummy;
        if (!isValidRegistration(registration)) {
          throw std::invalid_argument("Not Valid Registration!\n");
        }
        addVehicle(registration, description);
      } else if (strcmp(tolower(command), "person") == 0) {
        std::string name;
        char ID[16];
        char dummy;
        std::cin >> dummy;
        std::getline(std::cin, name, '\"');
        std::cin >> dummy;
        std::cin >> ID;
        if(!isValidID(ID)){
          throw std::invalid_argument("Not valid ID!\n");
        }
        addPerson(name, charToInt(ID));
      } else if (strcmp(tolower(command), "acquire") == 0) {
        int ID;
        char registration[9];
        std::cin >> ID;
        std::cin >> registration;
        if (!isValidRegistration(registration)) {
          throw std::invalid_argument("The registration you entered is not valid!\n");
        }
        acquire(ID, registration);
      } else if (strcmp(tolower(command), "release") == 0) {
        int ID;
        char registration[9];
        std::cin >> ID;
        std::cin >> registration;
        if (!isValidRegistration(registration)) {
          throw std::invalid_argument("The registration you entered is not valid!");
        }
        release(ID, registration);
      } else if (strcmp(tolower(command), "remove") == 0) {
        char what[64];
        std::cin >> what;
        removeVorP(what);
      } else if (strcmp(tolower(command), "save") == 0) {
        try {
          char *savePath = new char[256];
          char dummy;
          std::cin >> dummy;
          std::cin.get(savePath,256,'\"');
          std::cin >> dummy;
          save(savePath);
        }
        catch(std::bad_alloc& e){
          std::cerr << "Not enough memory to save the file, canceling the operation.\n";
        }
      } else if (strcmp(tolower(command), "show") == 0) {
        char what[9];
        std::cin >> what;
        show(what);
      } else if (strcmp(tolower(command), "exit") == 0) {
        return 0;
      } else
        continue;
    }
    catch (std::invalid_argument& e) {
      std::cerr << e.what();
      std::cerr << "The operation was ended." << std::endl;
      continue;
    }
    catch (std::runtime_error& e) {
      std::cerr << e.what();
      std::cerr << "The operation was ended." << std::endl;
      continue;
    }
    catch (std::out_of_range& e) {
      std::cerr << e.what();
      std::cerr << "The operation was ended." << std::endl;
      continue;
    }
    catch (std::bad_alloc& e) {
      std::cerr << e.what();
      std::cerr << "The operation was ended." << std::endl;
      continue;
    }
    catch(std::logic_error& e){
      std::cerr << e.what();
      std::cerr << "\nThe operation was ended." << std::endl;
    }
    catch(...){
      std::cerr << "Unknown error.\nThe operation was ended." << std::endl;
      continue;
    }
  }
  return 0;
}