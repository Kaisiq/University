#pragma once
#include <cmath>

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

void swapValues(std::vector<Cell>& table, int i, int j){
  Cell a = table[i];
  table[i] = table[j];
  table[j] = a;
}

void sortTable(std::vector<Cell>& table){
  int sz = table.size();
  for(int i=0; i<sz-1; i++){
    int min = i;
    for(int j=i+1; j<sz; j++){
      if(strcmp(table[i].getName(), table[j].getName()) > 0){
        min = j;
      }
    }
    swapValues(table, min, i);
  }
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

char* getOperand(int n, const char* str){
  if(n > operandsCount(str)){
    throw std::invalid_argument("Operands are less than that!\n");
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
      char* result = new char[sz];
      i = 0;
      while (str[j] != '+' && str[j] != '-' && str[j] != '/' && str[j] != '*' && str[i]!='\0') {
        result[i] = str[j];
        j++;
        i++;
      }
      return result;
    } else {
      while (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i]!='\0') {
        i++;
      }
      count++;
      i++;
    }
  }
  throw std::runtime_error("error\n");
}

char getOperator(int n, const char* str){
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
  for(int i=0; i<sz; i++){
    result += (str[i] - '0') * pow(10, sz-i-1);
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
  if(isValidNumber(str)){
    if(isValidDouble(str)){
      int toDot = 0;
      while(str[toDot] != '.' && str[toDot] != '\0'){
        toDot++;
      }
      double result = 0;
      for(int i=0; i<toDot; i++){
        result += (str[i] - '0') * pow(10, toDot-i-1);
      }
      for(int i=toDot+1; i<sz; i++){
        result += (str[i] - '0') * pow(0.1 , i-toDot);
      }
      return result;
    }
    else{
      int result = strToInt(str);
      return result;
    }
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
    return convertToNumber<T>(Table::getInstance()->getCell(str)->getValue());
  }
  else{
    return 0;
  }

}

char* intToCharArr(const int a){
  int b = a;
  int len=0;
  while(b!=0){
    b/=10;
    len++;
  }
  int integer[len];
  b = a;
  for(int i=0; i<len; i++){
    integer[i] = b/pow(10,len-i-1);
  }
  char* result = new char[len+1];
  for(int i=0; i<len; i++){
    result[i] = integer[i] + '0';
  }
  result[len] = '\0';
  return result;
}


bool hasAtleastOneDoubleOrHasDivision(const char* str){
  char* operators = new char [operationsCount(str)];
  int operatorCount = operationsCount(str);
  for(int i=0; i<operatorCount; i++){
    operators[i] = getOperator(i,str);
  }

  char** operands = new char* [operandsCount(str)];
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
      if (result.empty())
        result = std::to_string(convertToNumber<T>(operands[i]) / convertToNumber<T>(operands[i + 1]));
      else if (strcmp(result.c_str(), operands[i]) == 0)
        result = std::to_string(convertToNumber<T>(result.c_str()) / convertToNumber<T>(operands[i + 1]));
      if (strcmp(result.c_str(), operands[i + 1]) == 0)
        result = std::to_string(convertToNumber<T>(result.c_str()) / convertToNumber<T>(operands[i]));
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




char getMaxChar(const std::vector<Cell>& vector){
  if(vector.empty()){
    throw std::out_of_range("Vector is empty\n");
  }
  char max = vector[0].getName()[0];
  for(int i=1; i<vector.size(); i++){
    if(max < vector[i].getName()[0]){
      max = vector[i].getName()[0];
    }
  }
  return max;
}


char widthToChar(int width){
  return width + 'A';
}


char* getNumFromName(const char* name){
  int len = strlen(name);
  char* number = new(std::nothrow) char[len];
  for(int i=0; i<len-1; i++){
    number[i] = name[i+1];
  }
  number[len-1] = '\0';
  return number;
}


int getMaxNum(const std::vector<Cell>& vector){
  if(vector.empty()){
    throw std::out_of_range("Vector is empty\n");
  }
  int max = strToInt(getNumFromName(vector[0].getName()));
  for(int i=1; i<vector.size(); i++){
    if(max < strToInt(getNumFromName(vector[i].getName()))){
      max = strToInt(getNumFromName(vector[i].getName()));
    }
  }
  return max;
}
