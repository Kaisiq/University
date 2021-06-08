#include "Formula.h"


std::ostream& Number::print(std::ostream& out){
  out << this->value << "\n";
  return out;
}

Number* Number::clone(){
  return new Number(this->value);
}
float Number::evaluate(){
  return this->value;
}




float Operation::evaluate(){
  if(this->m_op == '/'){
    return m_lhs->evaluate() / m_rhs->evaluate();
  }
  else if(this->m_op == '*'){
    return m_lhs->evaluate() * m_rhs->evaluate();
  }
  else if(this->m_op == '+'){
    return m_lhs->evaluate() + m_rhs->evaluate();
  }
  else if(this->m_op == '-'){
    return m_lhs->evaluate() - m_rhs->evaluate();
  }
  else throw std::invalid_argument("Invalid operation\n");
}

std::ostream& Operation::print(std::ostream& out){
  out << "( " << this->m_lhs->evaluate() << ") " << this->m_op << " (" << this->m_rhs->evaluate() << ") = " << this->evaluate() << "\n";
  return out;
}
Operation* Operation::clone(){
  return new Operation(*this);
}