#include <string>

std::string Encrypt(std::string msg, const std::string &key) {
  if (!key.size())
    return msg;

  for (std::string::size_type i = 0; i < msg.size(); i++)
    msg[i] ^= key[i % key.size()];
  return msg;
}

std::string Decrypt(const std::string &msg, const std::string &key) {
  return Encrypt(msg, key);
}
