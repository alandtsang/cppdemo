#ifndef HTTPD_INFO_H_
#define HTTPD_INFO_H_

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct Book {
  std::string name;
};

struct FavoriteLanguage {
  std::string name;
  std::vector<std::string> languages;
};

struct Person {
  std::string name;
  int age;
  std::vector<Book> favoriteBooks;
};

void to_json(json &j, const Book &book);
void to_json(json &j, const Person &p);
void from_json(const json &j, FavoriteLanguage &favor);

#endif // HTTPD_INFO_H_
