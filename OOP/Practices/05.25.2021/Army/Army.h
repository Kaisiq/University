#pragma once
#include "../Unit/Unit.cpp"
#include <vector>


class Army
{
private:
  std::vector<Unit*> army;
  void copy(const Army& other){
    this->army.clear();
    this->army.reserve(other.army.size());
    for(int i=0; i<other.army.size(); i++){
      this->army.push_back(other.army[i]->clone());
    }
  }
public:
  Army();
  Army(std::initializer_list<Unit*>);
  Army(const Army&);
  Army(Army&&);
  Army& operator=(const Army&);
  Army& operator=(Army&&);
  ~Army();

  const Unit*const& operator[](size_t index) const;
  Unit*& operator[](size_t index);

  void pushBack(Unit*);

  Army& goToWar(Army&);

  const size_t getSize() const;
  const size_t getCapacity() const;
};