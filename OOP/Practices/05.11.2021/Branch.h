#pragma once

class Branch{
  unsigned int ID;
  char* address;
  int coefficient;
public:
  Branch();
  Branch(char* address, int coef, unsigned int ID);
  ~Branch();
  Branch(const Branch&);
  Branch &operator=(const Branch&);
  void operator++();
  const int getCoef() const;
  friend std::ostream& operator<< (std::ostream& out, const Branch& branch);
  friend std::istream& operator>> (std::istream& in, Branch& branch);
};
