#include "duel.cpp"


int main(){

  Weapon weapon1 = createWeapon();
  Weapon weapon2 = createWeapon();
  Weapon weapon3 = createWeapon();

  Warrior Human = createWarrior(weapon1);
  Warrior Alien = createWarrior(weapon3);


  fight(Human , Alien);


  return 0;
}