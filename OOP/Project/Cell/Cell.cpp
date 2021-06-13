#pragma once

Cell::Cell(const char* name_) : name(name_){}

const char* Cell::getName() const {
  return this->name;
}

Cell::~Cell(){
  delete[] this->name;
}

std::ostream& operator<<(std::ostream& out, const Cell* cell){
  out << cell->getValue();
  return out;
}


