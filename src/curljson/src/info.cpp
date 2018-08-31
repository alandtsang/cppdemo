#include <nlohmann/json.hpp>
#include "info.h"

using json = nlohmann::json;

void to_json(json &j, const Book &book) {
  j = {
      {"name", book.name}
  };
}

void to_json(json &j, const Person &p) {
  j = {
      {"name", p.name},
      {"age", p.age}
  };
  if (!p.favoriteBooks.empty())
    j.push_back({"books", p.favoriteBooks});
}

void from_json(const json &j, FavoriteLanguage &favor) {
  favor.name = j["name"];
  favor.languages = j["languages"].get<std::vector<std::string>>();
}

