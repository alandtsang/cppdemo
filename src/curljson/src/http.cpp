#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "info.h"

using json = nlohmann::json;

static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  auto j = json::parse(std::string((char *) ptr));
  std::cout << j << "\n";
  FavoriteLanguage *favor = (FavoriteLanguage *) userp;
  *favor = j;
  return realsize;
}

int GetFavoriteBooks() {
  CURL *curl;
  CURLcode code = CURLE_FAILED_INIT;

  std::string url = "127.0.0.1:9999/favorbooks";
  std::vector<Book> books;
  Book book1{"TCP/IP Illustrated, Volume 1"};
  Book book2{"Advanced Programming in the UNIX Environment"};
  books.push_back(book1);
  books.push_back(book2);
  Person p{"Aland", 18, books};

  json j = p;
  std::string dump = j.dump();
  std::cout << dump << "\n";
  FavoriteLanguage favor;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L); // POST
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, dump.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &favor);

    code = curl_easy_perform(curl);
    if (code != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(code));
      return code;
    } else {
      std::cout << "Name:" << favor.name << "\n";
      std::cout << "Languages:" << "\n";
      for (auto &l : favor.languages)
        std::cout << "  " << l << "\n";
    }
    curl_easy_cleanup(curl);
  }
  return code;
}

int main() {
  GetFavoriteBooks();
  return 0;
}
