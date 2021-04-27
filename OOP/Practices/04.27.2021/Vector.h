#pragma once
#include <iostream>

class Vector{
private:
  unsigned size;
  double* lengths;
public:
  Vector(const unsigned size);
  Vector(const Vector& rhs);
  Vector& operator=(Vector rhs);
  Vector(const unsigned size, const double*);
  Vector(const double x, const double y);
  Vector(const double x, const double y, const double z);
  ~Vector();

  void sumVectors(const Vector& a);
  void subVectors(const Vector& a);
  Vector multiplyVector(Vector a, const double number) const;
  double dotProduct(const Vector& a) const;
  void changeCoordinate(const unsigned, const double newCoord);
  const unsigned int getSize() const;
  void resize(unsigned newSize);
  void printVector();

  const Vector operator+(const Vector& rhs) const;
  Vector& operator+=(const Vector& rhs);
  const Vector operator-(const Vector& rhs) const;
  Vector& operator-=(const Vector& rhs);

  Vector& operator++();
  const Vector operator++(int);
  Vector& operator--();

  friend std::istream& operator>>(std::istream& in, Vector& v);
  friend std::ostream& operator<<(std::ostream& out, Vector& v);

  operator bool() const;
  operator double() const;

  const Vector operator*(const double number) const;
  Vector& operator*=(const double number);
  double operator*(const Vector& rhs) const;
  Vector& operator*=(const Vector& rhs);
  double operator[](const size_t index) const;
  bool operator>(const Vector& rhs) const;
  bool operator<(const Vector& rhs)const;
  bool operator>=(const Vector& rhs)const;
  bool operator<=(const Vector& rhs)const;
  bool operator==(const Vector& rhs)const;
  bool operator!=(const Vector& rhs)const;
};