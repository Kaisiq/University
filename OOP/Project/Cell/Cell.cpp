#pragma once
#include "Cell.h"

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

#include "IntCell.cpp"
#include "DoubleCell.cpp"
#include "StringCell.cpp"
#include "FormulaCell.cpp"
#include "../Table/Table.cpp"
