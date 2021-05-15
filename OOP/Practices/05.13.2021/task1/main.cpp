#include <iostream>
#include <fstream>
#include <cstring>


int main(int args, char* arg[]){
  std::ifstream in("/home/dahudohu/CLionProjects/University/OOP/Practices/05.13.2021/task1/text");
  char ch;
  int lines = 1;
  int chars = 0;
  char buff[500];

  in.seekg(0,std::ios::end);
  std::cout << in.tellg() << std::endl;

  if(in.good()){
    while(in.get(buff,500)){
      std::cout << buff << std::endl;
      std::cout << strlen(buff) << std::endl;
//      chars++;
//      if(ch == '\n') lines++;
    }

    std::cout << "\n" << "Lines: " << lines << "  Chars: " << chars;
    in.close();
  }



  return 0;
}