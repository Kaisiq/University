#pragma once

class Song{
  char* author;
  char* title;
  uint32_t size;
  uint32_t time;

public:
  Song(const char*, const char*, uint32_t, uint32_t);
  ~Song();
  void save();
  void save(std::fstream &fd);
};