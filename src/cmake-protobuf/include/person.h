#ifndef CMAKE_PROTOBUF_PERSON_H_
#define CMAKE_PROTOBUF_PERSON_H_

#include <string>
#include "test.pb.h"

class Person {
 public:
  Person() {}
  ~Person() {}

  void SetPerson(const std::string &name, int age);
  void SetBook(const std::string &bookName, float price);
  void Print();

 private:
  std::string name_;
  int age_;
  test::Book book_;
};

#endif // CMAKE_PROTOBUF_PERSON_H_
