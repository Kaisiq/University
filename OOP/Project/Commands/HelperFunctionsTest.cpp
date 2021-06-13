#include "HelperFunctions.cpp"
#include "../Cell/Cell.cpp"
#include "OOP/Project/Cell/DoubleCell/DoubleCell.h"
#include "OOP/Project/Cell/FormulaCell/FormulaCell.h"
#include "OOP/Project/Cell/IntCell/IntCell.h"
#include "OOP/Project/Cell/StringCell/StringCell.h"
#include "catch_amalgamated.cpp"
#include <cstring>
#include <iostream>
#include <vector>

Table* Table::instance = nullptr;

//int getMaxNum(const std::vector<Cell*>& vector);
//char getMaxChar(const std::vector<Cell*>& vector);
TEST_CASE("getMaxChar(const std::vector<Cell*>& vector)"
          "getMaxNum(const std::vector<Cell*>& vector)"){

  Table::getInstance()->editMember("A12", "12");
  Table::getInstance()->editMember("K64", "12");
  Table::getInstance()->editMember("D32", "12");

  REQUIRE((getMaxChar(Table::getInstance()->getTable()) == 'K'));
  REQUIRE(getMaxNum(Table::getInstance()->getTable()) == 64);
}


//char* tolower(const char* str);
TEST_CASE("tolower(const char* str"){
  REQUIRE(strcmp("test123hello space", tolower("TeSt123HeLLo SpACE")) == 0);
}

//bool isValidCell(const char* cell);
TEST_CASE("isValidCell(const char* cell)"){
  REQUIRE(isValidCell("A1"));
  REQUIRE(!isValidCell("some string"));
  REQUIRE(!isValidCell("123"));
  REQUIRE(!isValidCell("K1234K"));
  REQUIRE(!isValidCell("=A1"));
  REQUIRE(!isValidCell("A1-2+3"));
  REQUIRE(isValidCell("Z14000"));
}


//bool isValidNumber(const char* number);
TEST_CASE("isValidNumber(const char* number)"){
  REQUIRE(isValidNumber("123"));
  REQUIRE(isValidNumber("0.2"));
  REQUIRE(isValidNumber("23.45"));
  REQUIRE(isValidNumber("123.12312"));
  REQUIRE(isValidNumber("1231231200000000000"));
  REQUIRE(!isValidNumber("string"));
  REQUIRE(!isValidNumber("hello world"));
  REQUIRE(!isValidNumber("4no"));
  REQUIRE(!isValidNumber("A1"));
  REQUIRE(isValidNumber("-12"));
  REQUIRE(isValidNumber("-12.345"));
  REQUIRE(!isValidNumber("=B2+A3"));
}
//bool isValidDouble(const char* number);
TEST_CASE("isValidDouble(const char* number)"){
  REQUIRE(!isValidDouble("123"));
  REQUIRE(isValidDouble("0.2"));
  REQUIRE(isValidDouble("23.45"));
  REQUIRE(isValidDouble("123.12312"));
  REQUIRE(!isValidDouble("1231231200000000000"));
  REQUIRE(!isValidDouble("string"));
  REQUIRE(!isValidDouble("hello world"));
  REQUIRE(!isValidDouble("4no"));
  REQUIRE(!isValidDouble("A1"));
  REQUIRE(!isValidDouble("-12"));
  REQUIRE(isValidDouble("-12.345"));
  REQUIRE(!isValidDouble("=B2+A3"));
}
//bool isValidString(const char* str);
TEST_CASE("isValidString(const char* number)"){
  REQUIRE(!isValidString("123"));
  REQUIRE(!isValidString("0.2"));
  REQUIRE(!isValidString("23.45"));
  REQUIRE(!isValidString("123.12312"));
  REQUIRE(!isValidString("1231231200000000000"));
  REQUIRE(!isValidString("string"));
  REQUIRE(!isValidString("hello world"));
  REQUIRE(!isValidString("4no"));
  REQUIRE(!isValidString("A1"));
  REQUIRE(!isValidString("-12"));
  REQUIRE(!isValidString("-12.345"));
  REQUIRE(isValidString("\"=B2+A3\""));
  REQUIRE(isValidString("\"some random string\""));
  REQUIRE(isValidString("\"1231231233\""));
  REQUIRE(isValidString("\"-124.23\""));
}
//int operationsCount(const char* str);
TEST_CASE("operationsCount(const char* str)") {
  REQUIRE(operationsCount("=12+3+4+5") == 3);
  REQUIRE(operationsCount("=123*1/249*2+123-124/1/1/1+14-123*14") == 11);
}
//int operandsCount(const char* str);
TEST_CASE("operandsCount(const char* str)") {
  REQUIRE(operandsCount("=12+3+4+5") == 4);
  REQUIRE(operandsCount("=123*1/249*2+123-124/1/1/1+14-123*14") == 12);
}
//const char* getOperand(int n, const char* str);
TEST_CASE("getOperand(int n, const char* str)") {
  REQUIRE(strcmp(getOperand(0, "=12+3+4+5"), "12") == 0);
  REQUIRE(strcmp(getOperand(1, "=12+3+4+5"), "3") == 0);
  REQUIRE(strcmp(getOperand(2, "=12+3+4+5"), "4") == 0);
  REQUIRE(strcmp(getOperand(3, "=12+3+4+5"), "5") == 0);
  REQUIRE(strcmp(getOperand(0,"=123*1/249*2+123-124/1/1/1+14-123*14"), "123")==0);
  REQUIRE(strcmp(getOperand(1,"=123*1/249*2+123-124/1/1/1+14-123*14"), "1")==0);
  REQUIRE(strcmp(getOperand(2,"=123*1/249*2+123-124/1/1/1+14-123*14"), "249")==0);
  REQUIRE(strcmp(getOperand(3,"=123*1/249*2+123-124/1/1/1+14-123*14"), "2")==0);
  REQUIRE(strcmp(getOperand(4,"=123*1/249*2+123-124/1/1/1+14-123*14"), "123")==0);
  REQUIRE(strcmp(getOperand(5,"=123*1/249*2+123-124/1/1/1+14-123*14"), "124")==0);
  REQUIRE(strcmp(getOperand(6,"=123*1/249*2+123-124/1/1/1+14-123*14"), "1")==0);
}
//const char getOperator(int n, const char* str);
TEST_CASE("getOperator(int n, const char* str)") {
  REQUIRE(getOperator(0, "=12+3-4*5") == '+');
  REQUIRE(getOperator(1, "=12+3-4*5") == '-');
  REQUIRE(getOperator(2, "=12+3-4*5") == '*');
  REQUIRE(getOperator(0,"=123*1/249*2+123-124/1/1/1+14-123*14") == '*');
  REQUIRE(getOperator(1,"=123*1/249*2+123-124/1/1/1+14-123*14") == '/');
  REQUIRE(getOperator(2,"=123*1/249*2+123-124/1/1/1+14-123*14") == '*');
  REQUIRE(getOperator(3,"=123*1/249*2+123-124/1/1/1+14-123*14") == '+');
  REQUIRE(getOperator(4,"=123*1/249*2+123-124/1/1/1+14-123*14") == '-');
  REQUIRE(getOperator(5,"=123*1/249*2+123-124/1/1/1+14-123*14") == '/');

}
//bool isValidOperation(const char* str);
TEST_CASE("isValidOperation(const char* number)"){
  REQUIRE(!isValidOperation("123"));
  REQUIRE(!isValidOperation("0.2"));
  REQUIRE(!isValidOperation("23.45"));
  REQUIRE(!isValidOperation("123.12312"));
  REQUIRE(!isValidOperation("1231231200000000000"));
  REQUIRE(!isValidOperation("string"));
  REQUIRE(!isValidOperation("hello world"));
  REQUIRE(!isValidOperation("4no"));
  REQUIRE(!isValidOperation("A1"));
  REQUIRE(!isValidOperation("-12"));
  REQUIRE(!isValidOperation("-12.345"));
  REQUIRE(!isValidOperation("\"=B2+A3\""));
  REQUIRE(!isValidOperation("\"some random string\""));
  REQUIRE(!isValidOperation("\"1231231233\""));
  REQUIRE(!isValidOperation("\"-124.23\""));
  REQUIRE(isValidOperation("=A1"));
}
//int strToInt(const char* str);
TEST_CASE("strToInt(const char* str)"){
  REQUIRE(12 == strToInt("12"));
  REQUIRE(1245125 == strToInt("1245125"));
  REQUIRE(0 == strToInt("0"));
  REQUIRE(-12 == strToInt("-12"));
}
//const char* stringWithoutQuotes(const char* value);
TEST_CASE("stringWithoutQuotes(const char* value)"){
  REQUIRE(strcmp("test 123", stringWithoutQuotes("\"test 123\"")) == 0) ;
  REQUIRE(strcmp("1242356.23523", stringWithoutQuotes("\"1242356.23523\"")) == 0) ;
  REQUIRE(strcmp("test 123", stringWithoutQuotes("test 123")) == 0) ;
  REQUIRE(strcmp("1242356.23523", stringWithoutQuotes("1242356.23523")) == 0) ;
}
//template <typename T>
//T convertToNumber(const char* str);
TEST_CASE("convertToNumber(const char* str)"){
  REQUIRE(convertToNumber<int>("-12") == -12);
  REQUIRE(convertToNumber<int>("12") == 12);
  REQUIRE(convertToNumber<int>("0") == 0);
  REQUIRE(convertToNumber<double>("-12") == -12);
  REQUIRE(convertToNumber<double>("-12.34") == -12.34);
  REQUIRE(convertToNumber<double>("0") == 0);
  REQUIRE(convertToNumber<double>("12") == 12);
  REQUIRE(convertToNumber<double>("12.34") == 12.34);
}

//bool hasAtleastOneDoubleOrHasDivision(const char* str);
TEST_CASE("intToCharArr(hasAtleastOneDoubleOrHasDivision(const char* str)") {
  REQUIRE(hasAtleastOneDoubleOrHasDivision("=1/2"));
  REQUIRE(hasAtleastOneDoubleOrHasDivision("=1+2-4/2"));
  REQUIRE(hasAtleastOneDoubleOrHasDivision("=1/2/2/2/2"));
  REQUIRE(!hasAtleastOneDoubleOrHasDivision("=1+2+2-2-4*4*2"));
  REQUIRE(!hasAtleastOneDoubleOrHasDivision("0"));
  REQUIRE(hasAtleastOneDoubleOrHasDivision("=1+2+2-2-4*4*2.3"));
  REQUIRE(!hasAtleastOneDoubleOrHasDivision("=1+2+2-2-4*4*2"));
}


//const char* withoutSpaces(const char* str);
TEST_CASE("withoutSpaces(const char* str)"){
  REQUIRE(strcmp(withoutSpaces("he ll o o, t hi s   is  a s tring with   ma ny  spaces   "), "helloo,thisisastringwithmanyspaces") == 0);
  REQUIRE(strcmp(withoutSpaces("helloo,thisisastringwithmanyspaces"), "helloo,thisisastringwithmanyspaces") == 0);
}

//bool isValidInput(const char* str);
TEST_CASE("isValidInput(const char* str)"){
  REQUIRE(isValidInput("123"));
  REQUIRE(isValidInput("0.2"));
  REQUIRE(isValidInput("23.45"));
  REQUIRE(isValidInput("123.12312"));
  REQUIRE(isValidInput("1231231200000000000"));
  REQUIRE(!isValidInput("string"));
  REQUIRE(!isValidInput("hello world"));
  REQUIRE(!isValidInput("4no"));
  REQUIRE(!isValidInput("A1"));
  REQUIRE(isValidInput("-12"));
  REQUIRE(isValidInput("-12.345"));
  REQUIRE(isValidInput("\"=B2+A3\""));
  REQUIRE(isValidInput("\"some random string\""));
  REQUIRE(isValidInput("\"1231231233\""));
  REQUIRE(isValidInput("\"-124.23\""));
  REQUIRE(isValidInput("=A1"));
}

//char widthToChar(int width);
TEST_CASE("widthToChar(int width)"){
  REQUIRE(widthToChar(10) == 'K');
  REQUIRE(widthToChar(15) == 'P');
  REQUIRE(widthToChar(15) != 'K');
  REQUIRE(widthToChar(17) == 'R');
  REQUIRE(widthToChar(25) == 'Z');
}

//char* getNumFromName(const char* name);
TEST_CASE("getNumFromName(const char* name)"){
  REQUIRE(strcmp(getNumFromName("A1253"), "1253") == 0);
  REQUIRE(strcmp(getNumFromName("A9999"), "9999") == 0);
  REQUIRE(strcmp(getNumFromName("Z124"), "120453") != 0);
}


//bool isValidInt(const char* number);
TEST_CASE("isValidInt(const char* number)"){
  REQUIRE(isValidInt("12"));
  REQUIRE(isValidInt("23325235"));
  REQUIRE(!isValidInt("12.4"));
  REQUIRE(!isValidInt("asdasd"));
  REQUIRE(isValidInt("-12"));
}