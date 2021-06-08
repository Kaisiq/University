#include <iostream>
#include <fstream>
#include <cstring>
#include "Army/Army.cpp"


int main(){
  std::string asd = "penis";
  Raveger a(asd);

  std::initializer_list<Unit*>ravegers = {&a,a.clone(),a.clone(),a.clone(),a.clone(),a.clone(),a.clone(),a.clone(),a.clone(),a.clone(),a.clone(),a.clone(),a.clone()};
  Army army1(ravegers);

  Ultralisk h("4ep");
  std::initializer_list<Unit*>ultralisks = {&h,h.clone(),h.clone(),h.clone(),h.clone(),};
  Army army2(ultralisks);

  if(&army1.goToWar(army2) == &army1){
    for(int i=0; i<army1.getSize(); i++){
      army1[i]->print();
    }
  }
  else{
    for(int i=0; i<army2.getSize(); i++){
      army2[i]->print();
    }
  }

  return 0;
}