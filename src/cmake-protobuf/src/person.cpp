
#include "person.h"

void Person::SetPerson(const std::string &name, int age) {
  name_ = name;
  age_ = age;
}

void Person::SetBook(const std::string &bookName, float price) {
  book_.set_name(bookName);
  book_.set_price(price);
}

void Person::Print() {
  std::cout << name_
            << " is " << age_ << " years old. \n";
  std::cout << "His favorite book is " << book_.name()
            << ", and it costs " << book_.price() << "￥.\n";
}