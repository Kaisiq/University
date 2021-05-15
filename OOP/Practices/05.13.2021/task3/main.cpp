#include <iostream>
#include <fstream>
#include "Song.cpp"

uint32_t findSong(std::fstream &fd, const char *name) {
  fd.seekg(0,std::ios::beg);
  uint32_t len = std::strlen(name);

  uint32_t idx = -1;
  char* songTitle;
  uint32_t size;
  while(fd){
    idx = fd.tellg();
    fd.read((char*)&size, sizeof(size));
    if(fd.eof()){
      return idx = -1;
    }

    if(size != len){
      continue;
    }
    else{
      songTitle = new char[size];
      fd.read(songTitle, size);
      if(strcmp(songTitle,name) == 0){
        delete[] songTitle;

        return idx;
      }
      delete[] songTitle;
    }
    fd.read((char*)&size, sizeof(size));
    fd.seekp(size + 2*sizeof(uint32_t), std::ios::cur);
  }
  return -1;
}


void deleteSong(std::fstream& fd, const char* songName){
  int32_t  pos = findSong(fd,songName);
  if(pos == -1){
    return;
  }

  std::fstream temp("temp", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
  fd.seekp(0,std::ios::beg);

  uint32_t len;
  char* buff;
  uint32_t size, time;

  while(pos!= fd.tellg()){
    fd.read((char*)&len, sizeof(len));
    temp.write((const char*)&len, sizeof(len));
    buff = new char[size];
    fd.read(buff,len);
    temp.write(buff,len);
    delete[] buff;

    fd.read((char*)&len, sizeof(len));
    temp.write((const char*)&len, sizeof(len));

    buff = new char[size];
    fd.read(buff,len);
    temp.write(buff,len);
    delete[] buff;

    fd.read((char*)&size, sizeof(size));
    temp.write((const char*)&size, sizeof(size));

    fd.read((char*)&time, sizeof(time));
    temp.write((const char*)&time, sizeof(time));
  }

  fd.read((char*)&len, sizeof(len));
  fd.seekp(len,std::ios::cur);

  fd.seekp(len+ 2*sizeof(uint32_t), std::ios::cur);

  temp << fd.rdbuf();
  fd.close();

  fd.open("/home/dahudohu/CLionProjects/University/OOP/Practices/05.13.2021/task3/songs", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

  temp.seekp(0,std::ios::beg);
  fd << temp.rdbuf();

  temp.close();
  std::remove("temp");

}


void output(std::fstream& fd){
  fd.seekp(0, std::ios::beg);

  uint32_t  len;
  char *buff;
  uint32_t size,time;

  while(fd){
    fd.read((char*)&len, sizeof(len));
    buff = new char[len];
    fd.read(buff,len);
    std::cout << buff << std::endl;
    delete[] buff;

    fd.read((char*)&len, sizeof(len));

    buff = new char[len];
    fd.read(buff,len);
    std::cout << buff << std::endl;
    delete[] buff;

    fd.read((char*)&size, sizeof(size));

    fd.read((char*)&time, sizeof(time));

    std::cout << size << " " << time << std::endl;
  }

}


int main(){
  std::fstream fd("/home/dahudohu/CLionProjects/University/OOP/Practices/05.13.2021/task3/songs", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
  Song song1("fiki storaro", "bum", (uint32_t)300, (uint32_t)120);
  Song song2("fiki storaro", "djale", (uint32_t)300, (uint32_t)120);
  Song song3("fiki storaro", "zajdi zajdi", (uint32_t)300, (uint32_t)120);

  song1.save(fd);
  song2.save(fd);
  song3.save(fd);

  output(fd);
  deleteSong(fd,"bum");
  output(fd);
  fd.close();


  return 0;

}