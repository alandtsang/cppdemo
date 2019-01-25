#include <sstream>
#include "split.h"

/**
 * 分割字符串
 * @param s 为字符串
 * @param delimiter 为分割符
 * @return 字符串的数组
 */
std::vector<std::string> Split(const std::string &s, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;

  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}
