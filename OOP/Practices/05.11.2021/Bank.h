#pragma once
#include "Branch.cpp"
class Bank{
  std::string name;
  Branch* branches;
  unsigned int clients;
  unsigned int ID;
  static unsigned int num;
public:
  Bank(std::string name, unsigned int clients);
  ~Bank();
  Bank(const Bank&);
  Bank &operator=(const Bank&);
  void operator++(int id);
  const int getCoef() const;
  const int getWorstCoef() const;
  Bank &operator+=(Bank&);
  const unsigned int getBankCount() const;
  friend void compareTwoBanks(Bank& bank1, Bank& bank2);
  friend std::ostream& operator << (std::ostream& out, const Bank& bank);
  friend std::istream& operator >> (std::istream& in, Bank& bank);
};