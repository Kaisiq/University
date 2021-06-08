#include <iostream>
#include <vector>
#include <cstring>
#include "Cell/Cell.cpp"
#include "Commands/HelperFunctions.h"

Table* Table::instance = nullptr;

int main(){
  std::cout << "<===========  Welcome to the table manager program! ==========>\n\n";
  while(true) {
    std::cout << "Commands: \n"
              << "Open (\"path\") ---------> opens a file\n"
              << "Save (\"path\") ---------> saves a file\n"
              << "Saveas (\"path\") -------> save a file with a format\n"
              << "Print -----------------> prints the table\n"
              << "Edit(\"what\", \"value\")--> edits the given cell with the given value\n"
              << "Exit ------------------> exits the program.\n";
    try {
      char command[16];
      std::cin >> command;
      if (strcmp(tolower(command), "open") == 0) {
        std::string path;
        char dummy;
        std::cin >> dummy;
        std::getline(std::cin, path, '\"');
        open(path);
        std::cout << "File was opened\n";
      }
      else if (strcmp(tolower(command), "save") == 0) {
        std::string path;
        char dummy;
        std::cin >> dummy;
        std::getline(std::cin, path, '\"');
        save(path);
      }
      else if (strcmp(tolower(command), "saveas") == 0) {
        std::string path;
        char dummy;
        std::cin >> dummy;
        std::getline(std::cin, path, '\"');
        std::cin >> dummy;
        saveas(path);
      }
      else if (strcmp(tolower(command), "print") == 0){
        Table::getInstance()->printTable();
      }
      else if (strcmp(tolower(command), "edit") == 0) {
        char* where = new char[256];
        char* value = new char[256];
        std::cin >> where;
        std::cin.get(value, 256, '\n');  // <------------- if you enter 1234 you get " 1234"
        int i=0;
        while(value[i]){
          value[i] = value[i+1];            //<-------------- quick fix
          i++;
        }
        Table::getInstance()->editMember(where, value);
      }
      else if (strcmp(tolower(command), "exit") == 0) {
        std::cout << "\nExiting the program..\n";
        return 0;
      }
      else {
        throw std::invalid_argument("Invalid command\n");
      }
    }
    catch(std::invalid_argument& e){
      std::cerr << e.what()
                << "Ending operation.\n";
    }
  }
}