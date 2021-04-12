#pragma once

class Garage{
private:
  std::size_t capacity;
  std::size_t used;
  std::size_t vehicleCount;
  Vehicle** vehicles;
  void removeVehicleFromArr(int);
public:
  Garage(std::size_t size);
  ~Garage();
  Garage(const Garage&);
  void insert(Vehicle& v);
  void erase(const char* registration);
  const Vehicle& at(std::size_t pos) const;
  const Vehicle& operator[](std::size_t pos) const;
  bool empty() const;
  std::size_t size() const;
  void clear();
  const Vehicle* find(const char* registration) const;
  void printGarage();
};