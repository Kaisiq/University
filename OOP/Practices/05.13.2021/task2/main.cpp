#include <fstream>
#include <iostream>
#include <cstring>

int main(){
  std::ifstream file1("/home/dahudohu/CLionProjects/University/OOP/Practices/05.13.2021/task2/getNums", std::ios::binary);
  std::ifstream file2("/home/dahudohu/CLionProjects/University/OOP/Practices/05.13.2021/task2/numbers", std::ios::binary);
  std::ofstream output("/home/dahudohu/CLionProjects/University/OOP/Practices/05.13.2021/task2/output", std::ios::binary);

  uint32_t x,y;

  while(true){
    file1.read((char*)&x, sizeof(x));
    if(file1){
      break;
    }
    file1.read((char*)&y, sizeof(y));

    file2.seekg(x*sizeof(x), std::ios::beg);

    uint32_t temp;
    for(int i=0; i<y; i++){
      file2.read((char*)&temp, sizeof(temp));
      output.write((const char*)&temp, sizeof(temp));
    }
  }
  std::cout << "a \n a";
  file1.close();
  file2.close();
  output.close();

  return 0;
}