#include <fstream>
#include <iostream>
#include "Bank.cpp"

unsigned int Bank::num = 0;
int main(){
  Bank bank1("Bank",10);

  std::fstream in ("/home/dahudohu/CLionProjects/University/OOP/Practices/05.11.2021/input");
//  in.open("/home/dahudohu/CLionProjects/University/OOP/Practices/05.11.2021/input", std::ios::in | std::ios::out);

  if(in.is_open()){
    in >> bank1;
    in.close();
    std::cout << bank1 << std::endl;
  }


  std::ofstream out;
  out.open("/home/dahudohu/CLionProjects/University/OOP/Practices/05.11.2021/output");
  if(out.good()){
    out << bank1;
    out.close();
  }
  else{
    std::cout << "penisgei";
  }
  return 0;
}