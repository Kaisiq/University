#pragma once
#include "Unit.h"

Unit::Unit(int attack, int hitPoints, int armor, const std::string& name){
  this->attackPoints = attack;
  this->hitPoints = hitPoints;
  this->armor = armor;
  this->setName(name);
}
Unit::Unit(const Unit& other){
  this->attackPoints = other.attackPoints;
  this->hitPoints = other.hitPoints;
  this->armor = other.armor;
  this->setName(other.name);
}

Unit& Unit::duel(Unit& other){
  while(this->isAlive() && other.isAlive()) {
    this->attack(other);
    std::cout << getName() << " attacked " << other.getName() << " - " << other.getName() << " HP: " << other.getHitPoints() << std::endl;
    if(!other.isAlive()){
      std::cout << this->getName() << " wins!\n";
      return *this;
    }
    other.attack(*this);
    std::cout << other.getName() << " attacked " << getName() << " - " << getName() << " HP: " << getHitPoints() << std::endl;
    if(!this->isAlive()){
      std::cout << other.getName() << " wins!\n";
      return other;
    }
  }
  if(!other.isAlive() && !this->isAlive()){
    std::cout << "Both died!\n";
    return *this;
  }
  if(!other.isAlive()){
    std::cout << this->getName() << " wins!\n";
    return *this;
  }
  if(!this->isAlive()){
    std::cout << other.getName() << " wins!\n";
    return other;
  }
}
void Unit::attack(Unit& other){
  other.takeDamage(this->attackPoints);
}
void Unit::takeDamage(int damage){
  this->hitPoints = this->hitPoints - (damage - this->armor);
}
bool Unit::isAlive() const{
  return this->hitPoints >= 1;
}

void Unit::print(std::ostream& out = std::cout){
  out << "Name: " << this->getName() << "  HP: " << this->getHitPoints() << " Attack: " << this->getAttackPower() << " Armor: " << this->getArmor() << std::endl;
}

int Unit::getAttackPower() const{
  return this->attackPoints;
}
int Unit::getHitPoints() const{
  return this->hitPoints;
}
int Unit::getArmor() const{
  return this->armor;
}
const std::string& Unit::getName() const{
  return this->name;
}

int Unit::setAttackPower(int attack){
  this->attackPoints = attack;
}
int Unit::setHitPoints(int hp){
  this->hitPoints = hp;
}
int Unit::setArmor(int newArmor){
  this->armor = newArmor;
}
void Unit::setName(const std::string& newName){
  this->name = newName;
}

Zergling::Zergling(std::string name){
  this->setAttackPower(10);
  this->setHitPoints(30);
  this->setArmor(1);
  this->setName(name);
}

Baneling::Baneling(std::string name){
  this->setAttackPower(15);
  this->setHitPoints(30);
  this->setArmor(1);
  this->setName(name);
}

void Baneling::attack(Unit &other) {
  other.takeDamage(this->getAttackPower() + this->getHitPoints());
  this->setHitPoints(0);
}

Raveger::Raveger(std::string& name){
  this->setAttackPower(20);
  this->setHitPoints(100);
  this->setArmor(3);
  this->setName(name);
  this->hitCounter = 0;
}

Raveger::Raveger(const Raveger& other){
  this->setName(other.getName());
  this->hitCounter = other.hitCounter;
  this->setAttackPower(other.getAttackPower());
  this->setArmor(other.getArmor());
  this->setHitPoints(other.getHitPoints());
}

void Raveger::attack(Unit &other) {
  hitCounter++;
  if(hitCounter%3 == 0){
    hitCounter = 0;
    other.takeDamage(2* (this->getAttackPower()));
  }
  else
  other.takeDamage(this->getAttackPower());
}

Ultralisk::Ultralisk(std::string name){
  this->setAttackPower(35);
  this->setHitPoints(500);
  this->setArmor(5);
  this->setName(name);
}

Ultralisk::Ultralisk(const Ultralisk& other){
  this->setName(other.getName());
  this->setAttackPower(35);
  this->setHitPoints(500);
  this->setArmor(5);
}


Unit& Ultralisk::duel(Unit &other) {
  while(this->isAlive() && other.isAlive()) {
    this->attack(other);
    std::cout << getName() << " attacked " << other.getName() << " - " << other.getHitPoints() << std::endl;
    if(!other.isAlive()){
      std::cout << this->getName() << " wins!\n";
      return *this;
    }
    other.attack(*this);
    std::cout << other.getName() << " attacked " << getName() << " - " << getHitPoints() << std::endl;
    other.takeDamage(this->getArmor());
    std::cout << getName() << " attacked " << other.getName() << " - " << other.getHitPoints() << std::endl;
    if(!this->isAlive() && other.isAlive()){
      std::cout << "Both died!\n";
      return *this;
    }
    if(!other.isAlive()){
      std::cout << this->getName() << " wins!\n";
      return *this;
    }
    if(!this->isAlive()){
      std::cout << other.getName() << " wins!\n";
      return other;
    }
  }
}

Marine::Marine(std::string name){
  this->setAttackPower(10);
  this->setHitPoints(25);
  this->setArmor(2);
  this->setName(name);
}

Marauder::Marauder(std::string name){
  this->setAttackPower(10);
  this->setHitPoints(25);
  this->setArmor(2);
  this->setName(name);
}

void Marauder::attack(Unit &other) {
  other.takeDamage(this->getAttackPower());
  this->setHitPoints(this->getHitPoints() + 5);
}

Helion::Helion(std::string name){
  this->setAttackPower(35);
  this->setHitPoints(300);
  this->setArmor(7);
  this->setName(name);
}

void Helion::attack(Unit &other) {
  other.takeDamage(this->getAttackPower());
  other.setArmor(other.getArmor() - 1);
}
