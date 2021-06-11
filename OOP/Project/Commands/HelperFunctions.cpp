#pragma once
#include <cmath>
#include "../Table/Table.h"
#include "../Cell/FormulaCell.cpp"

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


bool isValidCell(const char* cell){
  size_t sz = strlen(cell);
  if(sz == 0){
    return false;
  }
  if(cell[0] < 'A' || cell[0] > 'Z'){
    return false;
  }
  for(int i=1; i<sz; i++){
    if(cell[i] < '0' || cell[i] > '9'){
      return false;
    }
  }
  return true;
}




bool isValidNumber(const char* number){
  size_t sz = strlen(number);
  if(sz <= 0){
    return false;
  }
  if(number[0] != '-'  &&  (number[0] < '0' || number[0] > '9')){
    return false;
  }
  int countDot = 0;
  for(int i=1; i<sz; i++){
    if(!(number[i] >= '0' && number[i] <= '9')){
      if(number[i] != '.'){
        return false;
      }
      else{
        countDot++;
        if(countDot >= 2){
          return false;
        }
      }
    }
  }
  return true;
}

bool isValidInt(const char* number){
  size_t sz = strlen(number);
  if(sz <= 0){
    return false;
  }
  if(number[0] != '-'  &&  (number[0] < '0' || number[0] > '9')){
    return false;
  }
  for(int i=1; i<sz; i++){
    if(!(number[i] >= '0' && number[i] <= '9')){
      return false;
    }
  }
  return true;
}

bool isValidDouble(const char* number){
  size_t sz = strlen(number);
  if(sz <= 0){
    return false;
  }
  if(number[0] != '-'  &&  (number[0] < '0' || number[0] > '9')){
    return false;
  }
  int countDot = 0;
  for(int i=1; i<sz; i++){
    if(!(number[i] > '0' && number[i] < '9')){
      if(number[i] != '.'){
        return false;
      }
      else{
        countDot++;
      }
    }
  }
  if(countDot != 1){
    return false;
  }
  return true;
}

bool isValidString(const char* str){
  size_t sz = strlen(str);
  if(sz <= 0){
    return false;
  }
  if(str[0] != '\"'){
    return false;
  }
  if(str[sz-1] != '\"'){
    return false;
  }
  return true;
}

int operationsCount(const char* str){
  size_t sz = strlen(str);
  int count = 0;
  for(int i=0; i<sz; i++){
    if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
      count++;
    }
  }
  return count;
}

int operandsCount(const char* str){
  int count=0;
  int i=1;
  while(i!='\0') {
    while (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*') {
      if(str[i]=='\0'){
        count++;
        return count;
      }
      i++;
    }
    count++;
    i++;
  }
  return count;
}

const char* getOperand(int n, const char* str){
  if(n > operandsCount(str)){
    std::string error = "Couldn't get operrand ";
    error += n;
    error += " from the formula, because it has only ";
    error += operandsCount(str);
    error += " operands\n";
    throw std::invalid_argument(error);
  }
  int count=0;
  int i=1;
  while(i!='\0') {
    if (count == n) {
      int j = i;
      while (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i]!='\0') {
        i++;
      }
      int sz = i-j;
      char *result = new char[sz+1];
      i = 0;
      while (str[j] != '+' && str[j] != '-' && str[j] != '/' && str[j] != '*' && str[i] != '\0'  && i<sz) {
        result[i] = str[j];
        j++;
        i++;
        result[sz] = '\0';
      }
      return result;
    }
    else {
      while (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i]!='\0') {
        i++;
      }
      count++;
      i++;
    }
  }
  std::string error = "Couldn't get operrand ";
  error += n;
  error += " from the formula\n";
  throw std::runtime_error(error);
}

const char getOperator(int n, const char* str){
  int count = -1;
  int i=0;
  size_t sz = strlen(str);
  while(count != n && i<sz){
    if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
      count++;
    }
    i++;
  }
  return str[i-1];
}


bool isValidOperation(const char* str){
  size_t sz = strlen(str);
  if(sz <= 0){
    return false;
  }
  if(str[0] != '='){
    return false;
  }
  if(operandsCount(str) != operationsCount(str)+1){
    return false;
  }
  for(int i=0; i<operandsCount(str); i++){
    if(!isValidString(getOperand(i,str)) && !isValidNumber(getOperand(i,str)) && !isValidCell(getOperand(i,str))){
      return false;
    }
  }
  return true;
}

int strToInt(const char* str){
  size_t sz = strlen(str);
  int result = 0;
  if(str[0] != '-') {
    for (int i = 0; i < sz; i++) {
      result += (str[i] - '0') * pow(10, sz - i - 1);
    }
  }
  else{
    for (int i = 1; i < sz; i++) {
      result += (str[i] - '0') * pow(10, sz - i - 1);
    }
    result *= -1;
  }
  return result;
}

const char* stringWithoutQuotes(const char* value){
  if(isValidString(value)){
    size_t sz = strlen(value);
    char *result = new char[sz - 1];
    for (int i = 0; i < sz - 1; i++) {
      result[i] = value[i + 1];
    }
    result[sz - 2] = 0;
    return result;
  }
  return value;
}


template <typename T>
T convertToNumber(const char* str){
  size_t sz = strlen(str);
  if(isValidDouble(str)){
    double result = atof(str);
    return result;
  }
  else if (isValidInt(str)){
    int result = strToInt(str);
    return result;
  }
  else if(isValidString(str)){
    if(!isValidNumber(stringWithoutQuotes(str))){
      return 0;
    }
    else{
      return convertToNumber<T>(stringWithoutQuotes(str));
    }
  }
  else if(isValidCell(str)){
    try {
      return convertToNumber<T>(Table::getInstance()->getCell<Cell>(str)->getValue());
    }
    catch(std::invalid_argument& e){
      if(strcmp(e.what(), "Couldn't find Cell!")==0){
        return 0;
      }
    }
  }
  else{
    return 0;
  }

}


bool hasAtleastOneDoubleOrHasDivision(const char* str){
  char* operators = new char [operationsCount(str)];
  int operatorCount = operationsCount(str);
  for(int i=0; i<operatorCount; i++){
    operators[i] = getOperator(i,str);
  }

  const char** operands = new const char* [operandsCount(str)];
  int operandCount = operandsCount(str);
  for(int i=0; i<operandCount; i++){
    operands[i] = getOperand(i,str);
  }

  for(int i=0; i<operandCount; i++){
    if(isValidDouble(operands[i])){
      return true;
    }
  }
  for(int i=0; i<operatorCount; i++){
    if(operators[i] == '/')
      return true;
  }
  return false;
}

template <typename T>
std::string calculateOperation(const char* str){
  char* operators = new char [operationsCount(str)];
  int operatorCount = operationsCount(str);
  for(int i=0; i<operatorCount; i++){
    operators[i] = getOperator(i,str);
  }

  const char** operands = new const char* [operandsCount(str)];
  int operandCount = operandsCount(str);
  for(int i=0; i<operandCount; i++){
    operands[i] = getOperand(i,str);
  }

  std::string result;
  for(int i=0; i<operatorCount; i++) {
    if (operators[i] == '/') {
      if (result.empty()) {
        if(convertToNumber<T>(operands[i+1]) == 0)
          result = "#ERROR";
        else
          result = std::to_string(convertToNumber<T>(operands[i]) / convertToNumber<T>(operands[i + 1]));
      }
      else if (strcmp(result.c_str(), operands[i]) == 0) {
        if(convertToNumber<T>(operands[i+1]) == 0)
          result = "#ERROR";
        else
          result = std::to_string(convertToNumber<T>(result.c_str()) / convertToNumber<T>(operands[i + 1]));
      }
      if (strcmp(result.c_str(), operands[i + 1]) == 0) {
        if(convertToNumber<T>(operands[i]) == 0)
          result = "#ERROR";
        else
          result = std::to_string(convertToNumber<T>(result.c_str()) / convertToNumber<T>(operands[i]));
      }
      for (int j = i; j < operatorCount - 1; j++) {
        operators[j] = operators[j + 1];
        operators[operatorCount] = '\0';
      }
      operatorCount--;
      operands[i] = result.c_str();
      for (int j = i + 1; j < operandCount - 1; j++) {
        operands[j] = operands[j + 1];
      }
      operandCount--;
      i--;
    }
  }
  for(int i=0; i<operatorCount; i++) {
    if (operators[i] == '*') {
      if (result.empty())
        result = std::to_string(convertToNumber<T>(operands[i]) * convertToNumber<T>(operands[i + 1]));
      else
      if(strcmp(result.c_str(),operands[i]) == 0)
        result = std::to_string(convertToNumber<T>(result.c_str()) * convertToNumber<T>(operands[i+1]));
      if(strcmp(result.c_str(),operands[i+1]) == 0)
        result = std::to_string(convertToNumber<T>(result.c_str()) * convertToNumber<T>(operands[i]));
      for (int j = i; j < operatorCount - 1; j++) {
        operators[j] = operators[j + 1];
        operators[operatorCount] = '\0';
      }
      operatorCount--;
      operands[i] = result.c_str();
      for (int j = i + 1; j < operandCount - 1; j++) {
        operands[j] = operands[j + 1];
      }
      operandCount--;
      i--;
    }
  }
  for(int i=0; i<operatorCount; i++){
    if(operators[i] == '+'){
      if(result.empty())
        result = std::to_string(convertToNumber<T>(operands[i]) + convertToNumber<T>(operands[i+1]));
      else
        if(strcmp(result.c_str(),operands[i]) == 0)
          result = std::to_string(convertToNumber<T>(result.c_str()) + convertToNumber<T>(operands[i+1]));
        if(strcmp(result.c_str(),operands[i+1]) == 0)
          result = std::to_string(convertToNumber<T>(result.c_str()) + convertToNumber<T>(operands[i]));
        for(int j = i; j<operatorCount-1; j++){
        operators[j] = operators[j+1];
        operators[operatorCount] = '\0';
      }
      operatorCount--;
      operands[i] = result.c_str();
      for(int j = i+1; j<operandCount-1; j++){
        operands[j] = operands[j+1];
      }
      operandCount--;
      i--;
    }
    if(operators[i] == '-'){
      if(result.empty())
        result = std::to_string(convertToNumber<T>(operands[i]) - convertToNumber<T>(operands[i+1]));
      else
      if(strcmp(result.c_str(),operands[i]) == 0)
        result = std::to_string(convertToNumber<T>(result.c_str()) - convertToNumber<T>(operands[i+1]));
      if(strcmp(result.c_str(),operands[i+1]) == 0)
        result = std::to_string(convertToNumber<T>(result.c_str()) - convertToNumber<T>(operands[i]));
      for(int j = i; j<operatorCount-1; j++){
        operators[j] = operators[j+1];
        operators[operatorCount] = '\0';
      }
      operatorCount--;
      operands[i] = result.c_str();
      for(int j = i+1; j<operandCount-1; j++){
        operands[j] = operands[j+1];
      }
      operandCount--;
      i--;
    }
  }
  if(typeid(T) == typeid(double))
    result.erase(result.find_last_not_of('0') + 1, std::string::npos);    //<---------- deletes all tailing zeroes from double number
  return result;
}

const char* withoutSpaces(const char* str){
  size_t sz = strlen(str);
  int countWhiteSpaces = 0;
  for(int i=0; i<sz; i++){
    if(str[i] == ' '){
      countWhiteSpaces++;
    }
  }
  size_t resultSz = sz - countWhiteSpaces;
  char* result = new char[resultSz + 1];
  int j=0;
  for(int i=0; i<sz; i++) {
    if (str[i] != ' ') {
      result[j] = str[i];
      j++;
    }
  }
  result[resultSz] = '\0';
  return result;
}

bool isValidInput(const char* str){
  return isValidNumber(withoutSpaces(str)) || isValidOperation(withoutSpaces(str)) || isValidString(str);
}




char getMaxChar(const std::vector<Cell*>& vector){
  if(vector.empty()){
    throw std::out_of_range("Vector is empty\n");
  }
  char max = vector[0]->getName()[0];
  for(int i=1; i<vector.size(); i++){
    if(max < vector[i]->getName()[0]){
      max = vector[i]->getName()[0];
    }
  }
  return max;
}


char widthToChar(int width){
  return width + 'A';
}


char* getNumFromName(const char* name){
  int len = strlen(name);
  char* number = new char[len];
  for(int i=0; i<len-1; i++){
    number[i] = name[i+1];
  }
  number[len-1] = '\0';
  return number;
}


int getMaxNum(const std::vector<Cell*>& vector){
  if(vector.empty()){
    throw std::out_of_range("Vector is empty\n");
  }
  int max = strToInt(getNumFromName(vector[0]->getName()));
  for(int i=1; i<vector.size(); i++){
    if(max < strToInt(getNumFromName(vector[i]->getName()))){
      max = strToInt(getNumFromName(vector[i]->getName()));
    }
  }
  return max;
}


bool checkForError(const char* str){
  int operandCount = operandsCount(str);
  const char** operands = new const char* [operandCount];
  for (int i = 0; i < operandCount; i++) {
    operands[i] = getOperand(i, str);
  }
  for (int i = 0; i < operandCount; i++) {
    if(isValidCell(operands[i])){
      if(strcmp(Table::getInstance()->getCell<Cell>(operands[i])->getValue(), "#ERROR")==0)
        return true;
    }
  }
  return false;
}



bool checkForInfiniteLoopFormulas(Cell* cell, const char* formula) {
  const char* ID = cell->getName();
  int operandCount = operandsCount(formula);
  const char** operands = new const char* [operandCount];
  for (int i = 0; i < operandCount; i++) {
    operands[i] = getOperand(i, formula);
  }
  for (int i = 0; i < operandCount; i++) {
    if (isValidCell(operands[i]) && (strcmp(Table::getInstance()->getCell<Cell>(operands[i])->getCellType(), "formula") == 0)) {
      if (strcmp(ID, operands[i])==0) {   // A1     operand[0] A1    A1=A1+1
        return true;
      }
      else{  //    A1   A2    A2=A1+1   A1=A2+1
        int operandOperands = operandsCount(operands[i]);
        for(int j=0; j<operandOperands; j++){
          if(strcmp(ID, (Table::getInstance()->getCell<FormulaCell>(operands[i]))->operator[](j)) == 0){
            return true;
          }
          else if(strcmp(Table::getInstance()->getCell<FormulaCell>(operands[i])->getName(), ID) != 0)
            return checkForInfiniteLoopFormulas(cell, Table::getInstance()->getCell<FormulaCell>(operands[i])->getUncalculatedValue());
          else continue;
        }
      }
    }
  }
  return false;
}
