#include <iostream>
class Formula
{
public:
  Formula() = default;
  virtual ~Formula() = default;
  Formula(const Formula&) = delete;
  Formula& operator=(const Formula&) = delete;

  virtual float evaluate() = 0;
  virtual std::ostream& print(std::ostream& out)=0;
  virtual Formula* clone()=0;
};


class Number: public Formula
{
public:
  Number(float value) {
    this->value = value;
  }
  std::ostream& print(std::ostream& out) override;
  Number* clone() override;
  float evaluate() override;

private:
  float value;
};


class Operation : public Formula
{
public:
  ~Operation() override{
    delete[] this->m_rhs;
    delete[] this->m_lhs;
  }

  Operation(char op, Formula* lhs, Formula* rhs) {
    this->m_op = op;
    m_lhs = lhs->clone();
    m_rhs = rhs->clone();
  }
  Operation(const Operation& rhs) : m_op(rhs.m_op), m_lhs(rhs.m_lhs), m_rhs(rhs.m_rhs){}
  Operation& operator= (const Operation& rhs){
    if(this != &rhs){
      this->m_op = rhs.m_op;
      this->m_rhs = rhs.m_rhs;
      this->m_lhs = rhs.m_lhs;
    }
    return *this;
  }
  float evaluate() override;
  std::ostream& print(std::ostream& out) override;
  Operation* clone() override;

private:
  char m_op;
  Formula* m_lhs;
  Formula* m_rhs;
};