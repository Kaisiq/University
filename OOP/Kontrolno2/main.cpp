//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Контролно по ООП-практикум
//
// Име: Даниел Даниел Иванов
// ФН: 45792
// Специалност: Информатика
// Курс: 1
// Административна група: 4
// Ден, в който се явявате на контролното: 15.05.2021
// Начален час на контролното: 9:00 <тук попълнете часа за вашата група>
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
//#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

class Message{
  uint8_t type;
  enum Type{
    INFO = 1,
    WARNING = 2,
    ERROR = 3,
    CRITICAL = 4,
  };
  std::string description;

public:
  Message(const uint8_t type, std::string description){
    this->type = type;
    this->description = description;
  }
  char* getType(){
    if(this->type == this->INFO){
      return "INFO: ";
    }
    else if(this->type == this->WARNING){
      return "WARNING: ";
    }
    else if(this->type == this->ERROR){
      return "ERROR: ";
    }
    else if(this->type == this->CRITICAL){
      return "CRITICAL: ";
    }
    return "CRITICAL: ";
  }
  uint8_t getTypeInt(){
    return this->type;
  }
  friend std::ofstream& operator <<(std::ofstream& out, Message& msg){
    out << msg.getType() << " " <<  msg.description;
    return out;
  }
  Message(const Message&) = delete;
  Message& operator= (const Message&) = delete;
};


class Logger{
private:
  Message* msg;
  static uint32_t infoCount;
  static uint32_t warningCount;
  static uint32_t errorCount;
  static uint32_t criticalCount;

public:
  Logger(const uint8_t type, std::string description){
    try {
      this->msg = new Message(type, description);
    }
    catch(std::bad_alloc& e){
      std::cerr << "Could not allocate memory for Message.";
      throw;
    }
  }
  Logger(){}
  void setMessage(const uint8_t type, std::string description){
    delete[] this->msg;
    try{
      this->msg = new Message(type,  description);
    }
    catch(std::bad_alloc& e){
      std::cerr << "Could not allocate memory for Message.";
      throw;
    }
  }

  const uint32_t getInfoCnt() const{
    return this->infoCount;
  }
  const uint32_t getWarningCount() const{
    return this->warningCount;
  }
  const uint32_t getErrorCnt() const{
    return this->errorCount;
  }
  const uint32_t getCriticalCnt() const{
    return this->criticalCount;
  }
  const uint32_t getLinesCnt() const{
    return this->infoCount + this->warningCount + this->errorCount + this->criticalCount;
  }
  Message& getMessage(){
    return *this->msg;
  }
  friend std::ofstream &operator<<(std::ofstream &log, Logger &logger) {
    switch (logger.msg->getTypeInt()) {
    case 1:
      logger.infoCount++;
      break;
    case 2:
      logger.warningCount++;
      break;
    case 3:
      logger.errorCount++;
      break;
    case 4:
      logger.criticalCount++;
      break;
    }
    log << logger.msg << "\n";
    return log;
  }

};



class Configuration{
private:
  static Configuration* instance;
  char* file;
  Logger* log;
  Configuration(char* path){
    if(!instance) {
      try {
        this->log = new Logger();
      } catch (std::bad_alloc &e) {
        std::cerr << "Not enough memory to create Configuration.";
        throw;
      }
      this->file = path;
    }
  }
public:
  static Configuration* getInstance(){
    return createInstance("/home/dahudohu/CLionProjects/University/OOP/Kontrolno2/config");
  }
  static Configuration* createInstance(char* path){
    if(!instance){
      try {
        instance = new Configuration(path);
      }
      catch(std::bad_alloc& e){
        std::cerr << "not enough memory to create Configuration instance.";
        throw;
      }
    }
    return instance;
  }
  friend std::ofstream& operator << (std::ofstream& out, Configuration& config){
    out << *config.log;
    return out;
  }
  char* getPath(){
    return this->file;
  }
  void writeLog(){
    std::ofstream file(getPath(), std::ios::app);
    if(!file.is_open()) {
      file << log;
      if(!file.good()){
        throw std::exception();
      }
    }
    else{
      throw std::exception();
    }
    file.close();
  }
  void writeLog(uint8_t msgType, std::string desc){
    log->setMessage(msgType,desc);
    std::ofstream file(getPath(), std::ios::app);
    if(!file.is_open()){
      file << Configuration::getInstance();
      if(!file.good()){
        throw std::exception();
      }
    }
    else{
      throw std::exception();
    }
    file.close();
  }
};

Configuration* Configuration::instance = nullptr;

int main(int argsNum, char* args[]) {
  if(args[1]){
    Configuration::createInstance(args[1]);
  }
  else{
    Configuration::getInstance();
  }
  int option = 0;
  while(option != 9){
    std::cout << "Enter 1 to add a new message \n"
              << "Enter 9 to exit the program \n";
    std::cin >> option;
    switch(option) {
    case 1:{
      uint8_t type;
      char descr[64];
      std::cout << "Enter type of message \n"
                << "1 for Info message \n"
                << "2 for Warning message \n"
                << "3 for Error message \n"
                << "4 for Critical error message \n";
      std::cin >> type;
      std::cout << "Enter description: \n";
      std::cin >> descr;
      try {
        Configuration::getInstance()->writeLog(type, descr);
      }
      catch(std::bad_alloc& e){
        std::cerr << "not enough memory, aborting process";
      }
      catch(std::exception& e){
        std::cerr << "File didn't open, aborting process";
      }
      break;
    }
    case 9: return 0;
    default: break;
    }
  }


  return 0;
}
