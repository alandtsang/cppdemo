#include <iostream>

#include "file.h"

int main() {
  const char *path = "/tmp/emptyfile";

  if (!CheckDirOrFileExist(path)) {
      std::cout << "File " << path << " is not exist.\n"; 
  }

  std::string msg = "hello world";
  WriteFile(path, msg);
  std::string newMsg = ReadFile(path);
  std::cout << "new message = " << newMsg << "\n";
}
