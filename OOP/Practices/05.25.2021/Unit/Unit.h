#pragma once
class Unit
{
public:
  Unit() = default;
  Unit(int attack, int hitPoints, int armor, const std::string& name);
  Unit(const Unit& other);
  virtual ~Unit() = default;

  virtual Unit& duel(Unit& other);
  virtual void attack(Unit& other);
  void takeDamage(int damage);
  bool isAlive() const;

  void print(std::ostream& out);

  virtual Unit* clone(){
    return new Unit(*this);
  }

  int getAttackPower() const;
  int getHitPoints() const;
  int getArmor() const;
  const std::string& getName() const;

  int setAttackPower(int attack);
  int setHitPoints(int hp);
  int setArmor(int armor);
  void setName(const std::string& name);
private:
  int attackPoints;
  int hitPoints;
  int armor;
  std::string name;
};


class Zergling : public virtual Unit{
public:
  Unit* clone() const{
    return new Zergling(*this);
  }
  Zergling(std::string name);
  Zergling(const Zergling& other);
};

class Baneling : public virtual Unit{
public:
  Baneling(std::string name);
  Baneling(const Baneling& other);
  void attack(Unit &other);
  Unit* clone() const{
    return new Baneling(*this);
  }
  };

class Raveger : public virtual Unit{
private:
  int hitCounter;
public:
  Raveger(std::string& name);
  Raveger(const Raveger& other);
  virtual void attack(Unit &other) override;
  Unit* clone() const{
    return new Raveger(*this);
  }
};

class Ultralisk : public virtual Unit{
public:
  Ultralisk(std::string name);
  Ultralisk(const Ultralisk& other);
  Unit& duel(Unit &other);
  Unit* clone() const{
    return new Ultralisk(*this);
  }
};

class Marine : public virtual Unit{
public:
  Marine(std::string name);
  Marine(const Marine& other);
  Unit* clone() const{
    return new Marine(*this);
  }
};

class Marauder : public virtual Unit{
public:
  Marauder(std::string name);
  Marauder(const Marauder& other);
  void attack(Unit &other);
  Unit* clone() const{
    return new Marauder(*this);
  }
};

class Helion : public virtual Unit{
public:
  Helion(std::string name);
  Helion(const Helion& other);
  void attack(Unit &other);
  Unit* clone() const{
    return new Helion(*this);
  }
};
