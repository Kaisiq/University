#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "Cell/Cell.h"
#include "Table/Table.h"
#include "Commands/Commands.h"
#include "Commands/HelperFunctions.h"

Table* Table::instance = nullptr;

int main(){
  std::cout << "<===========  Welcome to the table manager program! ==========>\n\n";
  std::string currentFile;
  while(true) {
    std::cout << "Commands: \n"
              << "Open (\"path\") ---------> opens a file\n"
              << "Save --------------------> saves the current file\n"
              << "Saveas (\"path\") -------> save the table on the given path\n"
              << "Close -------------------> closes the current open file\n"
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
        currentFile = path;
        std::cout << "File was opened\n";
      }
      else if (strcmp(tolower(command), "new") == 0) {
        currentFile.clear();
        Table::getInstance()->getTable().clear();
        std::cout << "New File was created.\n";
      }
      else if (strcmp(tolower(command), "save") == 0) {
        save(currentFile);
        std::cout << "File was saved\n";
      }
      else if (strcmp(tolower(command), "saveas") == 0) {
        std::string path;
        char dummy;
        std::cin >> dummy;
        std::getline(std::cin, path, '\"');
        save(path);
        std::cout << "File was saved\n";
      }
      else if (strcmp(tolower(command), "close") == 0) {
        currentFile.clear();
        std::cout << "File was closed.\n";
      }
      else if (strcmp(tolower(command), "print") == 0){
        Table::getInstance()->printTable();
        std::cout << "Table was printed.\n";
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
        std::cout << "Exiting the program..\n";
        return 0;
      }
      else {
        std::string error = "Invalid command -> ";
        error += command;
        error += '\n';
        throw std::invalid_argument(error);
      }
    }
    catch(std::invalid_argument& e){
      std::cerr << e.what() << "Ending operation.\n";
    }
    catch(std::runtime_error& e){
      std::cerr << e.what() << "Ending operation.\n";
    }
    catch(std::bad_alloc &e){
      std::cerr << e.what() << "Ending operation.\n";
    }
    catch(std::out_of_range& e){
      std::cerr << e.what() << "Cancelling the operation.\n";
    }
  }
}