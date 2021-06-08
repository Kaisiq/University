//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Контролно 2
//
// Име: Даниел Даниел Иванов
// ФН: 45792
// Специалност: Информатика
// Курс: 1
// Административна група: 4
// Ден, в който се явявате на контролното: 29.05.2021
// Начален час на контролното: <тук попълнете часа за вашата група>
// Кой компилатор използвате: GCC <посочете едно от Visual C++, GCC или Clang>
//

// (Можете да изтриете този коментар след като го прочетете)
// Редът по-долу е специфичен за Visual C++.
// Ако използвате друг компилатор, можете да го изтриете.
// Тъй като strlen, strcmp и т.н. са дефинирани като deprecated,
// имате две възможности:
//
// * да използвате безопасните версии на тези функции
//   (strlen_s, strcmp_s и т.н.). В този случай можете да
//   изтриете дадената по-долу #define директива.
//
// * да дефинирате _CRT_SECURE_NO_WARNINGS преди да
//   включите съответните header файлове от стандартната
//   библиотека.
//
#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


class Command{
private:
  std::string command;
public:
  explicit Command(const std::string& command);
  std::string getCommand();
  std::string getArgument(size_t);
  std::size_t size();
  std::string operator[](std::size_t);
};

Command::Command(const std::string& command) {
  this->command = command;
}

std::string Command::getCommand(){
  std::string result;
  int i;
  for(i=0; i<command.size(); i++){
    if(command[i] == ' '){
      break;
    }
  }
  if(i == command.size()){
    return command;
  }
  i=0;
  while(this->command[i] != ' ' && (i<command.size())){
    result[i] = command[i];
    i++;
  }

  return result;
}

//template <typename T>      <-------------------- no time to implement
std::string Command::getArgument(size_t arg) {
  if(arg > this->size()){
    throw std::invalid_argument("No such argument!\n");
  }
  std::string result;
  int i=0;
  int j=0;
  while(i != arg){
    while(this->command[j] != ' '){
      j++;
    }
    i++;
    j++;
  }
  int k=0;
  while(this->command[j] != ' '){
    result[k] = this->command[j];
    j++;
    k++;
  }
  return result;
}

std::size_t Command::size() {
  size_t count = 0;
  for(int i=0; i<this->command.size(); i++){
    if(this->command[i] == ' '){
      count++;
    }
  }
  return count;
}

std::string Command::operator[](std::size_t argNum) {
  return getArgument(argNum);
}

class Editor{
private:
  static Editor* instance;
  std::size_t size;
  std::fstream file;
  Editor(const std::string& path);
  Editor();
public:
  static Editor* getInstance();
  std::size_t getSize() const;
  void open(const std::string& path);
  void close();
  void edit(std::size_t offset, std::uint8_t value);
  void display(std::ostream& out, std::size_t offset, std::size_t limit);
};


Editor* Editor::getInstance(){
  if(!instance){
    instance = new Editor();
  }
  return instance;
}

Editor::Editor(){
  this->size = 0;
}

Editor::Editor(const std::string &path){
  file.open(path, std::ios::in | std::ios::out | std::ios::binary);
  if(!file.is_open()){
    throw std::runtime_error("Couldn't open file\n");
  }
  this->size = file.end;
}

class Processor : public Command{
public:
  Processor(const std::string &str);
  bool isValid();
  void execute();

};

Processor::Processor(const std::string &str) : Command(str) {}


bool Processor::isValid(){
  if(!strcmp(this->getCommand().c_str(), "EXIT") || !strcmp(this->getCommand().c_str(), "SIZE") || !strcmp(this->getCommand().c_str(), "EDIT")
     || !strcmp(this->getCommand().c_str(), "SHOW") || !strcmp(this->getCommand().c_str(), "OPEN")) {
    return true;
  }
  return false;
}


void Processor::execute(){
  if(!strcmp(this->getCommand().c_str(), "EXIT")){
    exit(0);
  }
  else if(!strcmp(this->getCommand().c_str(), "SIZE")){
    std::cout << Editor::getInstance()->getSize() << std::endl;
  }
  else if(!strcmp(this->getCommand().c_str(), "EDIT")){
    size_t offset;
    uint8_t byte;
    std::cin >> offset;
    std::cin >> byte;
    Editor::getInstance()->edit(offset,byte);
  }
  else if(!strcmp(this->getCommand().c_str(), "SHOW")) {
    size_t offset;
    size_t limit;
    std::cin >> offset >> limit;
    try {
      Editor::getInstance()->display(std::cout, offset, limit);
    }
    catch(std::runtime_error& e){
      std::cerr << e.what() << "Aborting.\n";
    }
    catch(std::invalid_argument& e){
      std::cerr << e.what() << "Aborting.\n";
    }
  }
  else{
    std::cerr << "Invalid Command\nPlease try again.\n";
  }
}
std::size_t Editor::getSize() const{
  return this->size;
}
void Editor::open(const std::string& path){
  this->file.open(path, std::ios::in | std::ios::out | std::ios::binary);
  if(!file.is_open()){
    throw std::runtime_error("Couldn't open file\n");
  }
  this->size = file.end;
}

void Editor::close(){
  this->file.close();
}
void Editor::edit(std::size_t offset, std::uint8_t value){
  if(offset > getSize()){
    throw std::invalid_argument("Out of file\n");
  }
  file.seekp(offset);
  if(!file.good()){
    throw std::runtime_error("Something with the file went wrong\n");
  }
  file << value;
}
void Editor::display(std::ostream& out, std::size_t offset, std::size_t limit){
  if(offset > getSize()){
    throw std::invalid_argument("Out of file\n");
  }
  int i=0;
  while(file.tellp() != file.beg+limit){
    if(!file.good()){
      throw std::runtime_error("Something with the file went wrong\n");
    }
    file.seekp(offset + i);
    out << std::setfill('0') << std::setw(16) << std::hex << file.tellp() << std::endl;
    i++;
  }
}


Editor* Editor::instance = nullptr;

int main(int args, char* argument[]){
  try {
    if (argument[1]) {
      Editor::getInstance()->open(argument[1]);
    }
  }
  catch(std::runtime_error& e){
    std::cerr << e.what() << "Aborting operation\n";
  }
  std::string command;
  while(true){
    std::cout << "Enter a Command:\n"
              << "EXIT ---> Exits the program\n"
              << "SIZE ---> Prints the size of the opened file (if you have opened one)\n"
              << "EDIT ---> Edits the file on the position (offset) with the byte that you enter(byte)\n"
              << "SHOW ---> Displays the file from the offset to the limit you give\n";
    std::getline(std::cin, command, '\n');
    Processor cmd(command);
    if(cmd.isValid()){
      if(strcmp(cmd.getCommand().c_str(), "EXIT") == 0){
        std::cout << "exiting";
        Editor::getInstance()->close();  // <<-- closing file before exit if user forgot
        return 0;
      }
      try {
        cmd.execute();
      }
      catch(std::runtime_error&e) {
        std::cerr << e.what() << "Aborting.\n";
      }
      catch(std::invalid_argument&e ){
        std::cerr << e.what() << "Aborting.\n";
      }
      catch(std::bad_alloc &e){
        std::cerr << "Not enough memory to create Editor instance\n";
      }
    }
    else{
      std::cerr << "Not Valid Command";
    }
  }
}