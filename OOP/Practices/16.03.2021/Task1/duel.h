
#ifndef UNIVERSITY_DUEL_H
#define UNIVERSITY_DUEL_H

class Weapon{
  char* name = new char[20];
  int power;
  int hitsUntilBreak;



public:
  void setName(char*);
  char* const getName() const;
  int getPower() const;
  void setPower(int);
  int getHitsUntilBreak() const;
  void setHitsUntilBreak(int);


};

class Warrior{
  char* name = new char[20];
  int power;
  int health;
  Weapon weapon;



public:
  void setName(char*);
  char* getName() const;
  int getPower() const;
  void setPower(int);
  int getHealth() const;
  void setHealth(int);
  void setWeapon(Weapon& newWeapon);
  Weapon getWeapon() const;


};



#endif // UNIVERSITY_DUEL_H
