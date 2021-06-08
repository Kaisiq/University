#pragma once
#include <iostream>


class Registration{
private:
  char registration[9];
public:
  Registration();
  Registration(const char* str);
  Registration& operator=(const char* str);
  bool operator==(const char* str) const;
  const char *toString() const;
};