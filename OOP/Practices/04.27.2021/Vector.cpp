#include "Vector.h"
#include <cassert>
#include <cmath>
Vector::Vector(const unsigned size){
  this->size = size;
  this->lengths = new(std::nothrow) double[this->size];
  for(int i=0; i<this->size; i++) {
    this->lengths[i] = 0;
  }
}

Vector::Vector(const Vector& v) : Vector(v.size, v.lengths){
}

Vector& Vector::operator=(Vector v){
  if(*this==v){
    return *this;
  }
  else{
    delete[] lengths;
    this->lengths = new(std::nothrow) double[v.size];
    for(int i=0; i<v.getSize(); i++){
      this->lengths[i] = v.lengths[i];
    }
    this->size = v.size;
    return *this;
  }
}


Vector::Vector(const unsigned size, const double* arr){
  this->size = size;
  this->lengths = new(std::nothrow) double[this->size];
  for(int i=0;i<this->size;i++){
    this->lengths[i] = arr[i];
  }
}

Vector::Vector(const double x, const double y){
  this->size = 2;
  this->lengths = new(std::nothrow) double[2];
  this->lengths[0] = x;
  this->lengths[1] = y;
}

Vector::Vector(const double x, const double y, const double z){
  this->size = 3;
  this->lengths = new(std::nothrow) double[3];
  this->lengths[0] = x;
  this->lengths[1] = y;
  this->lengths[2] = z;
}

Vector::~Vector(){
  delete[] this->lengths;
}

void Vector::sumVectors(const Vector& a){
  assert(this->getSize() == a.getSize());
  unsigned rSize = a.getSize();
  for(int i=0; i<rSize; i++){
    this->lengths[i] += a.lengths[i];
  }
}

void Vector::subVectors(const Vector& a){
  assert(this->getSize() == a.getSize());
  unsigned rSize = a.getSize();
  for(int i=0; i<rSize; i++){
    this->lengths[i] -= a.lengths[i];
  }
}

Vector Vector::multiplyVector(Vector a, const double number) const {
  assert(size>0);
  unsigned rSize = a.getSize();
  double* result = new(std::nothrow) double[rSize];
  for(int i=0; i<rSize; i++){
    result[i] = a.lengths[i]*number;
  }
  delete[] a.lengths;
  a.lengths = result;
  return a;
}

double Vector::dotProduct(const Vector& a) const {
  assert(a.getSize() == this->getSize());
  double result = 0;
  unsigned rSize = a.getSize();
  for(int i=0; i<rSize; i++){
    result += a.lengths[i] * this->lengths[i];
  }
  return result;
}

void Vector::changeCoordinate(const unsigned coord, const double newCoord){
  assert(coord < this->size);
  this->lengths[coord] = newCoord;
}

const unsigned int Vector::getSize() const{
  return this->size;
}

void Vector::resize(unsigned newSize){
  double* result = new(std::nothrow) double[newSize];
  unsigned oldSize = this->getSize();
  for(int i=0; i<oldSize; i++){
    result[i] = this->lengths[i];
  }
  if(newSize>oldSize){
    for(unsigned i=oldSize; i<newSize; i++){
      result[i] = 0;
    }
  }
  delete[] this->lengths;
  this->lengths = result;
  this->size = newSize;
}

void Vector::printVector(){
  unsigned countTo = this->getSize();
  if(countTo == 2){
    std::cout << "X" << " = " << this->lengths[0] << '\n';
    std::cout << "Y" << " = " << this->lengths[1] << "\n\n";
  }
  else if(countTo == 3){
    std::cout << "X" << " = " << this->lengths[0] << '\n';
    std::cout << "Y" << " = " << this->lengths[1] << '\n';
    std::cout << "Z" << " = " << this->lengths[2] << "\n\n";
  }
  else {
    for (int i = 0; i < countTo; i++) {
      std::cout << "X" << i + 1 << "= " << this->lengths[i] << '\n';
    }
    std::cout << "\n";
  }
}

const Vector Vector::operator+(const Vector& rhs) const{
    unsigned rSize = rhs.getSize();
    Vector result(rSize);
    result.sumVectors(rhs);
    result.sumVectors(*this);
    return result;
}

Vector& Vector::operator+=(const Vector& rhs){
  this->sumVectors(rhs);
  return *this;
}

const Vector Vector::operator-(const Vector& rhs) const{
  unsigned rSize = rhs.getSize();
  Vector result(rSize);
  result.sumVectors(*this);
  result.subVectors(rhs);
  return result;
}

Vector& Vector::operator-=(const Vector& rhs){
  this->subVectors(rhs);
  return *this;
}


Vector& Vector::operator++(){
  for(int i=0; i<this->size; i++){
    lengths[i] +=1;
  }
  return *this;
}

const Vector Vector::operator++(int){
  Vector old = *this;
  ++(*this);
  return old;
}


Vector& Vector::operator--(){}


std::istream& operator>>(std::istream& in, Vector& v){
  std::size_t size;

  in >> v.size;

  for(int i=0; i<v.size; i++){
    in >> v.lengths[i];
  }
  return in;
}
std::ostream& operator<<(std::ostream& out, Vector& v){
  out << "Size = " <<  v.size << "\n";
  for(int i=0; i<v.size; i++){
    out << "X" << i+1 << " = " << v.lengths[i] << "\n";
  }
  out << "\n";
  return out;
}

Vector::operator bool() const{
  for(int i=0; i<lengths[i]; i++){
    if(lengths[i] != 0){
      return false;
    }
  }
  return true;
}

Vector::operator double() const{
  double result=0;
  for(int i=0; i<this->size; i++){
    result += (this->lengths[i] * this->lengths[i]);
  }
  return sqrt(result);
}

const Vector Vector::operator*(const double number) const{
  Vector result = multiplyVector(*this, number);
  return result;
}

Vector& Vector::operator*=(const double number){
  *this = (multiplyVector(*this,number));
  return *this;
}

double Vector::operator*(const Vector& rhs) const{
  return dotProduct(rhs);
}
Vector& Vector::operator*=(const Vector& rhs){
  assert(this->getSize() == rhs.getSize());
  unsigned countTo = this->getSize();
  for(int i=0; i<countTo; i++){
    this->lengths[i] *= rhs.lengths[i];
  }
  return *this;
}

double Vector::operator[](const size_t index) const{
  assert(index < size && index > 0);
  return this->lengths[index];
}


bool Vector::operator>(const Vector& rhs) const{
  assert(size == rhs.size);
  for(int i=0; i<size; i++){
    if(this->lengths[i] <= rhs.lengths[i]){
      return false;
    }
  }
  return true;
}


bool Vector::operator<(const Vector& rhs)const{
  assert(size == rhs.size);
  for(int i=0; i<size; i++){
    if(this->lengths[i] >= rhs.lengths[i]){
      return false;
    }
  }
  return true;
}


bool Vector::operator>=(const Vector& rhs)const{
  assert(size == rhs.size);
  for(int i=0; i<size; i++){
    if(this->lengths[i] < rhs.lengths[i]){
      return false;
    }
  }
  return true;
}
bool Vector::operator<=(const Vector& rhs)const{
  assert(size == rhs.size);
  for(int i=0; i<size; i++){
    if(this->lengths[i] > rhs.lengths[i]){
      return false;
    }
  }
  return true;
}

bool Vector::operator==(const Vector& rhs)const{
  assert(size == rhs.size);
  for(int i=0; i<size; i++){
    if(this->lengths[i] != rhs.lengths[i]){
      return false;
    }
  }
  return true;
}

bool Vector::operator!=(const Vector& rhs)const{
  assert(size == rhs.size);
  for(int i=0; i<size; i++){
    if(this->lengths[i] == rhs.lengths[i]){
      return false;
    }
  }
  return true;
}