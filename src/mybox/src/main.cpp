#include <iostream>

#include "file.h"
#include "encrypt.h"

int main() {
  // File
  const char *path = "/tmp/emptyfile";
  if (!CheckDirOrFileExist(path)) {
    std::cout << "File " << path << " is not exist.\n";
  }

  std::string msg = "hello world";
  WriteFile(path, msg);
  std::string newMsg = ReadFile(path);
  std::cout << "new message = " << newMsg << "\n";

  // Encrypt
  msg = "hello boy, your age is 18";
  std::string key = "tRdnHN*RSuScUWK~";
  std::string encryptStr = Encrypt(msg, key);
  std::cout << "encrypt string = " << encryptStr << "\n";
  newMsg = Decrypt(encryptStr, key);
  std::cout << "decrypt message = " << newMsg << "\n";
}
