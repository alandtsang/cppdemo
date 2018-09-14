#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person {
 public:
  Person(std::string name, int age);
  ~Person() {}

  const char *GetName() { return name_.c_str(); }
  int GetAge() { return age_; }

 private:
  std::string name_;
  int age_;
};

#endif // PERSON_H_
