#include <string>
#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

bool CheckDirOrFileExist(const char *path) {
  struct stat st;
  if (stat(path, &st) == -1)
    return false;
  return true;
}

bool WriteFile(const char *path, const std::string &msg) {
  std::ofstream file(path, std::ofstream::out);
  if (file.is_open()) {
    file << msg;
    file.close();
    return true;
  }
  return false;
}

std::string ReadFile(const char *path) {
  std::string line;
  std::ifstream file(path);

  if (file.is_open()) {
    getline(file, line);
    file.close();
  }
  return line;
}
