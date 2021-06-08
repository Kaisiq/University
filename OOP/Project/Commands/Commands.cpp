#pragma once
#include "HelperFunctions.cpp"
#include <fstream>

void open(const std::string path){
  std::ifstream in;
  in.open(path, std::ios::in | std::ios::out);
  int col;
  int row = 1;
  std::string commas;
  std::getline(in, commas, '\n');
  unsigned int commasCount = 0;
  size_t sz = commas.size();
  for(int i=0; i<sz; i++){
    if(commas[i] == ','){
      commasCount++;
    }
  }
  in.seekg(std::ios::beg);
  while(in.is_open() && (!in.eof())){
    col = 0;
    while(in.is_open() && col <= commasCount) {
      std::string input;
      if(col == commasCount)
        std::getline(in, input, '\n');
      else
        std::getline(in, input, ',');
      if(input[0] == '\n') {
        row++;
        for(int i=0; i<input.size(); i++){
          input[i] = input[i+1];
        }
      }
      if(input.size() >= 1 && input[0] != '\0'){
        char* inputStr = new char[input.size()+1];
        for(int i=0; i<input.size(); i++){
          inputStr[i] = input[i];
        }
        inputStr[input.size()] = '\0';
        char width = col + 'A';
        char* height = intToCharArr(row);
//        std::cout << width << " ";        <--------- debugging tool
        char* result = new char[strlen(height)+2];
        result[0] = width;
        strcat(result,height);
        result[strlen(height)+1] = '\0';
        Table::getInstance()->editMember(result, inputStr);
      }
      col++;
    }
    row++;
  }
  in.close();
}

void save(std::string path){
  std::ofstream out;
  out.open(path, std::ios::in | std::ios::out);
  out.seekp(0, std::ios::end);
  if(out.is_open() && (out.tellp() != 0)){
    std::cout << "The file is not empty.\nDo you want to overwrite? (Y/N)\n";
    char option;
    std::cin >> option;
    if(tolower(option) == 'y'){
      out.close();
      out.open(path, std::ios::out | std::ios::trunc);
      if(!out.is_open()){
        throw std::runtime_error("Couldn't open file!\n");
      }
    }
  }
  if(!out.is_open()){
    throw std::runtime_error("Couldn't open file!\n");
  }
  sortTable(Table::getInstance()->getTable());

  int sz = Table::getInstance()->getTable().size();
  int width = getMaxChar(Table::getInstance()->getTable()) - 'A' + 1;
  int height = getMaxNum(Table::getInstance()->getTable());
  int count = 0;

  for(int i=1; i<=height; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < sz; k++) {
        if(widthToChar(j) == Table::getInstance()->getTable()[k].getName()[0]  &&  i == strToInt(getNumFromName(Table::getInstance()->getTable()[k].getName()))){
          for(int l=0; l<count; l++){
            out << ",";
          }
          out << Table::getInstance()->getTable()[k].getValue();
        }
      }
      count++;
    }
    count = 0;
    if(i<height-1)
    out << "\n";
  }

  


  out.close();
}

void saveas(std::string path){

}




