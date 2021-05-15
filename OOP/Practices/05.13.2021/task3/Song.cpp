#include "Song.h"
#include <cstring>

Song::Song(const char* author, const char* title, uint32_t, uint32_t)
: size(size), time(time)
{
  this->author = new char[strlen(author)+1];
  strcpy(this->author,author);
  this->title = new char[strlen(title)+1];
  strcpy(this->author,title);
}
Song::~Song(){
  delete[] author;
  delete[] title;
}
void Song::save(std::fstream &fd){
  uint32_t len = strlen(title)+ 1;
  fd.write((const char*)&len, sizeof(len));
  fd.write(title,len);

  len = strlen(author)+ 1;
  fd.write((const char*)&len, sizeof(len));
  fd.write(author,len);


  fd.write((const char*)&size, sizeof(size));
  fd.write((const char*)&time, sizeof(time));

}

