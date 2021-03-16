#pragma once
#include <iostream>
using namespace std;

#include "duel.h"

void Weapon::setName(char* newName){
  name = newName;
}

char* const Weapon::getName() const{
  return name;
}

int Weapon::getPower() const{
  return power;
}

void Weapon::setPower(int newPower){
  power = newPower;
}

int Weapon::getHitsUntilBreak() const{
  return hitsUntilBreak;
}

void Weapon::setHitsUntilBreak(int newHitsUntilBreak){
  hitsUntilBreak = newHitsUntilBreak;
}


Weapon createWeapon(){
  Weapon weapon;
  char name[20];
  std::cout << "Enter weapon name: ";
  std::cin >> name;
  weapon.setName(name);
  int power;
  cout << "Enter weapon power: ";
  cin >> power;
  weapon.setPower(power);
  int breakpoints;
  cout << "Enter weapon breakpoints: ";
  cin >> breakpoints;
  weapon.setHitsUntilBreak(breakpoints);
  return weapon;
}




void Warrior::setName(char* newName){
  name = newName;
}
char* Warrior::getName() const{
  return name;
}
int Warrior::getPower() const{
  return power;
}
void Warrior::setPower(int newPower){
  power = newPower;
}
int Warrior::getHealth() const{
  return health;
}
void Warrior::setHealth(int newHealth){
  health = newHealth;
}
void Warrior::setWeapon(Weapon& newWeapon){
  weapon = newWeapon;
}
Weapon Warrior::getWeapon() const{
  return weapon;
}


Warrior createWarrior(Weapon& weapon){
  Warrior warrior;
  char name[20];
  cout << "Enter warrior name: ";
  cin >> name;
  warrior.setName(name);
  int power;
  cout << "Enter warrior power: ";
  cin >> power;
  warrior.setPower(power);
  int health;
  cout << "Enter warrior health: ";
  cin >> health;
  warrior.setHealth(health);
  warrior.setWeapon(weapon);
  return warrior;
}


void attack(Warrior& attacker, Warrior& attacked){
  int damage = attacker.getPower() + attacker.getWeapon().getPower();
  attacked.setHealth((attacked.getHealth() - damage));
  attacker.getWeapon().setHitsUntilBreak((attacker.getWeapon().getHitsUntilBreak() - 1));
}

bool isDead(Warrior& warrior){
  return warrior.getHealth() <= 0;
}



void fight(Warrior& warrior1, Warrior& warrior2) {

  while(!isDead(warrior1) && !isDead(warrior2)){
    if(warrior1.getWeapon().getHitsUntilBreak() == 0){
      warrior1.getWeapon().setPower(0);
    }
    if(warrior2.getWeapon().getHitsUntilBreak() == 0){
      warrior2.getWeapon().setPower(0);
    }
    //warrior 2 damages warrior 1
    attack(warrior2,warrior1);

    //warrior 1 damages warrior 2
    attack(warrior1,warrior2);

  }
  if(isDead(warrior2)){
    cout << "Warrior " << warrior1.getName() << " won the fight with " << warrior1.getHealth() << " remaining health!";
  }else{
    cout << "Warrior " << warrior2.getName() << " won the fight with " << warrior2.getHealth() << " remaining health!";
  }
}
