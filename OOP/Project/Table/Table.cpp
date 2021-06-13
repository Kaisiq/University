#pragma once

class Cell;

void Table::printTable(){
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
        if(widthToChar(j) == table[k]->getName()[0]  &&  i == strToInt(getNumFromName(table[k]->getName()))){
          std::cout << "|" << std::setw(paddings[j]) << table[k];
          printValue = true;
        }
      }
      if(!printValue)
        std::cout << "|" << std::setw(paddings[j]) << " ";
    }
    std::cout << "| \n";
  }
}




void Table::editMember(const char* where,const char* value){
  if(strcmp(withoutSpaces(value), "")==0)
    return;
  if(!isValidCell(where)){
    std::string error = "Invalid Cell ID: ";
    error += where;
    error += '\n';
    throw std::invalid_argument(error);
  }
  if(!isValidInput(value)){
    std::string error = "Invalid Cell Argument at Cell ";
    error += where;
    error += '\n';
    throw std::invalid_argument(error);
  }
  try{
    getCell<Cell>(where);
    if(isValidInt(value)) {
      if (typeid(int) == typeid(getCell<Cell>(where)->getValue())) {
        getCell<Cell>(where)->setValue(withoutSpaces(value));
      }
      else {
        table.at(getCellID(where)) = new IntCell(where, strToInt(value));
      }
    }
    else if(isValidDouble(value)){
      if(typeid(double) == typeid(getCell<Cell>(where)->getValue())){
        getCell<Cell>(where)->setValue(withoutSpaces(value));
      }
      else {
        table.at(getCellID(where)) = new DoubleCell(where, atof(value));
      }
    }
    else if(isValidString(value)){
      if(typeid(char*) == typeid(getCell<Cell>(where)->getValue())){
        getCell<Cell>(where)->setValue(withoutSpaces(value));
      }
      else {
        table.at(getCellID(where)) = new StringCell(where, value);
      }
    }
    else if(isValidOperation(value)){
      if(isValidOperation(getCell<Cell>(where)->getValue())){
        getCell<Cell>(where)->setValue(withoutSpaces(value));
      }
      else {
        table.at(getCellID(where)) = new FormulaCell(where, value);
      }
    }
    else {
      std::string error = "Invalid Cell Argument at Cell ";
      error += where;
      error += "(";
      error += value;
      error += ")\n";
      throw std::invalid_argument(error);
    }
    std::cout << "Cell was edited.\n";
  }
  catch(std::invalid_argument& e){
    if(strcmp(e.what(),"Couldn't find Cell!\n") == 0){
      if(isValidInt(withoutSpaces(value))) {
        Cell* a = new IntCell(where, strToInt(withoutSpaces(value)));
        Table::getInstance()->addCell(*a);
      }
      else if(isValidDouble(withoutSpaces(value))){
        Cell* a = new DoubleCell(where, std::atof(withoutSpaces(value)));
        Table::getInstance()->addCell(*a);
      }
      else if(isValidString(value)){
        Cell* a = new StringCell(where, value);
        Table::getInstance()->addCell(*a);
      }
      else if(isValidOperation(withoutSpaces(value))){
        Cell* a = new FormulaCell(where, withoutSpaces(value));
        Table::getInstance()->addCell(*a);
      }
      else throw std::runtime_error("Strange error occurred.\n");
      std::cout << "Cell was created and edited.\n";
    }
    else throw;
  }
}

template <typename CellType>
CellType* Table::getCell(const char* where){
  for(int i=0; i < table.size(); i++){
    if(strcmp(table[i]->getName(),where) == 0){
      return dynamic_cast<CellType*>(table[i]);
    }
  }
  throw std::invalid_argument("Couldn't find Cell!\n");
}

size_t Table::getCellID(const char* where){
  for(int i=0; i < table.size(); i++){
    if(strcmp(table[i]->getName(),where) == 0){
      return i;
    }
  }
  throw std::invalid_argument("Couldn't find Cell!\n");
}

void Table::addCell(Cell& cell){
  table.push_back(&cell);
}

std::vector<Cell*>& Table::getTable(){
  return table;
}


int Table::getMaxWhitespace(char a){
  int maxlen = 3;
  for(int i=0; i<table.size(); i++){
    if(a == table[i]->getName()[0]) {
        if (strlen(stringWithoutQuotes(table[i]->getValue())) > maxlen) {
          maxlen = strlen(stringWithoutQuotes(table[i]->getValue()));
        }
    }
  }
  return maxlen;
}