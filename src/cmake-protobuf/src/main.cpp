#include <iostream>
#include "person.h"

int main() {
  Person p;
  p.SetPerson("Alan", 18);
  p.SetBook("Effective C++", 51.8);
  p.Print();
  return 0;
}
