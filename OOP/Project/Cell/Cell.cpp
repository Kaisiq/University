#pragma once
#include "Cell.h"
#include "../Table/Table.cpp"

Cell::Cell(const char* name_, const char* value) : name(name_){
  this->value = value;
}

void Cell::changeValue(const char* newValue){
  this->value = newValue;
}

const char* Cell::getValue() const{
  return this->value;
}

const char* Cell::getName() const {
  return this->name;
}

