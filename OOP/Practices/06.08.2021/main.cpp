#include "Formula.cpp"

int main() {
  Number a(5.3);
  Number c(12);
  Operation b('+', &a, &c);

  Formula* d = new Operation('*', &b, &c);
  d->print(std::cout);


  return 0;
}