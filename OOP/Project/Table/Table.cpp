#pragma once
#include "Table.h"
#include "../Commands/Commands.h"
#include <iomanip>

class Cell;

void Table::printTable(){
  try {
    int width = getMaxChar(table) - 'A' + 1;
    int height = getMaxNum(table);

    int* paddings = new int[26];
    for(int i=0; i<26; i++){
      paddings[i] = getMaxWhitespace(widthToChar(i));
    }

    for (int i = 0; i < width; i++) {
      std::cout << "|" << std::fixed << std::setw(paddings[i]) << (char)('A' + i);  //<----------------- printing the first row with letters A - Z
    }
    std::cout << "|\n";

    for(int i=1; i<=height; i++){
      for(int j=0; j<width; j++){
        bool printValue = false;
        for(int k=0; k<table.size(); k++){
          if(widthToChar(j) == table[k].getName()[0]  &&  i == strToInt(getNumFromName(table[k].getName()))){
            if(isValidOperation(table[k].getValue())){
              if(hasAtleastOneDoubleOrHasDivision(table[k].getValue()))
                std::cout << "|" << std::setw(paddings[j]) << calculateOperation<double>(table[k].getValue());
              else
                std::cout << "|" << std::setw(paddings[j]) << calculateOperation<int>(table[k].getValue());
            }
            else {
              std::cout << "|" << std::setw(paddings[j]) << stringWithoutQuotes(table[k].getValue());
            }
            printValue = true;
          }
        }
        if(!printValue)
        std::cout << "|" << std::setw(paddings[j]) << " ";
      }
      std::cout << "| \n";
    }
  }

  catch(std::out_of_range& e){
    std::cerr << e.what() << "Cancelling the operation.\n";
  }
}




void Table::editMember(const char* where,const char* value){
  if(strcmp(withoutSpaces(value), "")==0)
    return;
  if(!isValidCell(where)){
    throw std::invalid_argument("Invalid Cell Number\n");
  }
  if(!isValidInput(value)){
    throw std::invalid_argument("Invalid Cell Argument\n");
  }
  try{
    if(!isValidString(value))
      getCell(where)->changeValue(withoutSpaces(value));
    else
      getCell(where)->changeValue(value);
    std::cout << "Cell was edited.\n";
  }
  catch(std::invalid_argument& e){
    if(strcmp(e.what(),"Couldn't find Cell!") == 0){
      if(!isValidString(value)) {
        Cell a(where, withoutSpaces(value));
        Table::getInstance()->addCell(a);
      }
      else{
        Cell a(where, value);
        Table::getInstance()->addCell(a);
      }
      std::cout << "Cell was created and edited.\n";
    }
    else throw;
  }
}


Cell* Table::getCell(const char* where){
  for(int i=0; i < table.size(); i++){
    if(strcmp(table[i].getName(),where) == 0){
      return &table[i];
    }
  }
  throw std::invalid_argument("Couldn't find Cell!");
}


void Table::addCell(Cell& cell){
  table.push_back(cell);
}

std::vector<Cell>& Table::getTable(){
  return table;
}


int Table::getMaxWhitespace(char a){
  int maxlen = 3;
  for(int i=0; i<table.size(); i++){
    if(a == table[i].getName()[0]) {
      if (isValidOperation(table[i].getValue())) {
        std::string result;
        if (hasAtleastOneDoubleOrHasDivision(table[i].getValue())) {
          if (strlen(calculateOperation<double>(table[i].getValue()).c_str()) > maxlen) {
            maxlen = strlen(calculateOperation<double>(table[i].getValue()).c_str());
          }
        }
        else{
          if (strlen(calculateOperation<int>(table[i].getValue()).c_str()) > maxlen) {
            maxlen = strlen(calculateOperation<int>(table[i].getValue()).c_str());
          }
        }
      }
      else {
        if (strlen(stringWithoutQuotes(table[i].getValue())) > maxlen) {
          maxlen = strlen(stringWithoutQuotes(table[i].getValue()));
        }
      }
    }
  }

  return maxlen;
}