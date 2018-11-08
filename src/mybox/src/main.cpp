#include <iostream>

#include "file.h"
#include "encrypt.h"
#include "utils.h"
#include "base64.h"

int main() {
  // File
  const char *path = "/tmp/emptyfile";
  if (!CheckDirOrFileExist(path)) {
    std::cout << "File " << path << " is not exist.\n";
  }

  std::string msg = "hello world";
  WriteFile(path, msg);
  std::string newMsg = ReadFile(path);
  std::cout << "new message = " << newMsg << "\n\n";

  // Encrypt
  msg = "hello boy, your age is 18";
  std::string key = "tRdnHN*RSuScUWK~";
  std::string encryptStr = Encrypt(msg, key);
  std::cout << "encrypt string = " << encryptStr << "\n";
  newMsg = Decrypt(encryptStr, key);
  std::cout << "decrypt message = " << newMsg << "\n\n";

  // Random
  int num = GetRandomNum(20);
  std::cout << "random [0, 20) = " << num << "\n";
  num = GetRandomNum(20, 5);
  std::cout << "random [5, 20) = " << num << "\n\n";

  // Base64
  std::string s = "any + old & data";
  msg = base64_encode(s.c_str(), s.length());
  std::cout << msg << "\n";
  newMsg = base64_decode(msg);
  std::cout << newMsg << "\n\n";
}
