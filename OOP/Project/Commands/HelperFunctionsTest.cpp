#include "catch_amalgamated.cpp"
#include "../Cell/Cell.cpp"
#include "HelperFunctions.cpp"

Table* Table::instance = nullptr;

TEST_CASE("getMaxChar"){
  std::vector<Cell> vector;
  Cell a("A12", "12");
  Cell b("K64", "\"asd\"");
  Cell c("D32", "\"asd\"");
  vector.push_back(a);
  vector.push_back(b);
  vector.push_back(c);

  char str[256] = "A12";
  char str2[256] = "K64";
  char str3[256] = "D32";
//
//  Table::getInstance()->editMember(str, "12");
//  Table::getInstance()->editMember(str2, "12");
//  Table::getInstance()->editMember(str3, "12");

  std::cout << getMaxChar(vector);
  std::cout << getMaxNum(vector);
  std::cout << "\n\n\n" << getMaxChar(Table::getInstance()->getTable()) << getMaxNum(Table::getInstance()->getTable()) << std::endl;
  Table::getInstance()->printTable();
}