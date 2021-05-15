#include <fstream>
#include <iostream>

struct Song{
  char ch;
  int time;
  int size;
};


int main(){
  std::fstream fd;
  fd.open("/home/dahudohu/CLionProjects/University/OOP/Practices/05.13.2021/task3/song", std::ios::out);
  fd.close();
  fd.open("/home/dahudohu/CLionProjects/University/OOP/Practices/05.13.2021/task3/song", std::ios::in | std::ios::out | std::ios::binary);

  Song song;
  song.ch = 'a';
  song.time = 15;
  song.size = 20;

  fd.write((const char*)&song , sizeof(song));


  fd.seekg(0, std::ios::beg);

  Song song1;
//  fd.read((char*)&song1.ch, sizeof(song1.ch));
//  fd.read((char*)&song1.time, sizeof(song1.time));
//  fd.read((char*)&song1.size, sizeof(song1.size));
//
//
  fd.read((char*)&song1, sizeof(song1));
  std::cout << song1.ch << std::endl;
  std::cout << song1.time << std::endl;
  std::cout << song1.size << std::endl;





  fd.close();
  return 0;

}