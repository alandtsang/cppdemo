#ifndef MYBOX_INCLUDE_ENCRYPT_H_
#define MYBOX_INCLUDE_ENCRYPT_H_

#include <string>

std::string Encrypt(std::string msg, const std::string &key);
std::string Decrypt(const std::string &msg, const std::string &key);

#endif // MYBOX_INCLUDE_ENCRYPT_H_
